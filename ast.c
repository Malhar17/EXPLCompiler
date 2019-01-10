struct tnode* makeConstantNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->type = 0;
    temp->nodetype = 0;
    temp->varname = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    *(temp->varname) = c;
    temp->nodetype = 0;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeVarNode(char c){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->type = 1;
    temp->nodetype = 0;
    temp->varname = malloc(sizeof(char));
    *(temp->varname) = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeReadNode(struct tnode *l){
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = 1;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeWriteNode(struct tnode *l){
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = 2;
    t->left = l;
    t->right = NULL;
    t->varname = NULL;
    return t;
}

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r){
    struct tnode *t;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->nodetype = 3;
    t->left = l;
    t->right = r;
    t->varname = NULL;
    return t;
}

int getreg()
{
    int temp = reg;
    reg++;
    return temp;
}

void freereg()
{
    reg--;
    return;
}

int codeGen(struct tnode *t){
    if(t->left == NULL && t->right == NULL)
    {
        int temp = getreg();
        if(t->type == 0)
        {
            fprintf(fp, "MOV R%d, %d\n",temp, t->val);
        }
        else
        {
            int st = *(t->varname) - 'a' + 4096;
            fprintf(fp, "MOV R%d, [%d]\n",temp, st);
        }
        return temp;
    }
    switch(t->nodetype)
    {
        case 0 :
        {
            int l = codeGen(t->left);
            int r = codeGen(t->right);
            switch(*(t->varname))
            {
                case '+':
                    fprintf(fp, "ADD R%d, R%d\n", l, r);
                    break;
                case '*':
                    fprintf(fp, "MUL R%d, R%d\n", l, r);
                    break;
                case '-':
                    fprintf(fp, "SUB R%d, R%d\n", l, r);
                    break;
                case '/':
                    fprintf(fp, "DIV R%d, R%d\n", l, r);
                    break;
                case '=':
                {   int st = *((t->left)->varname) - 'a' + 4096;
                    fprintf(fp, "MOV [%d], R%d\n", st, r);
                }
            }
            freereg();
            return l;
        }
        case 1 :
        {
            int st = *((t->left)->varname) - 'a' + 4096;
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

        case 2 :
        {
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

        case 3 :
            codeGen(t->left);
            codeGen(t->right);
            break;
    }
    return 0;
}