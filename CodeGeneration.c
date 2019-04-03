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

void pushRegisters(int x)
{
    for(int i=x-1;i>0;i--)
        fprintf(fp, "PUSH R%d\n", i);
}

void popRegisters(int x)
{
    for(int i=1;i<x;i++)
        fprintf(fp, "POP R%d\n", i);
}

int codeGen(struct tnode *t){
    if(t == NULL)
        return -1;
    switch(t->nodetype)
    {
        case LF:
        {
//            printf("LF \n");
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
                    else if((t->left)->nodetype == FLD)
                    {
                        int l = codeGen((t->left)->left);
                        fprintf(fp, "ADD R%d, %d\n", l, (t->left)->val);
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
            else if((t->left)->nodetype == FLD)
            {
                int l = codeGen((t->left)->left);
                fprintf(fp, "ADD R%d, %d\n", l, (t->left)->val);
                fprintf(fp, "MOV R%d, R%d\n", temp, l);
                freereg();
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
            fprintf(fp, "BRKP\n" );
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
            pushRegisters(x);
            struct tnode *p = t->left;
            int noArguments = 0;
            while(p != NULL)
            {
                int k = codeGen(p->left);
                fprintf(fp, "PUSH R%d\n", k);
                p = p->right;
                noArguments++;
            }
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL F%d\n", (t->Gentry)->flabel);
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, %d\n", noArguments);
            popRegisters(x);
            return l;
        }

        case FTD:
        {
            int x = reg;
            reg = 0;
            if(t->Gentry != NULL)
            {
                fprintf(fp, "F%d:\n", (t->Gentry)->flabel);
            }    
            else
            {
                fprintf(fp, "F%d:\n", (t->Mentry)->flabel);
            }
            fprintf(fp, "PUSH BP\n");
            fprintf(fp, "MOV BP, SP\n");
            fprintf(fp, "ADD SP, %d\n", t->val);
            codeGen(t->left);
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

        case NIL_:
        {
            int l = getreg();
            fprintf(fp, "MOV R%d, -9999999\n", l);
            return l;
        }

        case INTLZ:
        {
            int x = reg;
            pushRegisters(x);
            int temp = getreg();
            fprintf(fp, "MOV R%d, \"Heapset\"\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            freereg();
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL 0\n");
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, 4\n");
            popRegisters(x);
            return l;
        }

        case ALC:
        {
            int x = reg;
            pushRegisters(x);
            int temp = getreg();
            fprintf(fp, "MOV R%d, \"Alloc\"\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            freereg();
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL 0\n");
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, 4\n");
            popRegisters(x);
            fprintf(fp, "BRKP\n");
            return l;
        }

        case FRE:
        {
            int x = reg;
            pushRegisters(x);
            int temp = getreg();
            fprintf(fp, "MOV R%d, \"Free\"\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            freereg();
            temp = codeGen(t->left);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            fprintf(fp, "PUSH R%d\n", temp);
            freereg();
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL 0\n");
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, 4\n");
            popRegisters(x);
            return l;
        }

        case FLD:
        {
            int l = codeGen(t->left);
            fprintf(fp, "ADD R%d, %d\n", l, t->val);
            fprintf(fp, "MOV R%d, [R%d]\n", l, l);
            return l;
        }

        case SELF_:
        {
            int temp = getreg();
            fprintf(fp, "MOV R%d, BP\n", temp);
            fprintf(fp, "ADD R%d, %d\n", temp, (t->Lentry)->binding);
            fprintf(fp, "MOV R%d, [R%d]\n", temp, temp);
            return temp;
        }

        case FLFC:
        {
            int x = reg;
            pushRegisters(x);
            struct tnode *p = t->right;
            int noArguments = 1;
            int k = codeGen(t->left);
            fprintf(fp, "PUSH R%d\n", k);
            while(p != NULL)
            {
                k = codeGen(p->left);
                fprintf(fp, "PUSH R%d\n", k);
                p = p->right;
                noArguments++;
            }
            fprintf(fp, "ADD SP, 1\n");
            fprintf(fp, "CALL F%d\n", (t->Mentry)->flabel);
            int l = getreg();
            fprintf(fp, "POP R%d\n", l);
            fprintf(fp, "SUB SP, %d\n", noArguments);
            popRegisters(x);
            return l;
        }
    }
    return 0;
}