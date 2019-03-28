struct tnode* makeConstantNode(int n){
    printf("Const %d\n", n );
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = inttype;
    t->nodetype = LF;
    t->varname = NULL;
    t->Gentry = NULL;
    t->val = n;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct tnode* makeStringNode(char *c){
    printf("String %s\n", c );
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = strtype;
    t->nodetype = LF;
    t->varname = c;
    t->Gentry = NULL;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct tnode* makeVarNode(char *c){
    printf("Var %s\n", c );
    struct Gsymbol *x = lookUp(c);
    struct Lsymbol *y = LlookUp(c);
    if(x == NULL && y == NULL)
    {
        printf("%s Undeclared\n",c);
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    if(y != NULL)
        t->type = y->type;
    else t->type = x->type;
    t->nodetype = LF;
    t->varname = c;
    t->Gentry = x;
    t->Lentry = y;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct tnode* makeArrayNode(char *c, struct tnode *l){
    printf("Var %s\n", c );
    struct Gsymbol *x = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    x = lookUp(c);
    if(x == NULL)
    {
        printf("%s Undeclared\n",c);
        exit(1);
    }
    if(l->type != inttype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = x->type;
    t->nodetype = ARRAY;
    t->varname = c;
    t->Gentry = x;
    t->left = l;
    t->right = NULL;
    return t;
}

struct tnode* make2DArrayNode(char *c, struct tnode *l, struct tnode *r){
    printf("Var %s\n", c );
    struct Gsymbol *x = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    x = lookUp(c);
    if(x == NULL)
    {
        printf("%s Undeclared\n",c);
        exit(1);
    }
    if(l->type != inttype || r->type != inttype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = x->type;
    t->nodetype = ARRAY;
    t->varname = c;
    t->Gentry = x;
    t->left = l;
    t->right = r;
    return t;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    printf("OP %c\n", c );
    if(l->type != r->type && r->type != nulltype)
    {
        printf("OP Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->varname = malloc(sizeof(char));
    *(t->varname) = c;
    t->type = l->type;
    t->nodetype = OP;
    t->left = l;
    t->right = r;
    return t;
}


struct tnode* makeReadNode(struct tnode *l){
    printf("RD %s\n", l->varname );
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = voidtype;
    t->nodetype = RD;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeWriteNode(struct tnode *l){
    printf("WT %s\n", l->varname );
    if(l->type != inttype && l->type != strtype)
    {
        printf("WT %s Type mismatch\n",l->varname);
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = WT;
    t->type = voidtype;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r){
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = CNT;
    t->type = voidtype;
    t->left = l;
    t->right = r;
    t->varname = NULL;
    return t;
}

struct tnode* makeIfElseNode(struct tnode *l, struct tnode *m, struct tnode *r)
{
    if(l->type != booltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = IFEL;
    t->type = voidtype;
    struct tnode *e;
    e = (struct tnode*)malloc(sizeof(struct tnode));
    e->nodetype = CNT;
    e->type = voidtype;
    e->left = m;
    e->right = r;
    t->left = l;
    t->right = e;
    return t;
}

struct tnode* makeIfNode(struct tnode *l, struct tnode *r)
{
    if(l->type != booltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = IFST;
    t->type = voidtype;
    t->left = l;
    t->right = r;
    return t;
}

struct tnode* makeWhileNode(struct tnode *l, struct tnode *r)
{
    if(l->type != booltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = WHILEDO;
    t->type = voidtype;
    t->left = l;
    t->right = r;
    return t;   
}

struct tnode* makeRepeatNode(struct tnode *l, struct tnode *r)
{
    if(r->type != booltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = REPEATTUNTIL;
    t->type = voidtype;
    t->left = l;
    t->right = r;
    return t;   
}

struct tnode* makeDoWhileNode(struct tnode *l, struct tnode *r)
{
    if(r->type != booltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = DOWHILE;
    t->type = voidtype;
    t->left = l;
    t->right = r;
    return t;   
}

struct tnode* makeCondNode(char *c, struct tnode *l, struct tnode *r)
{
    printf("COND %s\n",c);
    if((l->type != inttype || r->type != inttype) && r->type != nulltype)
    {
        printf("Type mismatch\n");
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->varname = c;
    t->type = booltype;
    t->nodetype = COND;
    t->left = l;
    t->right = r;
    return t;
}

struct tnode* makeJmpNode(int x)
{
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = x;
    t->type = voidtype;
    t->left  = t->right = NULL;
    return t;
}

struct tnode* makeFuncDefNode(struct TypeTable *type, char *name, struct tnode *l)
{
    struct Gsymbol *x = lookUp(name);
    if(x == NULL)
    {
        printf("%s not defined\n",name);
        exit(1);
    }
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->val = Lbinding-1;
    t->nodetype = FTD;
    t->type = x->type;
    t->left = l;
    t->right = NULL;
    t->Gentry = x;
    t->Lentry = Lsym;
    printLocalSym();
    return t;
}

struct tnode* makeFuncCallNode(char *name, struct tnode *l)
{
    struct Gsymbol *x = lookUp(name);
    if(x == NULL)
    {
        printf("%s not defined\n",name);
        exit(1);
    }
    parameterCheck(x->paramlist, l);
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = FTC;
    t->type = x->type;
    t->left = l;
    t->right = NULL;
    t->Gentry = x;
    return t;
}

struct tnode* makeReturnNode(struct tnode *l)
{
    if(l->type != currFType)
    {
        printf("return type improper\n");
        exit(1);
    }
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = RET;
    t->val = Lbinding-1;
    t->left = l;
    return t;
}

struct tnode* makeOrNode(struct tnode *l, struct tnode *r)
{
    if(l->type != booltype || r->type != booltype)
    {
        printf("type mismatch in ||\n");
        exit(1);
    }
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = booltype;
    t->nodetype = OR_;
    t->left = l;
    t->right = r;
    return t;
}

struct tnode* makeAndNode(struct tnode *l, struct tnode *r)
{
    if(l->type != booltype || r->type != booltype)
    {
        printf("type mismatch in &&\n");
        exit(1);
    }
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = booltype;
    t->nodetype = AND_;
    t->left = l;
    t->right = r;
    return t;
}

struct tnode* makeAllocNode()
{
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = nulltype;
    t->nodetype = ALC;
    t->left = t->right = NULL;
    return t;
}

struct tnode* makeInitializeNode()
{
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = inttype;
    t->nodetype = INTLZ;
    t->left = t->right = NULL;
    return t;
}

struct tnode* makeFreeNode(struct tnode *l)
{
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = inttype;
    t->nodetype = FRE;
    t->left = l;
    t->right = NULL;
    return t;
}

struct tnode* makeNullNode()
{
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = nulltype;
    t->nodetype = NIL_;
    t->left = t->right = NULL;
    return t;
}

struct tnode* makeFieldNode(struct tnode *l, char *name)
{
    struct FieldList *f = FLookUp(l->type,name);
    if(f == NULL)
    {
        printf("%s does not have %s field\n", l->varname, name);
        exit(1);
    }
    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->varname = name;
    t->val = f->fieldIndex;
    t->type = f->type;
    t->nodetype = FLD;
    t->left = l;
    t->right = NULL;
    return t;
}