%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	FILE *fp;
	int reg = 0;
	int label = 0;
	int whilelabel = -1;
	int bindingAddress = 4096;
	struct Gsymbol *symTable = NULL;
	extern FILE *yyin;
	
	#include "ast.h"
	#include "ast.c"

	int yylex(void);

%}

%union
{
	struct tnode *yys;	
	int integer;
	struct varList *varNameList;
	char *string;
};

%token NUM PLUS MINUS MUL DIV START END WRITE READ ID ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONT LT LE GT GE EQ NE REPEAT UNTIL MOD
%token DECL ENDDECL INT STR STRING

%left EQ NE LE LT GE GT
%left PLUS MINUS
%left MUL DIV MOD

%type <yys> expr WRITE READ ASSIGN stmt slist asgstmt instmt outstmt wedo iets ietse dowe reun
%type <integer> type NUM
%type <varNameList> varlist
%type <string> ID STRING

%%

program : declarations START slist END {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
								codeGen($3);
					fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1");
					return 0;
					}
	| declarations START END {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
					fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1");
					}
	;

declarations : DECL decllist ENDDECL {printSymTable();}
	| DECL ENDDECL {}
	;

decllist : decllist decl {}
	| decl {}
	;

decl : type varlist ';' {
							while($2 != NULL)
							{
								install($2->name, $1, $2->size, $2->rowsize);
								$2 = $2->next;
							}
						} 
	;

type : INT { $$ = inttype;}
	| STR {$$ = strtype;}
	;

varlist : varlist ','  ID {$$ = addVarList($1, $3, 1, 1);}
	| varlist ','  ID '[' NUM ']' {$$ = addVarList($1, $3, 1, $5);}
	| varlist ','  ID '[' NUM ']' '[' NUM ']' {$$ = addVarList($1, $3, $5, $8);}
	| ID {$$ = makeVarList($1, 1, 1);}
	| ID '[' NUM ']' {$$ = makeVarList($1, 1, $3);}
	| ID '[' NUM ']' '[' NUM ']' {$$ = makeVarList($1, $3, $6);}
	;

slist : slist stmt ';' {$$ = makeConnectorNode($1, $2);}
	| stmt ';' {$$ = $1;}
	;

stmt : instmt {$$ = $1;}
	| outstmt {$$ = $1;}
	| asgstmt {$$ = $1;}
	| wedo {$$ = $1;}
	| iets {$$ = $1;}
	| ietse {$$ = $1;}
	| BREAK {$$ = makeJmpNode(BRKST);}
	| CONT {$$ = makeJmpNode(CONTST);}
	| reun {$$ = $1;}
	| dowe {$$ = $1;}
	;

wedo : WHILE '(' expr ')' DO slist ENDWHILE {$$ = makeWhileNode($3, $6);};

iets : IF '(' expr ')' THEN slist ENDIF  { $$ = makeIfNode($3, $6);};

ietse : IF '(' expr ')' THEN slist ELSE slist ENDIF  { $$ = makeIfElseNode($3, $6, $8);};

instmt : READ '(' ID ')' {$$ = makeReadNode(makeVarNode($3));}
	| READ '(' ID '[' expr ']' ')' {$$ = makeReadNode(makeArrayNode($3, $5));}
	| READ '(' ID '[' expr ']' '[' expr ']' ')' {$$ = makeReadNode(make2DArrayNode($3, $5, $8));}
	;

outstmt : WRITE '(' expr ')' {$$ = makeWriteNode($3);};

asgstmt : ID ASSIGN expr {$$ = makeOperatorNode('=', makeVarNode($1), $3);}
	| ID '[' expr ']' ASSIGN expr {$$ = makeOperatorNode('=',makeArrayNode($1,$3),$6);}
	| ID '[' expr ']' '[' expr ']' ASSIGN expr {$$ = makeOperatorNode('=',make2DArrayNode($1,$3, $6),$9);}
	;

reun : REPEAT slist UNTIL '(' expr ')' {$$ = makeRepeatNode($2, $5);};

dowe : DO slist WHILE '(' expr ')' {$$ = makeDoWhileNode($2, $5);};

expr : expr PLUS expr {$$ = makeOperatorNode('+',$1, $3);}
	| expr MUL expr {$$ = makeOperatorNode('*',$1, $3);}
	| expr MINUS expr {$$ = makeOperatorNode('-',$1, $3);}
	| expr DIV expr {$$ = makeOperatorNode('/',$1, $3);}
	| expr MOD expr {$$ = makeOperatorNode('%', $1, $3);}
	| '(' expr ')' {$$ = $2;}
	| ID { $$ = makeVarNode($1);}
	| NUM { $$ = makeConstantNode($1);}
	| expr EQ expr {$$ = makeCondNode("==", $1, $3);}
	| expr NE expr {$$ = makeCondNode("!=", $1, $3);}
	| expr LT expr {$$ = makeCondNode("<", $1, $3);}
	| expr GT expr {$$ = makeCondNode(">", $1, $3);}
	| expr LE expr {$$ = makeCondNode("<=", $1, $3);}
	| expr GE expr {$$ = makeCondNode(">=", $1, $3);}
	| STRING {$$ = makeStringNode($1);}
	| ID '[' expr ']' {$$ = makeArrayNode($1, $3);}
	| ID '[' expr ']' '[' expr ']' {$$ = make2DArrayNode($1, $3, $6);}
	;

%%

yyerror(char const *s)
{
    printf("%s\n",s);
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