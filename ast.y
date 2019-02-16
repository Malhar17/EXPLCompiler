%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	FILE *fp;
	int reg = 0;
	int label = 0;
	int flabel = 1;
	int currFType = -1;
	int whilelabel = -1;
	int bindingAddress = 4096;
	int Lbinding = 1;
	struct Gsymbol *symTable = NULL;
	struct Lsymbol *Lsym = NULL;
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
	struct argumentList *argList;
};

%token NUM PLUS MINUS MUL DIV START END WRITE READ ID ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONT LT LE GT GE EQ NE REPEAT UNTIL MOD
%token DECL ENDDECL INT STR STRING MAIN RETURN AND OR

%left OR AND
%left EQ NE LE LT GE GT
%left PLUS MINUS
%left MUL DIV MOD

%type <yys> expr WRITE READ ASSIGN stmt slist asgstmt instmt outstmt wedo iets ietse dowe reun Arglist Body ret Fdef FDefBlock MainBlock Program
%type <integer> Type NUM
%type <varNameList> Gid GidList IdList 
%type <string> ID STRING
%type <argList> Param ParamList fname mains

%%

Program : GDeclBlock FDefBlock MainBlock {	$$ = makeConnectorNode($2, $3);
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen($$);
											return 0;
										 }
	| GDeclBlock MainBlock {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
							fprintf(fp, "CALL F0\n");
							fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
							codeGen($2);
							return 0;}
	| MainBlock {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
							fprintf(fp, "CALL F0\n");
							fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
							codeGen($1);
							return 0;}
	;

GDeclBlock : DECL GdeclList ENDDECL {printSymTable();}
	| DECL ENDDECL {}
	;

GdeclList : GdeclList GDecl {} 
	| GDecl {}
	;

GDecl : Type GidList ';' 	{
								while($2 != NULL)
								{
									install($2->name, $1, $2->size, $2->rowsize, $2->argList);
									$2 = $2->next;
									Lsym = NULL;
								}
							}
	;

GidList : GidList ',' Gid {$$ = addVarList($1, $3);}
	| Gid {$$ = $1;}
	; 

Gid : ID {$$ = makeVarList($1, 1, 1);}
	| ID '[' NUM ']' {$$ = makeVarList($1, $3, 1);}
	| ID '(' ParamList ')' {$$ = addFunc($1, $3);}
	| ID '(' ')' {$$ = addFunc($1, NULL);}
	;


FDefBlock : FDefBlock Fdef {$$ = makeConnectorNode($1, $2);}
	| Fdef {$$ = $1;}
	;

Fdef : fname ParamList ')' '{' LdeclBlock Body '}'{
															funcLookUp($1->type, $1->name, $2);
															$$ = makeFuncDefNode($1->type, $1->name, $6);
															currFType = -1;
															Lsym = NULL;
															Lbinding = 1;
														}
	; 

fname : Type ID '(' {$$ = makeArgList($1, $2); currFType = $1; Lsym = (lookUp($2))->Lsym;};

ParamList : ParamList ',' Param {$$ = addArgList($1, $3);}
	| Param {$$ = $1;}
	;

Param : Type ID {$$ = makeArgList($1, $2);}
	;

Type : INT {$$ = inttype;}
	| STR {$$ = strtype;}
	;


LdeclBlock : DECL LDecList ENDDECL {}
	| DECL ENDDECL {}
	;

LDecList : LDecList LDecl {}
	| LDecl {}
	;

LDecl : Type IdList ';' {
							while($2 != NULL)
								{
									Linstall($2->name, $1, Lbinding);
									Lbinding++;
									$2 = $2->next;
								}
							printLocalSym();
						}
	; 

IdList : IdList ',' ID {$$ = addLVarList($1, $3);}
	| ID {$$ = makeLVarList($1);}
	;

MainBlock : mains ')' '{' LdeclBlock Body '}' {
												$$ = makeFuncDefNode($1->type, $1->name, $5);
												currFType = -1;
												Lsym = NULL;
												Lbinding = 1;
											  }
          ;

mains : INT MAIN '(' {install("main", inttype, 0, 0, NULL); $$ = makeArgList(inttype, "main"); currFType = inttype; Lsym = NULL;};

Body : START slist END {$$ = $2;}
	| START END {$$ = NULL;}
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
	| ret {$$ = $1;}
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

ret : RETURN expr {$$ = makeReturnNode($2);}
	;

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
	| ID '(' ')' {$$ = makeFuncCallNode($1, NULL);}
	| ID '(' Arglist ')' {$$ = makeFuncCallNode($1, $3);}
	| expr OR expr {$$ = makeOrNode($1, $3);}
	| expr AND expr {$$ = makeAndNode($1, $3);}
	;

Arglist : Arglist ',' expr {$$ = makeConnectorNode($1, $3);}
	| expr {$$ = makeConnectorNode(NULL, $1);}
	;

%%

int yyerror(char const *s)
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