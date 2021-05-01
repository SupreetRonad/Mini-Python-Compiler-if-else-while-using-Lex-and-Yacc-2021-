#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "par1.y"
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
		/*printf("Making NODE");*/
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
		/*printf("Printing tree");*/

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
	
#line 57 "y.tab.c"
#define T_EndOfFile 257
#define T_Return 258
#define T_Number 259
#define T_True 260
#define T_False 261
#define T_ID 262
#define T_Print 263
#define T_Cln 264
#define T_NL 265
#define T_EQL 266
#define T_NEQ 267
#define T_EQ 268
#define T_GT 269
#define T_LT 270
#define T_EGT 271
#define T_ELT 272
#define T_Or 273
#define T_And 274
#define T_Not 275
#define T_In 276
#define ID 277
#define ND 278
#define DD 279
#define T_String 280
#define T_If 281
#define T_Elif 282
#define T_While 283
#define T_Else 284
#define T_Import 285
#define T_Break 286
#define T_Pass 287
#define T_MN 288
#define T_PL 289
#define T_DV 290
#define T_ML 291
#define T_OP 292
#define T_CP 293
#define T_OB 294
#define T_CB 295
#define T_Def 296
#define T_Comma 297
#define T_List 298
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    2,    2,    3,    3,    3,    4,    5,    1,    1,
    1,    7,    7,    7,    7,    7,    7,    7,    7,   12,
   12,   12,   12,   12,   12,   16,   16,   16,   16,   13,
   13,   13,   13,   13,   13,   13,   13,   17,   17,   17,
   17,   18,   18,   10,   11,   11,   11,   11,   11,    8,
    9,   15,   14,    6,    6,    6,    6,    6,   20,   20,
   22,   22,   22,   25,   25,   25,   25,   27,   27,   23,
   23,   24,   24,   24,   26,   26,   26,   28,   28,   29,
   29,   30,   30,   31,   31,   32,   32,   21,   19,
};
short yylen[] = {                                         2,
    1,    1,    1,    1,    1,    1,    1,    4,    2,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    1,    3,    1,
    1,    2,    3,    2,    3,    3,    3,    4,    0,    1,
    1,    1,    4,    1,    1,    1,    1,    2,    1,    1,
    4,    5,    4,    4,    5,    4,    1,    3,    3,    4,
    4,    1,    4,    0,    4,    2,    1,    1,    0,    2,
    0,    3,    0,    3,    0,    2,    0,    7,    4,
};
short yydefred[] = {                                      0,
    0,   52,    2,   40,   41,    7,    0,    0,    0,    3,
    0,    0,    0,   51,   50,    0,    0,    0,    1,    5,
   20,    0,    6,    0,   54,   12,   13,   14,   15,    0,
   17,   18,   19,    0,   38,   57,   55,   56,   59,   60,
   58,    0,    9,    0,   42,    0,    0,    0,    0,   44,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,   43,    0,    0,    0,    0,   46,   47,
    0,    0,    0,   10,    0,    0,    0,    0,    0,    0,
   37,    0,    0,    0,    0,    0,   31,   32,   53,    0,
   72,    0,   63,   77,   70,   71,    0,    0,   48,    0,
   86,   89,    8,    0,    0,   78,   76,    0,    0,   62,
   67,    0,   80,    0,    0,    0,    0,    0,    0,    0,
   84,    0,   73,    0,   68,   69,   82,    0,   72,   88,
    0,    0,   66,    0,    0,   65,    0,   75,   73,
};
short yydgoto[] = {                                      18,
   19,   20,   21,   46,   23,  116,   25,   26,   27,   28,
   29,   30,   31,   32,   33,    0,   34,   35,   36,   37,
   38,   39,   40,  102,  120,  103,  121,  104,  108,  123,
  111,   82,
};
short yysindex[] = {                                    -91,
 -252,    0,    0,    0,    0,    0, -274,  -91, -264,    0,
  626,  626, -239,    0,    0,  626, -239,    0,    0,    0,
    0, -262,    0, -236,    0,    0,    0,    0,    0,  830,
    0,    0,    0, -223,    0,    0,    0,    0,    0,    0,
    0, -247,    0,  626,    0, -260,  830, -216, -210,    0,
  821, -229, -251,  -43, -253, -247,  -91, -254, -254, -254,
 -254, -254, -239, -254, -254, -254, -254,  626,  626, -218,
  -52,  -52,    0,    0, -239, -219, -257,  830,    0,    0,
 -217, -214, -212,    0, -254, -222, -222, -222, -222, -222,
    0, -222, -222, -222, -222, -244,    0,    0,    0,  636,
    0, -242,    0,    0,    0,    0, -213, -206,    0, -253,
    0,    0,    0, -137,  792,    0,    0,  626, -183,    0,
    0, -239,    0, -176, -217,  675, -171,  -52, -213,  714,
    0,  753,    0,  -52,    0,    0,    0, -182,    0,    0,
  792, -242,    0,  792,  675,    0,  675,    0,    0,
};
short yyrindex[] = {                                     96,
    0,    0,    0,    0,    0,    0,    0,   96,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  199,    0,   97,    0,    0,    0,    0,    0,  476,
    0,    0,    0,  279,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0, -194,    0,   96,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   49,    0,    0, -192,    0,  199,  515,    0,    0,
 -190,    0,    0,    0,    0,  238,  320,  359,  398,  437,
    0,   43,   82,  121,  160,    0,    0,    0,    0,  226,
    0,  556,    0,    0,    0,    0, -184,    0,    0,    0,
    0,    0,    0,    0,  226,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -190,   49,    0,   49, -184,   49,
    0,  226,    0,   49,    0,    0,    0,    0,    0,    0,
  226,  597,    0,  226,   49,    0,   49,    0,    0,
};
short yygindex[] = {                                      0,
   -5,  -25,  -55,    2,    0,   14,    0,    0,    0,    0,
    0,   46,    9,    0,    0,    0,   -8,  107,   64,    0,
    0,    0,    0,  -36,  -23,  -56,    0,  -93,    0,   -9,
   -3,    0,
};
#define YYTABLESIZE 1121
short yytable[] = {                                      81,
    4,   22,   43,   54,    3,    3,  117,    6,    6,   22,
    9,    3,   41,   24,   50,  106,   70,   42,   53,   48,
   49,   24,    6,   58,   52,   10,   10,   44,   57,   55,
   83,   56,   10,   56,   55,  105,   56,   85,  117,  118,
   75,  119,   22,   64,   65,   66,   67,   71,   49,   68,
   69,   84,   52,   72,  125,   77,   47,   47,   22,   97,
   98,   51,   79,   74,   91,   64,   65,   66,   67,  133,
   24,  136,   22,   22,   99,  109,  107,  143,  112,  110,
  128,   21,  113,  122,  101,  101,  124,  130,  148,   47,
  149,  135,  134,  140,  144,   49,   11,  142,   87,   78,
   81,   22,   85,   86,   87,   88,   89,   90,   83,   92,
   93,   94,   95,   96,   96,   45,   22,   80,  146,  137,
   24,  131,    0,  129,    0,    0,  127,   22,  126,   22,
  114,   22,    0,   22,    0,   22,    0,    0,    0,    0,
    0,  101,   22,  139,    0,   22,   22,  101,   22,    0,
   64,   65,   66,   67,  145,   73,    0,  147,    0,   23,
    0,    0,    0,   47,    1,    0,    2,    3,    4,    5,
    6,    7,    0,    8,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,    0,    0,    0,    0,   10,   11,
    0,   12,    0,   13,   14,   15,    0,    0,    4,    0,
   16,    0,    0,    1,   17,    2,    3,    4,    5,    6,
    7,    0,  100,    0,    0,    3,    4,    5,    6,    0,
    0,    0,    9,    0,    0,   49,    0,   10,   11,    0,
   12,    9,   13,   14,   15,    0,   10,   39,    0,   16,
    0,    0,    0,   17,    0,    0,    0,    0,   16,    0,
   76,    0,    0,    0,    0,    0,    4,    0,    4,    4,
    4,    4,    4,    4,    4,    4,    0,    0,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    0,   30,    0,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    0,    0,    4,    4,   22,    0,
   22,   22,   22,   22,   22,   22,   22,   22,    0,    0,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   34,
    0,    0,   22,   22,   22,   22,   22,   22,   22,   22,
   49,    0,   49,    0,   22,   22,    0,   21,   22,   21,
   21,   21,   21,   21,   21,   21,   21,    0,    0,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   33,    0,
    0,   21,   21,   21,   21,   21,   21,   21,   21,    0,
    0,    0,    0,   21,   21,    0,   24,   21,   24,   24,
   24,   24,   24,   24,   24,   24,    0,    0,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   36,    0,    0,
   24,   24,   24,   24,   24,   24,   24,   24,    0,    0,
    0,    0,   24,   24,    0,   23,   24,   23,   23,   23,
   23,   23,   23,   23,   23,    0,    0,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   35,    0,    0,   23,
   23,   23,   23,   23,   23,   23,   23,    0,    0,    0,
    0,   23,   23,    0,    4,   23,    4,    4,    4,    4,
    4,    4,    0,    4,    0,    0,    4,    4,    4,    4,
    4,    0,    0,    4,    4,   16,    0,    0,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
   49,    0,    0,   39,    4,   39,   39,   39,   39,   39,
   39,   39,   39,    0,    0,    0,    0,   49,    0,   49,
   39,   39,   39,    0,   45,    0,    0,   39,   39,   39,
   39,   39,   39,   39,   39,    0,    0,    0,    0,   39,
   39,    0,    0,   39,   30,    0,   30,   30,   30,   30,
   30,   30,   30,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,    0,   61,    0,    0,   30,   30,
   30,   30,   30,   30,   30,   30,    0,    0,    0,    0,
   30,   30,    0,    0,   30,   34,    0,   34,   34,   34,
   34,   34,   34,   34,   34,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,    0,   64,    0,    0,   34,
   34,   34,   34,   34,   34,   34,   34,    0,    0,    0,
    0,   34,   34,    0,   33,   34,   33,   33,   33,   33,
   33,   33,   33,   33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   33,    0,    0,    0,    0,   33,   33,
   33,   33,   33,   33,   33,   33,    0,    0,    0,    0,
   33,   33,    0,   36,   33,   36,   36,   36,   36,   36,
   36,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   36,    0,    0,    0,    0,   36,   36,   36,
   36,   36,   36,   36,   36,    0,    0,    0,    0,   36,
   36,    0,   35,   36,   35,   35,   35,   35,   35,   35,
   35,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,    0,    0,    0,    0,   35,   35,   35,   35,
   35,   35,   35,   35,    0,    0,    0,    0,   35,   35,
    0,   16,   35,   16,   16,   16,   16,   16,   16,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   16,    0,    0,    0,    0,   16,   16,   16,   16,   16,
   16,   16,   16,    0,    0,    0,    0,   16,    0,    0,
   45,   16,   45,   45,   45,   45,   45,   45,    0,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   45,
    0,    0,    0,    0,   45,   45,   45,   45,   45,   45,
   45,   45,    0,    0,    0,    0,   45,    0,    0,    0,
   45,   61,    0,   61,   61,   61,   61,   61,   61,    0,
   61,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,    0,    0,    0,    0,   61,   61,    0,   61,    0,
   61,   61,   61,    0,    0,    0,    0,   61,    0,    0,
    0,   61,   64,    0,   64,   64,   64,   64,   64,   64,
    0,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   64,    0,    0,    0,    0,   64,   64,    0,   64,
    0,   64,   64,   64,    3,    4,    5,    6,   64,    0,
    0,    1,   64,    2,    3,    4,    5,    6,    7,    0,
    9,    0,    0,    0,    0,   10,    0,    0,    0,    0,
    9,    0,  115,    0,    0,   10,   11,   16,   12,    0,
   13,   14,   15,    0,    0,    0,    0,   16,    0,    0,
    1,   17,    2,    3,    4,    5,    6,    7,    0,  132,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    9,
    0,    0,    0,    0,   10,   11,    0,   12,    0,   13,
   14,   15,    0,    0,    0,    0,   16,    0,    0,    1,
   17,    2,    3,    4,    5,    6,    7,    0,  138,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,    0,    0,   10,   11,    0,   12,    0,   13,   14,
   15,    0,    0,    0,    0,   16,    0,    0,    1,   17,
    2,    3,    4,    5,    6,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    9,    0,  141,
    0,    0,   10,   11,    0,   12,    0,   13,   14,   15,
    0,    0,    0,    0,   16,    0,    0,    1,   17,    2,
    3,    4,    5,    6,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    0,    0,    0,
    0,   10,   11,    0,   12,    0,   13,   14,   15,    0,
    0,    0,    0,   16,    0,    0,    0,   17,   58,   59,
   60,   61,   62,    0,    0,    0,   63,   58,   59,   60,
   61,   62,    0,    0,    0,   63,    0,    0,   64,   65,
   66,   67,    0,   73,    0,    0,    0,   64,   65,   66,
   67,
};
short yycheck[] = {                                      55,
    0,    0,    8,  266,  259,  259,  100,  262,  262,    8,
  275,  259,  265,    0,   13,   72,   42,  292,   17,   11,
   12,    8,  262,  268,   16,  280,  280,  292,  265,  292,
   56,  294,  280,  294,  292,   72,  294,  292,  132,  282,
  292,  284,    0,  288,  289,  290,  291,  264,    0,  273,
  274,   57,   44,  264,  110,   54,   11,   12,   57,   68,
   69,   16,   54,  293,   63,  288,  289,  290,  291,  126,
   57,  128,   71,   72,  293,  295,   75,  134,  293,  297,
  264,    0,  295,  297,   71,   72,  293,  264,  145,   44,
  147,  128,  264,  130,  277,    0,    0,  134,  293,   54,
  293,  100,  293,   58,   59,   60,   61,   62,  293,   64,
   65,   66,   67,   68,   69,    9,  115,   54,  142,  129,
    0,  125,   -1,  122,   -1,   -1,  118,  126,  115,  128,
   85,  130,   -1,  132,   -1,  134,   -1,   -1,   -1,   -1,
   -1,  128,  141,  130,   -1,  144,  145,  134,  147,   -1,
  288,  289,  290,  291,  141,  293,   -1,  144,   -1,    0,
   -1,   -1,   -1,  118,  256,   -1,  258,  259,  260,  261,
  262,  263,   -1,  265,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  275,   -1,   -1,   -1,   -1,  280,  281,
   -1,  283,   -1,  285,  286,  287,   -1,   -1,    0,   -1,
  292,   -1,   -1,  256,  296,  258,  259,  260,  261,  262,
  263,   -1,  265,   -1,   -1,  259,  260,  261,  262,   -1,
   -1,   -1,  275,   -1,   -1,    0,   -1,  280,  281,   -1,
  283,  275,  285,  286,  287,   -1,  280,    0,   -1,  292,
   -1,   -1,   -1,  296,   -1,   -1,   -1,   -1,  292,   -1,
  294,   -1,   -1,   -1,   -1,   -1,  256,   -1,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,  268,  269,
  270,  271,  272,  273,  274,  275,  276,   -1,    0,   -1,
  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,   -1,   -1,  296,  297,  256,   -1,
  258,  259,  260,  261,  262,  263,  264,  265,   -1,   -1,
  268,  269,  270,  271,  272,  273,  274,  275,  276,    0,
   -1,   -1,  280,  281,  282,  283,  284,  285,  286,  287,
  282,   -1,  284,   -1,  292,  293,   -1,  256,  296,  258,
  259,  260,  261,  262,  263,  264,  265,   -1,   -1,  268,
  269,  270,  271,  272,  273,  274,  275,  276,    0,   -1,
   -1,  280,  281,  282,  283,  284,  285,  286,  287,   -1,
   -1,   -1,   -1,  292,  293,   -1,  256,  296,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,  268,  269,
  270,  271,  272,  273,  274,  275,  276,    0,   -1,   -1,
  280,  281,  282,  283,  284,  285,  286,  287,   -1,   -1,
   -1,   -1,  292,  293,   -1,  256,  296,  258,  259,  260,
  261,  262,  263,  264,  265,   -1,   -1,  268,  269,  270,
  271,  272,  273,  274,  275,  276,    0,   -1,   -1,  280,
  281,  282,  283,  284,  285,  286,  287,   -1,   -1,   -1,
   -1,  292,  293,   -1,  256,  296,  258,  259,  260,  261,
  262,  263,   -1,  265,   -1,   -1,  268,  269,  270,  271,
  272,   -1,   -1,  275,  276,    0,   -1,   -1,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  265,   -1,   -1,  256,  296,  258,  259,  260,  261,  262,
  263,  264,  265,   -1,   -1,   -1,   -1,  282,   -1,  284,
  273,  274,  275,   -1,    0,   -1,   -1,  280,  281,  282,
  283,  284,  285,  286,  287,   -1,   -1,   -1,   -1,  292,
  293,   -1,   -1,  296,  256,   -1,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  275,   -1,    0,   -1,   -1,  280,  281,
  282,  283,  284,  285,  286,  287,   -1,   -1,   -1,   -1,
  292,  293,   -1,   -1,  296,  256,   -1,  258,  259,  260,
  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  275,   -1,    0,   -1,   -1,  280,
  281,  282,  283,  284,  285,  286,  287,   -1,   -1,   -1,
   -1,  292,  293,   -1,  256,  296,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  275,   -1,   -1,   -1,   -1,  280,  281,
  282,  283,  284,  285,  286,  287,   -1,   -1,   -1,   -1,
  292,  293,   -1,  256,  296,  258,  259,  260,  261,  262,
  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  275,   -1,   -1,   -1,   -1,  280,  281,  282,
  283,  284,  285,  286,  287,   -1,   -1,   -1,   -1,  292,
  293,   -1,  256,  296,  258,  259,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,   -1,  280,  281,  282,  283,
  284,  285,  286,  287,   -1,   -1,   -1,   -1,  292,  293,
   -1,  256,  296,  258,  259,  260,  261,  262,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,   -1,   -1,   -1,   -1,  280,  281,  282,  283,  284,
  285,  286,  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,
  256,  296,  258,  259,  260,  261,  262,  263,   -1,  265,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,
   -1,   -1,   -1,   -1,  280,  281,  282,  283,  284,  285,
  286,  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,   -1,
  296,  256,   -1,  258,  259,  260,  261,  262,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,   -1,   -1,   -1,   -1,  280,  281,   -1,  283,   -1,
  285,  286,  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,
   -1,  296,  256,   -1,  258,  259,  260,  261,  262,  263,
   -1,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,   -1,  280,  281,   -1,  283,
   -1,  285,  286,  287,  259,  260,  261,  262,  292,   -1,
   -1,  256,  296,  258,  259,  260,  261,  262,  263,   -1,
  275,   -1,   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,
  275,   -1,  277,   -1,   -1,  280,  281,  292,  283,   -1,
  285,  286,  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,
  256,  296,  258,  259,  260,  261,  262,  263,   -1,  265,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,
   -1,   -1,   -1,   -1,  280,  281,   -1,  283,   -1,  285,
  286,  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,  256,
  296,  258,  259,  260,  261,  262,  263,   -1,  265,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,   -1,
   -1,   -1,   -1,  280,  281,   -1,  283,   -1,  285,  286,
  287,   -1,   -1,   -1,   -1,  292,   -1,   -1,  256,  296,
  258,  259,  260,  261,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,   -1,  277,
   -1,   -1,  280,  281,   -1,  283,   -1,  285,  286,  287,
   -1,   -1,   -1,   -1,  292,   -1,   -1,  256,  296,  258,
  259,  260,  261,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  275,   -1,   -1,   -1,
   -1,  280,  281,   -1,  283,   -1,  285,  286,  287,   -1,
   -1,   -1,   -1,  292,   -1,   -1,   -1,  296,  268,  269,
  270,  271,  272,   -1,   -1,   -1,  276,  268,  269,  270,
  271,  272,   -1,   -1,   -1,  276,   -1,   -1,  288,  289,
  290,  291,   -1,  293,   -1,   -1,   -1,  288,  289,  290,
  291,
};
#define YYFINAL 18
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_EndOfFile","T_Return",
"T_Number","T_True","T_False","T_ID","T_Print","T_Cln","T_NL","T_EQL","T_NEQ",
"T_EQ","T_GT","T_LT","T_EGT","T_ELT","T_Or","T_And","T_Not","T_In","ID","ND",
"DD","T_String","T_If","T_Elif","T_While","T_Else","T_Import","T_Break",
"T_Pass","T_MN","T_PL","T_DV","T_ML","T_OP","T_CP","T_OB","T_CB","T_Def",
"T_Comma","T_List",
};
char *yyrule[] = {
"$accept : StartDebugger",
"StartDebugger : StartParse",
"constant : T_Number",
"constant : T_String",
"term : id",
"term : constant",
"term : list_index",
"id : T_ID",
"list_index : id T_OB constant T_CB",
"StartParse : T_NL StartParse",
"StartParse : finalStatements T_NL StartParse",
"StartParse : finalStatements",
"basic_stmt : pass_stmt",
"basic_stmt : break_stmt",
"basic_stmt : import_stmt",
"basic_stmt : assign_stmt",
"basic_stmt : arith_exp",
"basic_stmt : bool_exp",
"basic_stmt : print_stmt",
"basic_stmt : return_stmt",
"arith_exp : term",
"arith_exp : arith_exp T_PL arith_exp",
"arith_exp : arith_exp T_MN arith_exp",
"arith_exp : arith_exp T_ML arith_exp",
"arith_exp : arith_exp T_DV arith_exp",
"arith_exp : T_OP arith_exp T_CP",
"ROP : T_GT",
"ROP : T_LT",
"ROP : T_EGT",
"ROP : T_ELT",
"bool_exp : bool_term",
"bool_exp : bool_term T_Or bool_term",
"bool_exp : bool_term T_And bool_term",
"bool_exp : arith_exp T_LT arith_exp",
"bool_exp : arith_exp T_GT arith_exp",
"bool_exp : arith_exp T_ELT arith_exp",
"bool_exp : arith_exp T_EGT arith_exp",
"bool_exp : arith_exp T_In id",
"bool_term : bool_factor",
"bool_term : arith_exp T_EQ arith_exp",
"bool_term : T_True",
"bool_term : T_False",
"bool_factor : T_Not bool_factor",
"bool_factor : T_OP bool_exp T_CP",
"import_stmt : T_Import id",
"assign_stmt : id T_EQL arith_exp",
"assign_stmt : id T_EQL bool_exp",
"assign_stmt : id T_EQL func_call",
"assign_stmt : id T_EQL T_OB T_CB",
"assign_stmt :",
"pass_stmt : T_Pass",
"break_stmt : T_Break",
"return_stmt : T_Return",
"print_stmt : T_Print T_OP constant T_CP",
"finalStatements : basic_stmt",
"finalStatements : cmpd_stmt",
"finalStatements : func_def",
"finalStatements : func_call",
"finalStatements : error T_NL",
"cmpd_stmt : if_stmt",
"cmpd_stmt : while_stmt",
"if_stmt : T_If bool_exp T_Cln start_suite",
"if_stmt : T_If bool_exp T_Cln start_suite elif_stmts",
"if_stmt : T_If bool_exp T_Cln suite",
"elif_stmts : T_Elif bool_exp T_Cln start_suite",
"elif_stmts : T_Elif bool_exp T_Cln start_suite elif_stmts",
"elif_stmts : T_Elif bool_exp T_Cln suite",
"elif_stmts : else_stmt",
"else_stmt : T_Else T_Cln start_suite",
"else_stmt : T_Else T_Cln suite",
"while_stmt : T_While bool_exp T_Cln start_suite",
"while_stmt : T_While bool_exp T_Cln suite",
"start_suite : finalStatements",
"start_suite : T_NL ID finalStatements suite",
"start_suite :",
"suite : T_NL ID finalStatements suite",
"suite : T_NL end_suite",
"suite : end_suite",
"end_suite : finalStatements",
"end_suite :",
"args : id args_list",
"args :",
"args_list : T_Comma id args_list",
"args_list :",
"call_list : T_Comma term call_list",
"call_list :",
"call_args : term call_list",
"call_args :",
"func_def : T_Def id T_OP args T_CP T_Cln start_suite",
"func_call : id T_OP call_args T_CP",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 162 "par1.y"

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






#line 580 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 7:
#line 67 "par1.y"
{	printf("\n## Checking in Symbol Table : %s\n", Inp_txt);

		if(check_table(Inp_txt)==0){
			printf("   >> Inserting into Symbol Table : %s\n", Inp_txt);
			into_table(Inp_txt,0);			
		}
		
		else{
			printf("   \"%s\" already in Symbol Table\n");
		}				
	}
break;
case 12:
#line 83 "par1.y"
{yyval=yyvsp[0];}
break;
case 13:
#line 84 "par1.y"
{yyval=yyvsp[0];}
break;
case 14:
#line 85 "par1.y"
{yyval=yyvsp[0];}
break;
case 15:
#line 86 "par1.y"
{yyval=yyvsp[0];}
break;
case 16:
#line 87 "par1.y"
{yyval=yyvsp[0];}
break;
case 17:
#line 88 "par1.y"
{yyval=yyvsp[0];}
break;
case 18:
#line 89 "par1.y"
{yyval=yyvsp[0];}
break;
case 19:
#line 90 "par1.y"
{yyval=yyvsp[0];}
break;
case 20:
#line 93 "par1.y"
{yyval=yyvsp[0];}
break;
case 21:
#line 94 "par1.y"
{yyval = createOp("+", 2, yyvsp[-2], yyvsp[0]);}
break;
case 22:
#line 95 "par1.y"
{yyval = createOp("-", 2, yyvsp[-2], yyvsp[0]);}
break;
case 23:
#line 96 "par1.y"
{yyval = createOp("*", 2, yyvsp[-2], yyvsp[0]);}
break;
case 24:
#line 97 "par1.y"
{yyval = createOp("/", 2, yyvsp[-2], yyvsp[0]);}
break;
case 25:
#line 99 "par1.y"
{yyval = yyvsp[-1];}
break;
case 54:
#line 128 "par1.y"
{ printtree(yyvsp[0]); }
break;
#line 794 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
