%{
	#include "lex.yy.c"
	#include <stdio.h>
	#include <stdlib.h>
	
	typedef struct node
	{
		struct node *left;
		struct node *right;
		struct node *another;
		char *token;
	} node;

	node *createOp( char *token, node *another, node *left, node *right);
	
	
	node *createOp(char *token, node *another, node *left, node *right)
	{
		//printf("Making NODE");
		/* malloc the node */
		node *newnode = (node *)malloc(sizeof(node));
		char *newstr = (char *)malloc(strlen(token)+1);
		strcpy(newstr, token);
		newnode->left = left;
		newnode->right = right;
		newnode->another = another;
		newnode->token = newstr;
		return(newnode);
	}
	
	
	void printtree(node *tree)
	{
		//printf("Printing tree");

		if (tree->left || tree->right || tree->another)
			printf("(");

		printf(" %s ", tree->token);

		if (tree->left)
			printtree(tree->left);
		if (tree->right)
			printtree(tree->right);
		if (tree->another)
			printtree(tree->another);
		
		if (tree->left || tree->right || tree->another)
			printf(")");
	}
	
%}



%token T_EndOfFile T_Return T_Number T_True T_False T_ID T_Print T_Cln T_NL T_EQL T_NEQ T_EQ T_GT T_LT T_EGT T_ELT T_Or T_And T_Not T_In ID ND DD T_String T_If T_Elif T_While T_Else T_Import T_Break T_Pass T_MN T_PL T_DV T_ML T_OP T_CP T_OB T_CB T_Def T_Comma T_List 

%start StartDebugger

%%
StartDebugger: StartParse ;

constant: T_Number | T_String ; 

term: id | constant | list_index ;

id: T_ID{	printf("\n## Checking in Symbol Table : %s\n", Inp_txt);

		if(check_table(Inp_txt)==0){
			printf("   >> Inserting into Symbol Table : %s\n", Inp_txt);
			into_table(Inp_txt,0);			
		}
		
		else{
			printf("   \"%s\" already in Symbol Table\n");
		}				
	};

list_index: id T_OB constant T_CB ; 

StartParse: T_NL StartParse | finalStatements T_NL StartParse | finalStatements ;

basic_stmt: pass_stmt {$$=$1;}
           | break_stmt {$$=$1;}
           | import_stmt {$$=$1;}
           | assign_stmt {$$=$1;}
           | arith_exp {$$=$1;}
           | bool_exp {$$=$1;}
           | print_stmt {$$=$1;}
           | return_stmt {$$=$1;}
           ;
           
arith_exp: term {$$=$1;}
          | arith_exp  T_PL  arith_exp {$$ = createOp("+", 2, $1, $3);}
          | arith_exp  T_MN  arith_exp {$$ = createOp("-", 2, $1, $3);}
          | arith_exp  T_ML  arith_exp {$$ = createOp("*", 2, $1, $3);}
          | arith_exp  T_DV  arith_exp {$$ = createOp("/", 2, $1, $3);}
          //| T_MN arith_exp {$$ = createOp("-", 1, $2);}
          | T_OP arith_exp T_CP {$$ = $2;} 
          ;

ROP: T_GT | T_LT | T_EGT | T_ELT ;

bool_exp: bool_term | bool_term T_Or bool_term  
		| bool_term T_And bool_term
		| arith_exp T_LT arith_exp
		| arith_exp T_GT arith_exp  
		| arith_exp T_ELT arith_exp
		| arith_exp T_EGT arith_exp
		| arith_exp T_In id ;
		
bool_term: bool_factor | arith_exp T_EQ arith_exp | T_True | T_False ;

bool_factor: T_Not bool_factor | T_OP bool_exp T_CP ;

import_stmt: T_Import id ;

assign_stmt: id T_EQL arith_exp | id T_EQL bool_exp | id T_EQL func_call | id T_EQL T_OB T_CB | ;

pass_stmt: T_Pass ;

break_stmt: T_Break ;

return_stmt: T_Return ;

print_stmt: T_Print T_OP constant T_CP ;

finalStatements: basic_stmt | cmpd_stmt | func_def | func_call | error T_NL ;

cmpd_stmt: if_stmt | while_stmt ;

if_stmt:  T_If bool_exp T_Cln start_suite 
	| T_If bool_exp T_Cln start_suite elif_stmts 
	| T_If bool_exp T_Cln suite  
	;

elif_stmts: T_Elif bool_exp T_Cln start_suite | T_Elif bool_exp T_Cln start_suite elif_stmts | T_Elif bool_exp T_Cln suite | else_stmt ;

else_stmt: T_Else T_Cln start_suite | T_Else T_Cln suite ;

while_stmt: T_While bool_exp T_Cln start_suite | T_While bool_exp T_Cln suite ;

start_suite: finalStatements | T_NL ID finalStatements suite | ;

suite: T_NL ID finalStatements suite | T_NL end_suite | end_suite;

end_suite: finalStatements | ;

args: id args_list | ;
 
args_list: T_Comma id args_list |;

call_list: T_Comma term call_list | ;

call_args: term call_list | ;

func_def: T_Def id T_OP args T_CP T_Cln start_suite ;

func_call: id T_OP call_args T_CP ;

%%

void yyerror(char *msg){
	//yyerrok; 
	yyclearin;
	printf("\n## ERROR @ line %d \n",yylineno);
	//printf("\n!!! Syntax Error at Line %d\n",  yylineno);
	//exit(0);
}

int main(){
	printf("~~~ PROCESSING....\n");
	yyparse();
	Table();
	return 0;
}






