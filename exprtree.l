%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"
	#include <stdlib.h>
	YYSTYPE yylval;
	int number;

%}

%%

[0-9]+	{number = atoi(yytext); yylval.yys = makeLeafNode(number); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{return END;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}