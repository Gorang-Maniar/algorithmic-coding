//find if there is a path of given length in the bst and print that path
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int a;
	struct tree *left;
	struct tree *right;
}node;
void insert(node *x,int y)
{
	if((x->a)>y)
	{
		if(x->left==NULL)
		{
			x->left=(node *)malloc(sizeof(node));
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
			x=x->right;
			x->left=NULL;
			x->right=NULL;
			x->a=y;
		}
		else
			insert(x->right,y);
	}
}
int path_find(node *x,int y,int sum)
{
	int u;
	sum=sum+x->a;
	if(sum==y)
	{
		//if(x->left!=NULL && x->right!=NULL)
		//{
		//	printf("path not found");
		//	return 0;
		//}
		//else
		//{
		printf("PATH FOUND\n");
		printf("%d\n",x->a);
		return 1;
		//}
	}
	if(x->left!=NULL)
	{
		u=path_find(x->left,y,sum);
		if(u==1)
		{
			printf("%d\n",x->a);
			return 1;
		}
	}
	if(x->right!=NULL)
	{
		u=path_find(x->right,y,sum);
		if(u==1)
		{
			printf("%d\n",x->a);
			return 1;
		}
	}
	return 0;
}
int main()
{
	node *l,*m;
	int n,o,i,u;
	printf("ENTER NUMBER OF ELEMENTS IN THE TREE\n");
	scanf("%d",&n);
	printf("ENTER %d ELEMENTS\n",n);
	scanf("%d",&o);
	l=(node *)malloc(sizeof(node));
	l->left=NULL;
	l->right=NULL;
	l->a=o;
	m=l;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&o);
		insert(m,o);
	}
	printf("THE NUMBER OF PATHS YOU HAVE TO FIND\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&o);	
		u=path_find(m,o,0);
		if(u==0)
			printf("PATH NOT FOUND\n");
	}
	return 0;
}			
