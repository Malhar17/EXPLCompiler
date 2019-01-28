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
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"break" {return BREAK;}
"continue" {return CONT;}
"repeat" {return REPEAT;}
"until" {return UNTIL;}
"==" {return EQ;}
"!=" {return NE;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"\n" {}
[()]	{return *yytext;}
" " {}
"\t" {}
.	{printf("%d unknown character\n", *yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}