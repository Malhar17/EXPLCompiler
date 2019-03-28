struct FieldList* FLookUp(struct TypeTable *t, char *name)
{
    struct FieldList *f = t->fields;
    while(f != NULL)
    {
        if(strcmp(f->name, name) == 0)
            return f;
        f = f->next;
    }
    return NULL;
}

struct TypeTable* TlookUp(char *name)
{
    struct TypeTable *x = Ttable;
    while(x != NULL)
    {
        if(strcmp(x->name, name) == 0)
            return x;
        x = x->next;
    }
    return NULL;
}

void Tinstall(char * name)
{
    if(TlookUp(name) != NULL)
    {
        printf("%s type defined again\n", name);
        exit(1);
    }
    struct TypeTable *x = (struct TypeTable*)malloc(sizeof(struct TypeTable));
    x->name = strdup(name);
    x->size = 1;
    x->fields = NULL;
    x->next = Ttable;
    Ttable = x;
}

struct FieldList* makeField(struct TypeTable *type, char *name)
{
    struct FieldList* x = (struct FieldList*)malloc(sizeof(struct FieldList));
    x->name = strdup(name);
    x->fieldIndex = Tsize;
    x->type = type;
    x->next = NULL;
    return x;
}

struct FieldList* addField(struct FieldList *p, struct FieldList *q)
{
    q->next = p;
    return q;
}

void fieldDef(struct TypeTable *t, struct FieldList *f)
{
    t->fields = f;
    t->size = Tsize;
}

void createTypeTable()
{
    Tinstall("int");
    inttype = TlookUp("int");
    Tinstall("str");
    strtype = TlookUp("str");
    Tinstall("bool");
    booltype = TlookUp("bool");
    Tinstall("null");
    nulltype = TlookUp("null");
    Tinstall("void");
    voidtype = TlookUp("void");
}

void printTypeTable()
{
    struct TypeTable *x = Ttable;
    printf("name\tsize\t\n");
    while(x != NULL)
    {
        printf("%s\t%d\t\n", x->name, x->size);
        struct FieldList *f = x->fields;
        while(f!= NULL)
        {
            printf("\t%s\t%s\t%d\n", (f->type)->name,f->name,f->fieldIndex);
            f = f->next;
        }
        x = x->next;
    }
}

struct argumentList* makeArgList(struct TypeTable *type, char * name)
{
    struct argumentList *x = (struct argumentList*)malloc(sizeof(struct argumentList));
    x->type = type;
    x->name = name;
    x->next = NULL;
    return x;
}

struct argumentList* addArgList(struct argumentList *x, struct argumentList *p)
{
    x->next = p;
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

void install(char *name, struct TypeTable *type, int size, int rowsize, struct argumentList *p)
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
    x->rowsize = rowsize;
    x->binding = getBinding(size*rowsize);
    if(size == 0)
    {
        x->flabel = getFLabel();
        if(strcmp("main", name)==0)
            x->flabel = 0;
        x->paramlist = p;
        int b = -3;
        struct argumentList *q = p;
        while(q != NULL)
        {
            b--;
            q = q->next;
        }
        b++;
        while(p != NULL)
        {
            Linstall(p->name, p->type, b);
            b++;
            p = p->next;
        }
        x->Lsym = Lsym;
        Lsym = NULL;
    }
    else x->flabel = -1;
    x->next = symTable;
    symTable = x;
}

void funcLookUp(struct TypeTable *type, char *name, struct argumentList *p)
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
    struct Lsymbol *x = Lsym;
    while(x != NULL)
    {
        if(strcmp(x->name, name) == 0)
            return x;
        x = x->next;
    }
    return NULL;
}

void Linstall(char *name, struct TypeTable *type, int binding)
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
    if(x->type != (t->left)->type)
    {
        printf("type mismatchin function call\n");
        exit(1);
    }
    parameterCheck(x->next,t->right);
}


void printSymTable()
{
    struct Gsymbol *x = symTable;
    printf("The Global Symbol Table:\n");
    printf("name\ttype\tsize\trowsize\tbinding\tparamlist\n");
    while(x != NULL)
    {
        printf("%s\t%s\t%d\t%d\t%d\t%d\t",x->name,(x->type)->name,x->size,x->rowsize,x->binding, x->flabel);
        struct argumentList *p = x->paramlist;
        while(p != NULL)
        {
            printf("%s %s, ",(p->type)->name, p->name);
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
        printf("%s\t%s\t%d\t",x->name,(x->type)->name,x->binding);
        printf("\n");
        x = x->next;
    }
}