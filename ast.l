%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "ast.h"
	#include <stdlib.h>
	YYSTYPE yylval;
	int number;
%}

%%

[0-9]+	{number = atoi(yytext); yylval.yys = makeConstantNode(number); return NUM;}
[a-z] {yylval.yys = makeVarNode(*yytext); return VAR;}
"read" {return READ;}
"write" {return WRITE;}
"begin" {return START;}
"end" {return END;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return ASSIGN;}
";" {return *yytext;}
"\n" {}
[()]	{return *yytext;}
" " {}
.	{printf("%d unknown character\n", *yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}