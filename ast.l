%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "ast.h"
	#include <stdlib.h>
	YYSTYPE yylval;
	int linenumber = 1;
	int charnumber = 1;
	char *var;
	char* stringcopy(char *b, int n);
%}

%%

"read" {printf("Read\n");charnumber += yyleng;return READ;}
"write" {printf("Write\n");charnumber += yyleng;return WRITE;}
"begin" {charnumber += yyleng;return START;}
"end" {charnumber += yyleng;return END;}
"if" {printf("if\n");charnumber += yyleng;return IF;}
"then" {printf("then\n");charnumber += yyleng;return THEN;}
"else" {printf("else\n");charnumber += yyleng;return ELSE;}
"endif" {printf("endif\n");charnumber += yyleng;return ENDIF;}
"while" {printf("while\n");charnumber += yyleng;return WHILE;}
"do" {printf("do\n");charnumber += yyleng;return DO;}
"endwhile" {printf("endwhile\n");charnumber += yyleng;return ENDWHILE;}
"break" {charnumber += yyleng;return BREAK;}
"continue" {charnumber += yyleng;return CONT;}
"repeat" {charnumber += yyleng;return REPEAT;}
"until" {charnumber += yyleng;return UNTIL;}
"decl" {charnumber += yyleng;return DECL;}
"enddecl" {charnumber += yyleng;return ENDDECL;}
"int" {charnumber += yyleng;return INT;}
"str" {charnumber += yyleng;return STR;}
"main" {return MAIN;}
"return" {return RETURN;}
"+"	{charnumber += yyleng;return PLUS;}
"-"	{charnumber += yyleng;return MINUS;}
"*"	{charnumber += yyleng;return MUL;}
"/"	{charnumber += yyleng;return DIV;}
"%" {charnumber += yyleng;return MOD;}
"=" {charnumber += yyleng;return ASSIGN;}
"||" {charnumber += yyleng; return OR;}
"&&" {charnumber += yyleng; return AND;}
"==" {charnumber += yyleng;return EQ;}
"!=" {charnumber += yyleng;return NE;}
"<" {charnumber += yyleng;return LT;}
">" {charnumber += yyleng;return GT;}
"<=" {charnumber += yyleng;return LE;}
">=" {charnumber += yyleng;return GE;}
";" {charnumber += yyleng;return *yytext;}
[{}] {charnumber +=yyleng; return *yytext;}
"["	{charnumber += yyleng;return *yytext;}
"]"	{charnumber += yyleng;return *yytext;}
"\n" {linenumber++; charnumber = 1;}
[()]	{charnumber += yyleng;return *yytext;}
" " {charnumber += yyleng;}
"," {charnumber += yyleng; return *yytext;}
"\t" {charnumber += yyleng;}
[0-9]+	{var = stringcopy(yytext, yyleng);yylval.integer = atoi(var); printf("%d",atoi(var)); charnumber += yyleng; return NUM;}
[a-zA-Z][a-zA-Z|0-9]* {char *var = stringcopy(yytext, yyleng);printf("lex %s\n",var);charnumber += yyleng;yylval.string = var; return ID;}
"\"".*"\"" {var = stringcopy(yytext, yyleng);charnumber += yyleng;yylval.string = var; return STRING;}
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