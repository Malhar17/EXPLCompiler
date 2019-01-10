%{
	#include <stdio.h>
	#include <stdlib.h>

	FILE *fp;
	int reg = 0;
	extern FILE *yyin;
	
	#include "ast.h"
	#include "ast.c"

	int yylex(void);

%}

%union
{
	struct tnode *yys;	
};

%token NUM PLUS MINUS MUL DIV START END WRITE READ VAR ASSIGN

%left PLUS MINUS
%left MUL DIV

%type <yys> NUM expr VAR WRITE READ ASSIGN stmt slist asgstmt instmt outstmt

%%

program : START slist END';' {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, 4121\n");
								codeGen($2);
					fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1");
					return 0;
					}
	| START END ';' {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
					fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1");
					}
	;

slist : slist stmt ';' {$$ = makeConnectorNode($1, $2);}
	| stmt ';' {$$ = $1;}
	;

stmt : instmt {$$ = $1;}
	| outstmt {$$ = $1;}
	| asgstmt {$$ = $1;}
	;

instmt : READ '(' VAR ')' {$$ = makeReadNode($3);}

outstmt : WRITE '(' expr ')' {$$ = makeWriteNode($3);}

asgstmt : VAR ASSIGN expr {$$ = makeOperatorNode('=', $1, $3);}

expr : expr PLUS expr {$$ = makeOperatorNode('+',$1, $3);}
	| expr MUL expr {$$ = makeOperatorNode('*',$1, $3);}
	| expr MINUS expr {$$ = makeOperatorNode('-',$1, $3);}
	| expr DIV expr {$$ = makeOperatorNode('/',$1, $3);}
	| '(' expr ')' {$$ = $2;}
	| VAR { $$ = $1;}
	| NUM { $$ = $1;}
	;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc , char *argv[]) {
	if(argc > 1)
	{
		FILE *in = fopen(argv[1],"r");
		yyin = in;
	}
	fp = fopen("a.xsm","w");
	yyparse();
	return 0;
}