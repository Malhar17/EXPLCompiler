%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	FILE *fp;
	int reg = 0;
	int label = 0;
	int flabel = 1;
	int clabel = 0;
	int classField = 0;
	int funcPosition = 0;
	struct TypeTable *currFType = NULL;
	int whilelabel = -1;
	int bindingAddress = 4096;
	int Lbinding = 1;
	struct Gsymbol *symTable = NULL;
	struct Lsymbol *Lsym = NULL;
	struct TypeTable *Ttable = NULL;
	struct ClassTable *Ctable = NULL;
	struct ClassTable *currClass = NULL;
	int Tsize = 0;
	extern FILE *yyin;
	
	struct TypeTable *inttype;
	struct TypeTable *strtype;
	struct TypeTable *booltype;
	struct TypeTable *nulltype;
	struct TypeTable *voidtype;


	#include "ast.h"
	#include "SymbolTable.c"
	#include "ast.c"
	#include "CodeGeneration.c"

	int yylex(void);

%}

%union
{
	struct tnode *yys;	
	int integer;
	struct varList *varNameList;
	char *string;
	struct argumentList *argList;
	struct TypeTable *typeTable;
	struct FieldList *fieldsList;
	struct ClassType *classTable;
};

%token NUM PLUS MINUS MUL DIV START END WRITE READ ID ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONT LT LE GT GE EQ NE REPEAT UNTIL MOD
%token DECL ENDDECL INT STR STRING MAIN RETURN AND OR TYPE ENDTYPE ALLOC INITIALIZE FREE NIL CLASS ENDCLASS DELETE NEW SELF

%left OR AND
%left EQ NE LE LT GE GT
%left PLUS MINUS
%left MUL DIV MOD

%type <yys> expr WRITE READ ASSIGN stmt slist asgstmt instmt outstmt wedo iets ietse dowe reun Arglist Body ret Fdef FDefBlock MainBlock Program
%type <yys> field MethodDefs fieldFucntion ClassDef ClassDefBlock ClassDefList
%type <integer> NUM
%type <varNameList> Gid GidList IdList 
%type <string> ID STRING TypeName
%type <argList> Param ParamList fname mains
%type <typeTable> tname
%type <fieldsList> FieldDecl FieldDeclList

%%

Program : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock {
											$$ = makeConnectorNode($4, $5);
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen($2);
											codeGen($$);
											return 0;
										 }
		| TypeDefBlock ClassDefBlock GDeclBlock MainBlock {
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen($2);
											codeGen($4);
											return 0;
										 }
		| TypeDefBlock MainBlock {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen($2);
									return 0;
								 }
		| ClassDefBlock GDeclBlock FDefBlock MainBlock {	
											$$ = makeConnectorNode($3, $4);
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen($1);
											codeGen($$);
											return 0;
										 }
		| ClassDefBlock GDeclBlock MainBlock {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen($1);
									codeGen($3);
									return 0;
								 }
		| MainBlock {	
						fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
						fprintf(fp, "CALL F0\n");
						fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
						codeGen($1);
						return 0;
					}
	;

TypeDefBlock : TYPE TypeDefList ENDTYPE {printTypeTable();}
	;

TypeDefList : TypeDefList TypeDef {}
	| TypeDef {}
	;

TypeDef : tname FieldDeclList '}' {fieldDef($1, $2); Tsize = 0;}
	;

tname : ID '{' {Tinstall($1);$$ = TlookUp($1);}
	;

FieldDeclList : FieldDeclList FieldDecl {$$ = addField($1, $2);}
	| FieldDecl {$$ = $1;}
	;

FieldDecl : TypeName ID ';' {$$ = makeField(TlookUp($1), $2); Tsize++;}
	;

TypeName : INT {$$ ="int";}
	| STR {$$ = "str";}
	| ID {$$ =strdup($1);}
	;

ClassDefBlock : CLASS ClassDefList ENDCLASS {$$ = $2;}
	|	{$$ = NULL;}
	;

ClassDefList : ClassDefList ClassDef {$$ = makeConnectorNode($1, $2);}
	| ClassDef {$$ = $1;}
	;

ClassDef : Cname '{' classDel MethodDefs '}' {
																		cInstall(currClass); 
																		clabel++; 
																		funcPosition = 0; 
																		classField = 0;
																		currClass = NULL;
																		$$ = $4;
																		}
		;

classDel : DECL Fieldlists MethodDecl ENDDECL {printClassMember(currClass);}

Cname : ID {currClass =  makeClass($1);}
	;

Fieldlists : Fieldlists Fld {}
	|
	;

Fld : TypeName ID  ';' {classFinstall(currClass, $1, $2); classField++; }
	;

MethodDecl : MethodDecl Mdecl {}
	| Mdecl {}
	;

Mdecl : TypeName ID '(' ParamList ')' ';' {classMinstall(currClass,TlookUp($1), $2, $4); funcPosition++;}
	| TypeName ID '(' ')' ';' {classMinstall(currClass,TlookUp($1), $2, NULL); funcPosition++;}
	;

MethodDefs : MethodDefs Fdef {$$ = makeConnectorNode($1, $2);}
	| Fdef {$$ = $1;}
	;

GDeclBlock : DECL GdeclList ENDDECL {printSymTable();}
	;

GdeclList : GdeclList GDecl {} 
	| GDecl {}
	;

GDecl : ID GidList ';' 	{
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
															if(currClass == NULL)
																funcLookUp($1->type, $1->name, $2);
															$$ = makeFuncDefNode($1->type, $1->name, $6);
															currFType = NULL;
															Lsym = NULL;
															Lbinding = 1;
														}
	| fname ')' '{' LdeclBlock Body '}'{
											if(currClass == NULL)
												funcLookUp($1->type, $1->name, NULL);
											$$ = makeFuncDefNode($1->type, $1->name, $5);
											currFType = NULL;
											Lsym = NULL;
											Lbinding = 1;
										}
	; 

fname : TypeName ID '(' {$$ = makeArgList(TlookUp($1), $2); currFType = TlookUp($1); 
		if(lookUp($2) != NULL)
			Lsym = (lookUp($2))->Lsym;
		if(currClass != NULL)
			Lsym = (classMlookUp(currClass, $2))->Lsym;
		if(Lsym == NULL)
			printf("NULLLLLLLL\n");
		printf("%s function starts\n\n", $2);
	};

ParamList : Param ',' ParamList {$$ = addArgList($1, $3);}
	| Param {$$ = $1;}
	;

Param : TypeName ID {$$ = makeArgList(TlookUp($1), $2);}
	;


LdeclBlock : DECL LDecList ENDDECL {printLocalSym();}
	| {}
	;

LDecList : LDecList LDecl {}
	| LDecl {}
	;

LDecl : TypeName IdList ';' {
							while($2 != NULL)
								{
									Linstall($2->name, TlookUp($1), Lbinding);
									Lbinding++;
									$2 = $2->next;
								}
						}
	; 

IdList : IdList ',' ID {$$ = addLVarList($1, $3);}
	| ID {$$ = makeLVarList($1);}
	;

MainBlock : mains ')' '{' LdeclBlock Body '}' {
												$$ = makeFuncDefNode($1->type, $1->name, $5);
												currFType = NULL;
												Lsym = NULL;
												Lbinding = 1;
											  }
          ;

mains : INT MAIN '(' {install("main", "int", 0, 0, NULL); $$ = makeArgList(inttype, "main"); currFType = inttype; Lsym = NULL;};

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
	| field ASSIGN expr {$$ = makeOperatorNode('=',$1, $3);}
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
	| field {$$ = $1;}
	| fieldFucntion {$$ = $1;}
	| ALLOC '(' ')' {$$ = makeAllocNode();}
	| FREE '(' expr ')' {$$ = makeFreeNode($3);}
	| INITIALIZE '(' ')' {$$ = makeInitializeNode();}
	| NIL {$$ = makeNullNode();}
	| NEW '(' ID ')' {$$ = makeNewFunctionNode($3);}
	| DELETE '(' field ')' {$$ = makeDeleteNode($3);}
	;

fieldFucntion : SELF '.' ID '(' Arglist ')' {$$ = makeFieldFucntionNode(makeSelfNode(), $3, $5);}
	| SELF '.' ID '(' ')' {$$ = makeFieldFucntionNode(makeSelfNode(), $3, NULL);}
	| ID '.' ID '(' Arglist ')' {$$ = makeFieldFucntionNode(makeVarNode($1), $3, $5);}
	| ID '.' ID '(' ')' {$$ = makeFieldFucntionNode(makeVarNode($1), $3, NULL);}
	| field '.' ID '(' Arglist ')' {$$ = makeFieldFucntionNode($1, $3, $5);}
	| field '.' ID '(' ')' {$$ = makeFieldFucntionNode($1, $3, NULL);}
	;


Arglist : expr ',' Arglist {$$ = makeConnectorNode($1, $3);}
	| expr {$$ = makeConnectorNode($1, NULL);}
	;

field : field '.' ID {$$ = makeFieldNode($1, $3);}
	| ID '.' ID {$$ = makeFieldNode(makeVarNode($1), $3);}
	| SELF '.' ID {$$ = makeFieldNode(makeSelfNode(), $3);}
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
	createTypeTable();
	yyparse();
	return 0;
}