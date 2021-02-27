%token T_EndOfFile T_Return T_Number T_True T_False T_ID T_Print T_Cln T_NL T_EQL T_NEQ T_EQ T_GT T_LT T_EGT T_ELT T_Or T_And T_Not T_In ID ND DD T_String T_If T_Elif T_While T_Else T_Import T_Break T_Pass T_MN T_PL T_DV T_ML T_OP T_CP T_OB T_CB T_Def T_Comma T_List T_MOD

%start start
//Grammar Rules
%%

StartDebugger : {init();} StartParse T_EndOfFile {printf("\nValid Python Syntax\n");  printAST($2); codeGenOp($2); printQuads(); printSTable(); freeAll(); exit(0);} ;

constant : T_Number {insertRecord("Constant", $<text>1, @1.first_line, currentScope); $$ = createID_Const("Constant", $<text>1, currentScope);}
         | T_String {insertRecord("Constant", $<text>1, @1.first_line, currentScope); $$ = createID_Const("Constant", $<text>1, currentScope);};

term : T_ID {modifyRecordID("Identifier", $<text>1, @1.first_line, currentScope); $$ = createID_Const("Identifier", $<text>1, currentScope);} 
     | constant {$$ = $1;} 
     | list_index {$$ = $1;};


list_index : T_ID T_OB constant T_CB {checkList($<text>1, @1.first_line, currentScope); $$ = createOp("ListIndex", 2, createID_Const("ListTypeID", $<text>1, currentScope), $3);};

StartParse : T_NL StartParse {$$=$2;}| finalStatements T_NL {resetDepth();} StartParse {$$ = createOp("NewLine", 2, $1, $4);}| finalStatements T_NL {$$=$1;};

basic_stmt : pass_stmt {$$=$1;}
           | break_stmt {$$=$1;}
           | import_stmt {$$=$1;}
           | assign_stmt {$$=$1;}
           | arith_exp {$$=$1;}
           | bool_exp {$$=$1;}
           | print_stmt {$$=$1;}
           | return_stmt {$$=$1;};

arith_exp : term {$$=$1;}
          | arith_exp  T_PL  arith_exp {$$ = createOp("+", 2, $1, $3);}
          | arith_exp  T_MN  arith_exp {$$ = createOp("-", 2, $1, $3);}
          | arith_exp  T_ML  arith_exp {$$ = createOp("*", 2, $1, $3);}
          | arith_exp  T_DV  arith_exp {$$ = createOp("/", 2, $1, $3);}
          | arith_exp  T_MOD arith_exp {$$ = createOp("%", 2, $1, $3);}
          | T_MN arith_exp {$$ = createOp("-", 1, $2);}
          | T_OP arith_exp T_CP {$$ = $2;} ;
		    

bool_exp : bool_term T_Or bool_term {$$ = createOp("or", 2, $1, $3);}
         | arith_exp T_LT arith_exp {$$ = createOp("<", 2, $1, $3);}
         | bool_term T_And bool_term {$$ = createOp("and", 2, $1, $3);}
         | arith_exp T_GT arith_exp {$$ = createOp(">", 2, $1, $3);}
         | arith_exp T_ELT arith_exp {$$ = createOp("<=", 2, $1, $3);}
         | arith_exp T_EGT arith_exp {$$ = createOp(">=", 2, $1, $3);}
         | arith_exp T_In T_ID {checkList($<text>3, @3.first_line, currentScope); $$ = createOp("in", 2, $1, createID_Const("Constant", $<text>3, currentScope));}
         | bool_term {$$=$1;}; 

bool_term : bool_factor {$$ = $1;}
          | arith_exp T_EQ arith_exp {$$ = createOp("==", 2, $1, $3);}
          | T_True {insertRecord("Constant", "True", @1.first_line, currentScope); $$ = createID_Const("Constant", "True", currentScope);}
          | T_False {insertRecord("Constant", "False", @1.first_line, currentScope); $$ = createID_Const("Constant", "False", currentScope);}; 
          
bool_factor : T_Not bool_factor {$$ = createOp("!", 1, $2);}
            | T_OP bool_exp T_CP {$$ = $2;}; 

import_stmt : T_Import T_ID {insertRecord("PackageName", $<text>2, @2.first_line, currentScope); $$ = createOp("import", 1, createID_Const("PackageName", $<text>2, currentScope));};
pass_stmt : T_Pass {$$ = createOp("pass", 0);};
break_stmt : T_Break {$$ = createOp("break", 0);};
return_stmt : T_Return {$$ = createOp("return", 0);};

assign_stmt : T_ID T_EQL arith_exp {insertRecord("Identifier", $<text>1, @1.first_line, currentScope); $$ = createOp("=", 2, createID_Const("Identifier", $<text>1, currentScope), $3);}  
            | T_ID T_EQL bool_exp {insertRecord("Identifier", $<text>1, @1.first_line, currentScope);$$ = createOp("=", 2, createID_Const("Identifier", $<text>1, currentScope), $3);}   
            | T_ID  T_EQL func_call {insertRecord("Identifier", $<text>1, @1.first_line, currentScope); $$ = createOp("=", 2, createID_Const("Identifier", $<text>1, currentScope), $3);} 
            | T_ID T_EQL T_OB T_CB {insertRecord("ListTypeID", $<text>1, @1.first_line, currentScope); $$ = createID_Const("ListTypeID", $<text>1, currentScope);} ;
	      
print_stmt : T_Print T_OP term T_CP {$$ = createOp("Print", 1, $3);};

finalStatements : basic_stmt {$$ = $1;}
                | cmpd_stmt {$$ = $1;}
                | func_def {$$ = $1;}
                | func_call {$$ = $1;}
                | error T_NL {yyerrok; yyclearin; $$=createOp("SyntaxError", 0);};

cmpd_stmt : if_stmt {$$ = $1;}
          | while_stmt {$$ = $1;};


if_stmt : T_If bool_exp T_Cln start_suite {$$ = createOp("If", 2, $2, $4);}
        | T_If bool_exp T_Cln start_suite elif_stmts {$$ = createOp("If", 3, $2, $4, $5);};

elif_stmts : else_stmt {$$= $1;}
           | T_Elif bool_exp T_Cln start_suite elif_stmts {$$= createOp("Elif", 3, $2, $4, $5);};

else_stmt : T_Else T_Cln start_suite {$$ = createOp("Else", 1, $3);};

while_stmt : T_While bool_exp T_Cln start_suite {$$ = createOp("While", 2, $2, $4);}; 

start_suite : basic_stmt {$$ = $1;}
            | T_NL ID {initNewTable($<depth>2); updateCScope($<depth>2);} finalStatements suite {$$ = createOp("BeginBlock", 2, $4, $5);};

suite : T_NL ND finalStatements suite {$$ = createOp("Next", 2, $3, $4);}
      | T_NL end_suite {$$ = $2;};

end_suite : DD {updateCScope($<depth>1);} finalStatements {$$ = createOp("EndBlock", 1, $3);} 
          | DD {updateCScope($<depth>1);} {$$ = createOp("EndBlock", 0);}
          | {$$ = createOp("EndBlock", 0); resetDepth();};

args : T_ID {addToList($<text>1, 1);} args_list {$$ = createOp(argsList, 0); clearArgsList();} 
     | {$$ = createOp("Void", 0);};

args_list : T_Comma T_ID {addToList($<text>2, 0);} args_list | ;


call_list : T_Comma term {addToList($<text>1, 0);} call_list | ;

call_args : T_ID {addToList($<text>1, 1);} call_list {$$ = createOp(argsList, 0); clearArgsList();}
					| T_Number {addToList($<text>1, 1);} call_list {$$ = createOp(argsList, 0); clearArgsList();}
					| T_String {addToList($<text>1, 1);} call_list {$$ = createOp(argsList, 0); clearArgsList();}	
					| {$$ = createOp("Void", 0);};

func_def : T_Def T_ID {insertRecord("Func_Name", $<text>2, @2.first_line, currentScope);} T_OP args T_CP T_Cln start_suite {$$ = createOp("Func_Name", 3, createID_Const("Func_Name", $<text>2, currentScope), $5, $8);};

func_call : T_ID T_OP call_args T_CP {$$ = createOp("Func_Call", 2, createID_Const("Func_Name", $<text>1, currentScope), $3);};

 
%%

