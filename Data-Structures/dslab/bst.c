//bst with insert,search,levelorder,preorder,postorder,and inorder functions using singly linked lists
#include<stdio.h>
#include<stdlib.h>
int a[100][100]={'\0'};//for levelorder traversal
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
int find(node *x,int y)
{
	if(x!=NULL)
	{
		if(x->a==y)
			return 1;
		else if((x->a)>y)
			return find(x->left,y);
		else if((x->a)<y)
			return find(x->right,y);
	}
	return -1;
}
void inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		printf("%d ",x->a);
		inorder(x->right);
	}
}
void postorder(node *x)
{
	if(x!=NULL)
	{
		postorder(x->left);
		postorder(x->right);
		printf("%d ",x->a);
	}
}
void preorder(node *x)
{
	if(x!=NULL)
	{
		printf("%d ",x->a);
		preorder(x->left);
		preorder(x->right);
	}
}
void levelorder(node *x,int m)
{
	if(x!=NULL)
	{
		int i=0;
		while(a[m][i]!='\0')
			i++;
		a[m][i]=x->a;
		levelorder(x->left,m+1);
		levelorder(x->right,m+1);
	}
}
int main()
{
	node *l,*m;
	int n,o,i,u,j;
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
	printf("ENTER NUMBER OF ELEMENTS YOU HAVE TO FIND\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&o);
		u=find(m,o);
		if(u==1)
			printf("ELEMENT FOUND\n");
		else
			printf("ELEMENT NOT FOUND\n");
	}
	printf("INORDER TRAVERSAL IS\n");
	inorder(m);
	printf("\n");
	printf("PREORDER TRAVERSAL IS\n");
	preorder(m);
	printf("\n");
	printf("POSTORDER TRAVERSAL IS\n");
	postorder(m);
	printf("\n");
	//level order traversal code
	printf("LEVELORDER TRAVERSAL IS\n");
	levelorder(m,0);
	for(i=0;a[i][0]!='\0';i++)
	{
		for(j=0;a[i][j]!='\0';j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
