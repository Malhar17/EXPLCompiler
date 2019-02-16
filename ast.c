struct argumentList* makeArgList(int type, char * name)
{
    struct argumentList *x = (struct argumentList*)malloc(sizeof(struct argumentList));
    x->type = type;
    x->name = name;
    x->next = NULL;
    return x;
}

struct argumentList* addArgList(struct argumentList *x, struct argumentList *p)
{
    struct argumentList *q = x;
    while(q->next != NULL)
        q = q->next;
    q->next = p;
    return x;
}

struct varList* makeVarList(char *name, int size, int rowsize)
{
    struct varList *x = (struct varList*)malloc(sizeof(struct varList));
    x->name = name;
    x->next = NULL;
    x->size = size;
    x->rowsize = size;
    x->argList = NULL;
    return x;
}

struct varList* addVarList(struct varList *p, struct varList *q)
{
    q->next = p;
    return q;
}

struct varList* addFunc(char *name, struct argumentList* p)
{
    struct varList* x = (struct varList*)malloc(sizeof(struct varList));
    x->name = name;
    x->argList = p;
    return x;
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

int getFLabel()
{
    int temp = flabel;
    flabel++;
    return temp;
}

void install(char *name, int type, int size, int rowsize, struct argumentList *p)
{
    if(lookUp(name) != NULL)
    {
        printf("%s declared again\n", name);
        exit(1);
    }
    struct Gsymbol *x = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    x->name = name;
    x->type = type;
    if(size == 0)
    {
        x->flabel = getFLabel();
        if(strcmp("main", name)==0)
            x->flabel = 0;
        x->paramlist = p;
        int b = -3;
        while(p != NULL)
        {
            Linstall(p->name, p->type, b);
            b--;
            p = p->next;
        }
        x->Lsym = Lsym;
    }
    else x->flabel = -1;
    x->size = size;
    x->rowsize = rowsize;
    x->binding = getBinding(size*rowsize);
    x->next = symTable;
    symTable = x;
}

void funcLookUp(int type, char *name, struct argumentList *p)
{
    struct Gsymbol *x = lookUp(name);
    if(x == NULL)
    {
        printf("%s not declared\n", name);
        exit(1);
    }
    if(x->type != type)
    {
        printf("%s function return type mismatch\n", name);
        exit(1);
    }
    struct argumentList *q = x->paramlist;
    while(q != NULL && p != NULL)
    {
        if(q->type != p->type || strcmp(q->name, p->name) != 0)
        {
            printf("In %s, argument mismatch\n", name);
            exit(1);
        }
        q = q->next;
        p = p->next;
    }
    if(q != NULL || p != NULL)
    {
        printf("In %s, arguments in conflict with function definition\n", name);
        exit(1);
    }
}

struct varList* makeLVarList(char *name)
{
    struct varList *x = (struct varList*)malloc(sizeof(struct varList));
    x->name = name;
    x->next = NULL;
    return x;
}

struct varList* addLVarList(struct varList *p, char *name)
{
    struct varList *x = (struct varList*)malloc(sizeof(struct varList));
    x->name = name;
    x->next = p;
    return x;
}


struct Lsymbol* LlookUp(char *name)
{
    printf("LlookUp\n");
    struct Lsymbol *x = Lsym;
    while(x != NULL)
    {
        if(strcmp(x->name, name) == 0)
            return x;
        x = x->next;
    }
    printf("hi\n");
    return NULL;
}

void Linstall(char *name, int type, int binding)
{
    if(LlookUp(name) != NULL)
    {
        printf("%s declared again\n", name);
        exit(1);
    }
    struct Lsymbol *x = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    x->name = name;
    x->type = type;
    x->binding = binding;
    x->next = Lsym;
    Lsym = x;
}

void parameterCheck(struct argumentList *x, struct tnode *t)
{
    if(x == NULL && t == NULL)
        return;
    if((x == NULL && t != NULL) || (x != NULL && t == NULL))
    {
        printf("parameter missing in function call\n");
        exit(1);
    }
    if(x->type != (t->right)->type)
    {
        printf("type mismatchin function call\n");
        exit(1);
    }
    parameterCheck(x->next,t->left);
}


void printSymTable()
{
    struct Gsymbol *x = symTable;
    printf("The Global Symbol Table:\n");
    printf("name\ttype\tsize\trowsize\tbinding\tparamlist\n");
    while(x != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\t",x->name,x->type,x->size,x->rowsize,x->binding);
        struct argumentList *p = x->paramlist;
        while(p != NULL)
        {
            printf("%d %s, ",p->type, p->name);
            p = p->next;
        }
        printf("\n");
        x = x->next;
    }
}

void printLocalSym()
{
    struct Lsymbol *x = Lsym;
    printf("The Local Symbol Table:\n");
    printf("name\ttype\tbinding\n");
    while(x != NULL)
    {
        printf("%s\t%d\t%d\t",x->name,x->type,x->binding);
        printf("\n");
        x = x->next;
    }
}

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
    printf("hi\n");
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
    t->type = voidtype;
    t->left  = t->right = NULL;
    return t;
}

struct tnode* makeFuncDefNode(int type, char *name, struct tnode *l)
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
    if(t == NULL)
        return -1;
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
                if(t->Gentry == NULL && t->Lentry == NULL)
                {
                    fprintf(fp, "MOV R%d, %s\n",temp, t->varname);
                }
                else if(t->Lentry != NULL)
                {
                    fprintf(fp, "MOV R%d, BP\n", temp);
                    fprintf(fp, "ADD R%d, %d\n", temp, (t->Lentry)->binding);
                    fprintf(fp, "MOV R%d, [R%d]\n", temp, temp);
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
            int r;
            switch(*(t->varname))
            {
                case '+':
                    l = codeGen(t->left);
                    r = codeGen(t->right);
                    fprintf(fp, "ADD R%d, R%d\n", l, r);
                    break;
                case '*':
                    l = codeGen(t->left);
                    r = codeGen(t->right);
                    fprintf(fp, "MUL R%d, R%d\n", l, r);
                    break;
                case '-':
                    l = codeGen(t->left);
                    r = codeGen(t->right);
                    fprintf(fp, "SUB R%d, R%d\n", l, r);
                    break;
                case '/':
                    l = codeGen(t->left);
                    r = codeGen(t->right);
                    fprintf(fp, "DIV R%d, R%d\n", l, r);
                    break;
                case '%':
                    l = codeGen(t->left);
                    r = codeGen(t->right);
                    fprintf(fp, "MOD R%d, R%d\n", l, r);
                    break;
                case '=':
                {   r = codeGen(t->right);
                    if((t->left)->nodetype == LF)
                    {
                        if((t->left)->Lentry != NULL)
                        {
                            int temp = getreg();
                            fprintf(fp, "MOV R%d, BP\n", temp);
                            fprintf(fp, "ADD R%d, %d\n", temp, ((t->left)->Lentry)->binding);
                            fprintf(fp, "MOV [R%d], R%d\n", temp, r);
                            freereg();
                        }
                        else
                        {
                            int st = ((t->left)->Gentry)->binding;
                            fprintf(fp, "MOV [%d], R%d\n", st, r);
                        }
                    }
                    else if((t->left)->nodetype == ARRAY)
                    {
                        int st = ((t->left)->Gentry)->binding;
                        int l = codeGen((t->left)->left);
                        if((t->left)->right != NULL)
                        {
                            int row = codeGen((t->left)->right);
                            fprintf(fp, "MUL R%d, %d\n",l, ((t->left)->Gentry)->rowsize);
                            fprintf(fp, "ADD R%d, R%d\n",l, row );
                            freereg();
                        }
                        fprintf(fp, "ADD R%d, %d\n", l, st);
                        fprintf(fp, "MOV [R%d], R%d\n", l, r);
                        freereg();
                    }
                }
            }
            freereg();
            return l;
        }
        case RD :
        {
//            printf("RD %s\n", (t->left)->varname );
            int temp = getreg();
            fprintf(fp, "BRKP\n");
            fprintf(fp, "MOV R%d, 7\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "MOV R%d, -1\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            if((t->left)->nodetype == LF)
            {
                if((t->left)->Lentry != NULL)
                {
                    fprintf(fp, "MOV R%d, BP\n", temp);
                    fprintf(fp, "ADD R%d, %d\n", temp, ((t->left)->Lentry)->binding);
                }
                else
                {
                    int st = ((t->left)->Gentry)->binding;
                    fprintf(fp, "MOV R%d, %d\n", temp, st);
                }
                
            }
            else if((t->left)->nodetype == ARRAY)
            {

                int st = ((t->left)->Gentry)->binding;
                int l = codeGen((t->left)->left);
                if((t->left)->right != NULL)
                {
                    int r = codeGen((t->left)->right);
                    fprintf(fp, "MUL R%d, %d\n",l, ((t->left)->Gentry)->rowsize);
                    fprintf(fp, "ADD R%d, R%d\n",l, r );
                    freereg();
                }
                fprintf(fp, "ADD R%d, %d\n", l, st);
                fprintf(fp, "MOV R%d, R%d\n", temp, l);
            }
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
            if((t->left)->nodetype == ARRAY)
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

        case ARRAY:
        {
            int st = (t->Gentry)->binding;
            int l = codeGen(t->left);
            int r;
            if(t->right != NULL)
            {
                r = codeGen(t->right);
                fprintf(fp, "MUL R%d, %d\n",l, (t->Gentry)->rowsize);
                fprintf(fp, "ADD R%d, R%d\n",l, r );
                freereg();
            }
            fprintf(fp, "ADD R%d, %d\n",l, st);
            fprintf(fp, "MOV R%d, [R%d]\n", l, l);
            return l;
        }

        case FTC:
        {
            int x = reg;
            for(int i=x;i>=0;i--)
                fprintf(fp, "PUSH R%d\n", i);
            struct tnode *p = t->left;
            int noArguments = 0;
            while(p != NULL)
            {
                int k = codeGen(p->right);
                fprintf(fp, "PUSH R%d\n", k);
                p = p->left;
                noArguments++;
            }
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL F%d\n", (t->Gentry)->flabel);
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, %d\n", noArguments);
            for(int i=0;i<=x;i++)
                fprintf(fp, "POP R%d\n", i);
            return l;
        }

        case FTD:
        {
            int x = reg;
            reg = 0;
            fprintf(fp, "F%d:\n", (t->Gentry)->flabel);
            fprintf(fp, "PUSH BP\n");
            fprintf(fp, "MOV BP, SP\n");
            fprintf(fp, "ADD SP, %d\n", t->val);
            codeGen(t->left);
            freereg();
            reg = x;
            break;
        }

        case RET:
        {
            int l = codeGen(t->left);
            fprintf(fp, "SUB SP, %d\n", t->val);
            int k = getreg();
            fprintf(fp, "MOV R%d, BP\n", k);
            fprintf(fp, "SUB R%d, 2\n", k);
            fprintf(fp, "MOV [R%d], R%d\n", k, l);
            freereg();
            fprintf(fp, "POP BP\n");
            fprintf(fp, "RET\n");
            break;
        }

        case AND_:
        {
            int label1 = getLabel();
            int label2 = getLabel();
            int label3 = getLabel();
            int k = getreg();
            int l = codeGen(t->left);
            fprintf(fp, "JNZ R%d, L%d\n", l, label1);
            fprintf(fp, "MOV R%d, 0\n", k);
            fprintf(fp, "JMP L%d\n", label3);
            fprintf(fp, "L%d:\n", label1);
            int r = codeGen(t->left);
            fprintf(fp, "JNZ R%d, L%d\n", r, label2);
            fprintf(fp, "MOV R%d, 0\n", k);
            fprintf(fp, "JMP L%d\n", label3);
            fprintf(fp, "L%d:\n", label2);
            fprintf(fp, "MOV R%d, 1\n", k);
            fprintf(fp, "L%d:\n", label3);
            freereg();
            freereg();
            return k;
        }

        case OR_:
        {
            int label1 = getLabel();
            int label2 = getLabel();
            int label3 = getLabel();
            int k = getreg();
            int l = codeGen(t->left);
            fprintf(fp, "JZ R%d, L%d\n", l, label1);
            fprintf(fp, "MOV R%d, 1\n", k);
            fprintf(fp, "JMP L%d\n", label3);
            fprintf(fp, "L%d:\n", label1);
            int r = codeGen(t->left);
            fprintf(fp, "JZ R%d, L%d\n", r, label2);
            fprintf(fp, "MOV R%d, 1\n", k);
            fprintf(fp, "JMP L%d\n", label3);
            fprintf(fp, "L%d:\n", label2);
            fprintf(fp, "MOV R%d, 0\n", k);
            fprintf(fp, "L%d:\n", label3);
            freereg();
            freereg();
            return k;         
        }
    }
    return 0;
}