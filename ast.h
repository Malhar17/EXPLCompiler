#define inttype 0
#define booltype 1
#define strtype 2
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


struct Gsymbol {
	char* name;		// name of the variable
	int type;		// type of the variable
	int size;		// size of the type of the variable
	int binding;	// stores the static memory address allocated to the variable
	struct Gsymbol *next;
};

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
	struct Gsymbol *Gentry;
	struct tnode *left,*right;	//left and right branches   
}tnode;

struct varList {
	char *name;
	struct varList *next;
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
struct varList* makeVarList(char *name);

//add variable to list
struct varList* addVarList(struct varList *p, char *name);

//print global symbol table
void printSymTable();

//make string node
struct tnode* makeStringNode(char *c);