%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag = 0;
	int lineNumber = 0;
	FILE *fp;
	struct node{
		int f;
		int la;
		int add;
		struct node *next;
	};

	struct node *x = NULL;

	void insert(int f,int la, int add)
	{
		printf("%d %d %d\n", f, la, add);
		if(x == NULL)
		{
			x = (struct node*)malloc(sizeof(struct node));
			x->f = f;
			x->la = la;
			x->add = add;
			x->next = NULL;
			return;
		}
		struct node *p = (struct node*)malloc(sizeof(struct node));
		p->f = f;
		p->la = la;
		p->add = add;
		p->next = x;
		x = p;
	}

	int getAdd(int f,int la)
	{
		struct node *p = x;
		while(p != NULL)
		{
			if(p->la == la && p->f == f)
				return p->add;
			p = p->next;
		}
		return -1;
	}
%}

label [L][0-9]+
flabel [F][0-9]+

%%

{label}":\n" 	{
					if(flag == 0)
						//printf("%d\n", atoi(yytext+1));
						insert(0, atoi(yytext+1),2056 +2*(lineNumber-8));
				}
" "{label}"\n"	{
					if(flag != 0)
					{
						fprintf(fp, " %d\n", getAdd(0, atoi(yytext+2)));
						printf("%d %d\n", atoi(yytext+2), getAdd(0,atoi(yytext+2)));
					}
					else lineNumber++;
				}
{flabel}":\n" 	{
					if(flag == 0)
						//printf("%d\n", atoi(yytext+1));
						insert(1, atoi(yytext+1),2056 +2*(lineNumber-8));
				}
" "{flabel}"\n"	{
					if(flag != 0)
					{
						fprintf(fp, " %d\n", getAdd(1, atoi(yytext+2)));
						printf("%d %d\n", atoi(yytext+2), getAdd(1,atoi(yytext+2)));
					}
					else lineNumber++;
				}
[\n] {
	if(flag == 0)
		lineNumber++;
	else fprintf(fp, "\n");
}
.				{
					if(flag != 0)
						fprintf(fp, "%s", yytext);
				}
%%

int yywrap(void) {
	if(flag == 0)
	{
		yyin = fopen("a.xsm", "r");
		flag = 1;
		return 0;
	}
	return 1;
}

int main()
{
	/*if(argc > 1)
	{
		FILE *in = fopen(argv[1],"r");
		yyin = in;
	}*/
	yyin = fopen("a.xsm","r");
	fp = fopen("b.xsm","w");
	yylex();
	return 0;
}