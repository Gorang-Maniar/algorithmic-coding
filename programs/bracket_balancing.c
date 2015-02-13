#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
	char ch;
	struct element* next;
	struct element* pre;
}node;
node* push(char c,node *t)
{
	t->next=(node *)malloc(sizeof(node));
	t->next->pre=t;
	t=t->next;
	t->ch=c;
	t->next=NULL;
	return t;
}
node* pop(node *t)
{
	node *f;
	f=t;
	t=t->pre;
	free(f);
	t->next=NULL;
	return t;
}
int main()
{
	//int n,j;
	//scanf("%d",&n);
	//for(j=0;j<n;j++)
	//{
		char s[100];
		scanf("%s",s);
		node *h,*g;
		int i,flag=0;
		h=(node *)malloc(sizeof(node));
		h->next=NULL;
		h->pre=NULL;
		h->ch=-1;
		g=h;
		i=0;
		while(s[i]!='\0')
		{
			if(s[i]=='{')
				g=push(s[i],g);
			else if(s[i]=='[')
				g=push(s[i],g);
			else if(s[i]=='(')
				g=push(s[i],g);
			else if(s[i]==']')
			{
				if(g->ch=='[')
					g=pop(g);
				else
				{
					printf("ERROR\n");
					flag=1;
					break;
				}
			}
			else if(s[i]=='}')
			{
				if(g->ch=='{')
					g=pop(g);
				else
				{
					printf("ERROR\n");
					flag=1;
					break;
				}
			}
			else if(s[i]==')')
			{
				if(g->ch=='(')
					g=pop(g);
				else
				{
					printf("ERROR\n");
					flag=1;
					break;
				}
			}
			i++;
		}
		if((flag==0)&&(g->ch==-1))
			printf("IT IS CORRECT!!!\n");
		else
			printf("ERROR\n");
	//}
	return 0;
}
