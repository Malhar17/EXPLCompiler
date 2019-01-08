struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL){
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
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
        fprintf(fp, "MOV R%d, %d\n",temp, t->val);
        return temp;
    }
    int l = codeGen(t->left);
    int r = codeGen(t->right);
    switch(*(t->op))
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
    }
    freereg();
    return l;
}