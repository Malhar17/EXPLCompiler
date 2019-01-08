%{
	#include <stdio.h>
	#include <stdlib.h>

	int reg = 0;
	int res;
	FILE *fp;

	#include "exprtree.h"
	#include "exprtree.c"

	int yylex(void);
	
%}

%union
{
	struct tnode *yys;	
};

%token NUM PLUS MINUS MUL DIV END

%left PLUS MINUS
%left MUL DIV

%type <yys> NUM expr

%%

program : expr END	{
				res = codeGen($1);
				return res;
			}
		;

expr : PLUS expr expr		{	
	$$ = makeOperatorNode('+',$2,$3);}
	 | MINUS expr expr  	{$$ = makeOperatorNode('-',$2,$3);}
	 | MUL expr expr	{$$ = makeOperatorNode('*',$2,$3);}
	 | DIV expr expr	{$$ = makeOperatorNode('/',$2,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	fp = fopen("a.xsm","w");
	fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	yyparse();
	fprintf(fp, "MOV R2, 5\nPUSH R2\nMOV R2, -2\nPUSH R2\nPUSH R%d\nPUSH R2\nPUSH R2\nINT 7\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1", res);
	fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R%d\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1", res);
	fclose(fp);
	return 0;
}