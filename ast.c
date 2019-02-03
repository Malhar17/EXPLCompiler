struct varList* makeVarList(char *name)
{
    struct varList *x = (struct varList*)malloc(sizeof(struct varList));
    x->name = name;
    x->next = NULL;
    return x;
}

struct varList* addVarList(struct varList *p, char *name)
{
    struct varList* q = (struct varList*)malloc(sizeof(struct varList));
    q->name = name;
    q->next = p;
    return q;
}

struct Gsymbol* lookUp(char *name)
{
    struct Gsymbol *x = symTable;
    while(x != NULL)
    {
        if(strcmp(x->name, name) == 0)
            break;
        x = x->next;
    }
    return x;
}

int getBinding(int size)
{
    int temp = bindingAddress;
    bindingAddress = bindingAddress + size;
    return temp;
}

void install(char *name, int type, int size)
{
    if(lookUp(name) != NULL)
    {
        printf("%s declared again\n", name);
        exit(1);
    }
    struct Gsymbol *x = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    x->name = name;
    x->type = type;
    x->size = size;
    x->binding = getBinding(size);
    x->next = symTable;
    symTable = x;
}

void printSymTable()
{
    struct Gsymbol *x = symTable;
    printf("name\ttype\tsize\tbinding\n");
    while(x != NULL)
    {
        printf("%s\t%d\t%d\t%d\n",x->name,x->type,x->size,x->binding);
        x = x->next;
    }
}

struct tnode* makeConstantNode(int n){
//    printf("Const %d\n", n );
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
//    printf("String %s\n", c );
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
//    printf("Var %s\n", c );
    struct Gsymbol *x = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    x = lookUp(c);
    if(x == NULL)
    {
        printf("%s Undeclared\n",c);
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->type = x->type;
    t->nodetype = LF;
    t->varname = c;
    t->Gentry = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
//    printf("OP %c\n", c );
    if(l->type != r->type)
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
//    printf("RD %s\n", l->varname );
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = RD;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeWriteNode(struct tnode *l){
//    printf("WT %s\n", l->varname );
    if(l->type != inttype && l->type != strtype)
    {
        printf("WT %s Type mismatch\n",l->varname);
        exit(1);
    }
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = WT;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r){
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = CNT;
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
    struct tnode *e;
    e = (struct tnode*)malloc(sizeof(struct tnode));
    e->nodetype = CNT;
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
    t->left = l;
    t->right = r;
    return t;   
}

struct tnode* makeCondNode(char *c, struct tnode *l, struct tnode *r)
{
    if(l->type != inttype || r->type != inttype)
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
    t->left  = t->right = NULL;
    return t;
}

int getreg()
{
    int t = reg;
    reg++;
    return t;
}

int getLabel()
{
    int t = label;
    label++;
    return t;
}

void freereg()
{
    reg--;
    return;
}

int codeGen(struct tnode *t){
    switch(t->nodetype)
    {
        case LF:
        {
//            printf("LF %d\n", t->type );
            int temp = getreg();
            if(t->varname == NULL)
            {
                fprintf(fp, "MOV R%d, %d\n",temp, t->val);
            }
            else
            {
                if(t->Gentry == NULL)
                {
                    fprintf(fp, "MOV R%d, %s\n",temp, t->varname);
                }
                else
                {
                    int st = (t->Gentry)->binding;
                    fprintf(fp, "MOV R%d, [%d]\n",temp, st);
                }
            }
            return temp;
        }
        case OP :
        {
//            printf("OP %c\n", *(t->varname) );
            int l;
            int r = codeGen(t->right);
            switch(*(t->varname))
            {
                case '+':
                    l = codeGen(t->left);
                    fprintf(fp, "ADD R%d, R%d\n", l, r);
                    break;
                case '*':
                    l = codeGen(t->left);
                    fprintf(fp, "MUL R%d, R%d\n", l, r);
                    break;
                case '-':
                    l = codeGen(t->left);
                    fprintf(fp, "SUB R%d, R%d\n", l, r);
                    break;
                case '/':
                    l = codeGen(t->left);
                    fprintf(fp, "DIV R%d, R%d\n", l, r);
                    break;
                case '=':
                {   int st = ((t->left)->Gentry)->binding;
                    fprintf(fp, "MOV [%d], R%d\n", st, r);
                }
            }
            freereg();
            return l;
        }
        case RD :
        {
//            printf("RD %s\n", (t->left)->varname );
            int st = ((t->left)->Gentry)->binding;
            int temp = getreg();
            fprintf(fp, "BRKP\n");
            fprintf(fp, "MOV R%d, 7\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "MOV R%d, -1\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "MOV R%d, %d\n", temp, st);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R0\n");
            fprintf(fp, "INT 6\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            freereg();
            return 0;
        }

        case WT :
        {
//            printf("WT \n" );
            int x = codeGen(t->left);
            int temp = getreg();
            fprintf(fp, "BRKP\n");
            fprintf(fp, "MOV R%d, 5\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "MOV R%d, -2\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "MOV R%d, R%d\n", temp, x);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R0\n");
            fprintf(fp, "INT 7\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            fprintf(fp, "POP R0\n");
            freereg();
            return 0;
        }

        case CNT :
            codeGen(t->left);
            codeGen(t->right);
            break;

        case WHILEDO:
        {
//            printf("WHILEDO \n");
            int label1 = getLabel();
            int label2 = getLabel();
            int x = whilelabel;
            whilelabel = label2;
            fprintf(fp, "BRKP\n");
            fprintf(fp, "L%d:\n",label1);
            int l = codeGen(t->left);
            fprintf(fp, "JZ R%d, L%d\n",l, label2 );
            codeGen(t->right);
            fprintf(fp, "JMP L%d\n", label1);
            fprintf(fp, "L%d:\n",label2);
            whilelabel = x;
            freereg();
            break;
        }

        case REPEATTUNTIL:
        {
            int label1 = getLabel();
            int label2 = getLabel();
            int x = whilelabel;
            whilelabel = label2;
            fprintf(fp, "BRKP\n");
            fprintf(fp, "L%d:\n",label1);
            codeGen(t->left);
            int l = codeGen(t->right);
            fprintf(fp, "JZ R%d, L%d\n",l, label1 );
            fprintf(fp, "L%d:\n",label2);
            whilelabel = x;
            freereg();
            break;
        }

        case DOWHILE:
        {
            int label1 = getLabel();
            int label2 = getLabel();
            int x = whilelabel;
            whilelabel = label2;
            fprintf(fp, "BRKP\n");
            fprintf(fp, "L%d:\n",label1);
            codeGen(t->left);
            int l = codeGen(t->right);
            fprintf(fp, "JNZ R%d, L%d\n",l, label1 );
            fprintf(fp, "L%d:\n",label2);
            whilelabel = x;
            freereg();
            break;
        }

        case IFST:
        {
            int label1 = getLabel();
            int l = codeGen(t->left);
            fprintf(fp, "JZ R%d, L%d\n",l, label1 );
            codeGen(t->right);
            fprintf(fp, "L%d:\n",label1);
            freereg();
            break;
        }

        case IFEL:
        {
            int label1 = getLabel();
            int label2 = getLabel();
            int l = codeGen(t->left);
            fprintf(fp, "JZ R%d, L%d\n", l, label1);
            codeGen((t->right)->left);
            fprintf(fp, "JMP L%d\n", label2);
            fprintf(fp, "L%d:\n", label1);
            codeGen((t->right)->right);
            fprintf(fp, "L%d:\n", label2);
            freereg();
            break;
        }

        case COND:
        {
//            printf("COND \n");
            int l = codeGen(t->left);
            int r = codeGen(t->right);
            if(strcmp(t->varname, "==")==0)
                fprintf(fp, "EQ R%d, R%d\n", l, r);
            else if(strcmp(t->varname, "!=")==0)
                fprintf(fp, "NE R%d, R%d\n", l, r);
            else if(strcmp(t->varname, "<")==0)
                fprintf(fp, "LT R%d, R%d\n", l, r);
            else if(strcmp(t->varname, "<=")==0)
                fprintf(fp, "LE R%d, R%d\n", l, r);
            else if(strcmp(t->varname, ">")==0)
                fprintf(fp, "GT R%d, R%d\n", l, r);
            else if(strcmp(t->varname, ">=")==0)
                fprintf(fp, "GE R%d, R%d\n", l, r);
            freereg();
            return l;
        }

        case BRKST:
        {
            if(whilelabel == -1)
                break;
            fprintf(fp, "JMP L%d\n", whilelabel);
            break;
        }

        case CONTST:
        {
            if(whilelabel == -1)
                break;
            fprintf(fp, "JMP L%d\n", (whilelabel-1));
            break;
        }

    }
    return 0;
}