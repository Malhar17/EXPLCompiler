%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "ast.h"
	#include <stdlib.h>
	YYSTYPE yylval;
	int number;
	int linenumber = 1;
	int charnumber = 1;
	char* stringcopy(char *b, int n);
%}

%%

[0-9]+	{number = atoi(yytext); yylval.yys = makeConstantNode(number); charnumber += yyleng; return NUM;}
"read" {charnumber += yyleng;return READ;}
"write" {charnumber += yyleng;return WRITE;}
"begin" {charnumber += yyleng;return START;}
"end" {charnumber += yyleng;return END;}
"if" {charnumber += yyleng;return IF;}
"then" {charnumber += yyleng;return THEN;}
"else" {charnumber += yyleng;return ELSE;}
"endif" {charnumber += yyleng;return ENDIF;}
"while" {charnumber += yyleng;return WHILE;}
"do" {charnumber += yyleng;return DO;}
"endwhile" {charnumber += yyleng;return ENDWHILE;}
"break" {charnumber += yyleng;return BREAK;}
"continue" {charnumber += yyleng;return CONT;}
"repeat" {charnumber += yyleng;return REPEAT;}
"until" {charnumber += yyleng;return UNTIL;}
"decl" {charnumber += yyleng;return DECL;}
"enddecl" {charnumber += yyleng;return ENDDECL;}
"int" {charnumber += yyleng;return INT;}
"str" {charnumber += yyleng;return STR;}
"==" {charnumber += yyleng;return EQ;}
"!=" {charnumber += yyleng;return NE;}
"<" {charnumber += yyleng;return LT;}
">" {charnumber += yyleng;return GT;}
"<=" {charnumber += yyleng;return LE;}
">=" {charnumber += yyleng;return GE;}
"+"	{charnumber += yyleng;return PLUS;}
"-"	{charnumber += yyleng;return MINUS;}
"*"	{charnumber += yyleng;return MUL;}
"/"	{charnumber += yyleng;return DIV;}
"=" {charnumber += yyleng;return ASSIGN;}
";" {charnumber += yyleng;return *yytext;}
"\n" {linenumber++; charnumber = 1;}
[()]	{charnumber += yyleng;return *yytext;}
" " {charnumber += yyleng;}
"," {charnumber += yyleng; return *yytext;}
"\t" {charnumber += yyleng;}
"\"".*"\"" {char *var = stringcopy(yytext, yyleng);charnumber += yyleng;yylval.string = var; return STRING;}
[a-z][a-z|0-9]* {char *var = stringcopy(yytext, yyleng);charnumber += yyleng;yylval.string = var; return ID;}
.	{printf("%d.%d unknown character\n", linenumber, charnumber);exit(1);}

%%

int yywrap(void) {
	return 1;
}

char* stringcopy(char *b, int n)
{
	char *a = (char*)malloc(sizeof(char)*n);
	for(int i=0;i<n;i++)
		a[i] = b[i];
	return a;
}