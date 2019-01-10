typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

/*Create a node tnode*/
//struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);

//constant node
struct tnode* makeConstantNode(int n);

//operator node
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

//variavle node
struct tnode* makeVarNode(char c);

//read node
struct tnode* makeReadNode(struct tnode *l);

//connector node
struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r);

//write node
struct tnode* makeWriteNode(struct tnode *l);