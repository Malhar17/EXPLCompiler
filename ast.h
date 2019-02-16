#define voidtype 0
#define inttype 1
#define booltype 2
#define strtype 3
#define LF 0
#define RD 1
#define WT 2
#define OP 3
#define CNT 4
#define IFEL 5
#define IFST 6
#define WHILEDO 7
#define COND 8
#define BRKST 9
#define CONTST 10
#define DOWHILE 11
#define REPEATTUNTIL 12
#define ARRAY 13
#define FTD 14
#define FTC 15
#define RET 16
#define OR_ 17
#define AND_ 18

struct Lsymbol{
	char *name;	//name of the variable
	int type;		//type of the variable:(Integer / String) 
	int binding;	//local binding of the variable
	struct Lsymbol *next;	//points to the next Local Symbol Table entry
};


struct Gsymbol {
	char* name;		// name of the variable
	int type;		// type of the variable
	int size;		// size of the type of the variable
	int rowsize;	// size of each row (only for 2D array)
	int binding;	// stores the static memory address allocated to the variable
	struct argumentList *paramlist;	//pointer to the head of the formal parameter list in the case of functions
	int flabel; 	//a label for identifying the starting address of a function's code
	struct Gsymbol *next;
	struct Lsymbol *Lsym;
};


typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct tnode *left,*right;	//left and right branches   
}tnode;

struct varList {
	char *name;
	struct varList *next;
	int size;
	int rowsize;
	struct argumentList *argList;
};

struct argumentList {
	char *name;
	int type;
	struct argumentList *next;
};
//Create a node tnode*/
//struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *l, struct tnode *r);

//constant node
struct tnode* makeConstantNode(int n);

//operator node
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

//variavle node
struct tnode* makeVarNode(char *c);

//read node
struct tnode* makeReadNode(struct tnode *l);

//connector node
struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r);

//write node
struct tnode* makeWriteNode(struct tnode *l);

//while node
struct tnode* makeWhileNode(struct tnode *l, struct tnode *r);

//if node
struct tnode* makeIfNode(struct tnode *l, struct tnode *r);

//ifelse node
struct tnode* makeIfElseNode(struct tnode *l, struct tnode *m, struct tnode *r);

//conditional node
struct tnode* makeCondNode(char *c, struct tnode *l, struct tnode *r);

//break and continue node
struct tnode* makeJmpNode(int x);

//do while node
struct tnode* makeDoWhileNode(struct tnode *l, struct tnode *r);

//repeat untill node
struct tnode* makeRepeatNode(struct tnode *l, struct tnode *r);

//make variable list
struct varList* makeVarList(char *name, int size, int rowsize);

//add variable to list
struct varList* addVarList(struct varList *p, struct varList *q);

//print global symbol table
void printSymTable();

//make string node
struct tnode* makeStringNode(char *c);

//make array node
struct tnode* makeArrayNode(char *c, struct tnode *l);

//make 2d array node
struct tnode* make2DArrayNode(char *c, struct tnode *l, struct tnode *r);

//make fucntion definition node
struct tnode* makeFuncDefNode(int type, char *name, struct tnode *l);

//make function call node
struct tnode* makeFuncCallNode(char *name, struct tnode *l);

//local symbol table install function
void Linstall(char *name, int type, int binding);

//make AND node
struct tnode* makeAndNode(struct tnode *l, struct tnode *r);

//make OR node
struct tnode* makeOrNode(struct tnode *l, struct tnode *r);

//make return node
struct tnode* makeReturnNode(struct tnode *l);