CC=gcc

token: y.tab.c
	$(CC) y.tab.c -ll -o out -w

lex.yy.c: lex.l
	lex lex.l

y.tab.c: par1.y
	yacc -d par1.y

clean:
	$(RM) lex.yy.c y.tab.c y.tab.h token 
