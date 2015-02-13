//check whether a binary tree is a bst or not
#include<stdio.h>
#include<stdlib.h>
int flag=0;
typedef struct tree
{
	int a;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}node;
void insert(node *x,int y)
{
	if((x->a)>y)
	{   
		if(x->left==NULL)
		{   
			x->left=(node *)malloc(sizeof(node));
			x->left->parent=x;
			x=x->left;
			x->left=NULL;
			x->right=NULL;
			x->a=y;
		}   
		else
			insert(x->left,y);
	}   
	else if((x->a)<y)
	{   
		if(x->right==NULL)
		{   
			x->right=(node *)malloc(sizeof(node));
			x->right->parent=x;
			x=x->right;
			x->left=NULL;
			x->right=NULL;
			x->a=y;
		} 
		else
			insert(x->right,y);
	}
}
void checktree(node *x)
{
	if(x!=NULL)
	{
		checktree(x->left);
		if((x->left)!=NULL)
			if((x->a)<(x->left->a))
				flag++;
		if((x->right)!=NULL)
			if((x->a)>(x->right->a))
				flag++;
		checktree(x->right);
	}
}
int main()
{
	node *l,*m;
	int n,o,i,u;
	printf("ENTER NUMBER OF ELEMENTS\n");
	scanf("%d",&n);
	printf("ENTER ROOT ELEMENT\n");
	scanf("%d",&o);
	l=(node *)malloc(sizeof(node));
	l->left=NULL;
	l->right=NULL;
	l->parent=NULL;
	l->a=o;
	m=l;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&o);
		insert(m,o);
	}
	checktree(m);
	if(flag==0)
		printf("IT IS A BST\n");
	else
		printf("IT IS NOT A BST\n");
	return 0;
}
