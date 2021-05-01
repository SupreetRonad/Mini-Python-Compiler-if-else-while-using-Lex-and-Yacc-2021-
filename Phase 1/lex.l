%{

	int yyparse(void);
	int yylex(void);
	void yyerror(char *);
	int scope[100]={0},stop=1,sid=1, line_no=1;
	char *Inp_txt;
	#include<string.h>
	#include<stdlib.h>
	#include<stdio.h>
	#include"symbolTable.h"
	#include"y.tab.h"	

	void debug(char *t, char *s);		

%}

%option yylineno
whitespace [ ]
Multiline_comment \'\'\'.+\'\'\'

%%

\/\*([^*]|\*[^/])*\*\/			;
\/\/[^\n]*				;
"import" 	{debug("IMPT",yytext); return T_Import;}
"print"  	{debug("Print",yytext); return T_Print;}
"pass" 	{debug("Pass",yytext); return T_Pass;}
"if" 		{debug("If",yytext); return T_If;}
"in" 		{debug("In",yytext); return T_In;}
"while" 	{debug("While",yytext); return T_While;}
"break" 	{debug("Break",yytext); return T_Break;}
"and" 		{debug("And",yytext); return T_And;}
"or" 		{debug("Or",yytext); return T_Or;}
"not" 		{debug("Not",yytext); return T_Not;}
"elif" 	{debug("Elif",yytext); return T_Elif;}
"else" 	{debug("Else",yytext); return T_Else;}
"def" 		{debug("Def",yytext); return T_Def;}
"return" 	{debug("Return",yytext); return T_Return;}
":" 		{debug("Cln",yytext); return T_Cln;}
">" 		{debug("GT",yytext); return T_GT;}
"<" 		{debug("LT",yytext); return T_LT;}
">=" 		{debug("EGT",yytext); return T_EGT;}
"<=" 		{debug("ELT",yytext); return T_ELT;}
"==" 		{debug("EQ",yytext); return T_EQ;}
"!=" 		{debug("NEQ",yytext); return T_NEQ;}
"True" 	{debug("True",yytext); return T_True;}
"False" 	{debug("False",yytext); return T_False;}
"+" 		{debug("PL",yytext); return T_PL;}
"-" 		{debug("MN",yytext); return T_MN;}
"*" 		{debug("ML",yytext); return T_ML;}
"/" 		{debug("DV",yytext); return T_DV;}
"(" 		{debug("OP",yytext); return T_OP;}
")" 		{debug("CP",yytext); return T_CP;}
"[" 		{debug("OB",yytext); return T_OB;}
"]" 		{debug("CB",yytext); return T_CB;}
"," 		{debug("Comma",yytext); return T_Comma;}
"=" 		{debug("EQL",yytext); return T_EQL;}
"list" 	{debug("List",yytext); return T_List;}

[0-9]+ 	{into_table(yytext,1);Inp_txt = strdup(yytext); debug(Inp_txt,yytext); return T_Number;}

[_a-zA-Z][_a-zA-Z0-9]* {Inp_txt = strdup(yytext); debug(Inp_txt,yytext); return T_ID;}

\"([^\"\n])*\" {into_table(yytext,1);Inp_txt = strdup(yytext); debug(Inp_txt,yytext); return T_String;}
\'([^\'\n])*\' {into_table(yytext,1);Inp_txt = strdup(yytext); debug(Inp_txt,yytext); return T_String;}

"#"([a-z]|[0-9]|[A-Z]|" ")* {}

"\t"		{debug("INDENT",yytext); return ID;}
{Multiline_comment} {}
{whitespace} 	{} 

"\n" 		{line_no++; debug("NL",yytext); return T_NL;}


%%


void debug(char *t, char *s){
   	FILE *fptr;
   	fptr = fopen("Tokens.txt", "a");
   	if(fptr == NULL){
	      	printf("Error!");
	      	exit(1);
   	}

   	fprintf(fptr,"%s : %s\n", t, s);
   	fclose(fptr);
}
