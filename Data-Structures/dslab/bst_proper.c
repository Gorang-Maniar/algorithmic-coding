//bst with insert,search,levelorder,preorder,postorder,and inorder functions and delete using doubly linnked lists
#include<stdio.h>
#include<stdlib.h>
int a[100][100]={'\0'};//for levelorder traversal
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
node* deletefind(node *x,int y)
{
	if(x!=NULL)
	{
		if(x->a==y)
			return x;
		else if((x->a)>y)
			return deletefind(x->left,y);
		else if((x->a)<y)
			return deletefind(x->right,y);
	}
	return NULL;
}
void delete(node *x,int m)
{
	node *y,*w,*z;
	y=deletefind(x,m);
	if(y==NULL)
		printf("ELEMENT NOT FOUND\n");
	else
	{
		if((y->left==NULL)&&(y->right==NULL))
		{
			w=y->parent;
			if(w->left!=NULL)
			{
				if(w->left->a==m)
					w->left=NULL;
				else
					w->right=NULL;
			}
			else
				w->right=NULL;
			free(y);
		}
		else if((y->left==NULL)&&(y->right!=NULL))
		{
			w=y->parent;
			if(w->left!=NULL)
			{
				if(w->left->a==m)
					w->left=y->right;
				else
					w->right=y->right;
			}
			else
				w->right=y->right;
					free(y);
		}
		else if((y->left!=NULL)&&(y->right==NULL))
		{
			w=y->parent;
			if(w->left!=NULL)
			{
				if(w->left->a==m)
					w->left=y->left;
				else
					w->right=y->left;
			}
			else
				w->right=y->left;
			free(y);
		}
		else if((y->left!=NULL)&&(y->right!=NULL))
		{
			w=y->left;
			int temp;
			while(w->right!=NULL)
				w=w->right;
			temp=w->a;
			w->a=y->a;
			y->a=temp;
			y=w;
			if((y->left==NULL)&&(y->right==NULL))
			{
				w=y->parent;
				if(w->left!=NULL)
				{
					if(w->left->a==m)
						w->left=NULL;
					else
						w->right=NULL;
				}
				else
					w->right=NULL;
				free(y);
			}
			else if((y->left==NULL)&&(y->right!=NULL))
			{
				w=y->parent;
				if(w->left!=NULL)
				{
					if(w->left->a==m)
						w->left=y->right;
					else
						w->right=y->right;
				}
				else
					w->right=y->right;
						free(y);
			}
			else if((y->left!=NULL)&&(y->right==NULL))
			{
				w=y->parent;
				if(w->left!=NULL)
				{
					if(w->left->a==m)
						w->left=y->left;
					else
						w->right=y->left;
				}
				else
					w->right=y->left;
				free(y);
			}
		}	
	}
}
int main()
{
	node *l,*m;
	int n,o,i,u,j,x,y;
	printf("ENTER ROOT ELEMENT\n");
	scanf("%d",&o);
	l=(node *)malloc(sizeof(node));
	l->left=NULL;
	l->right=NULL;
	l->parent=NULL;
	l->a=o;
	m=l;
	printf("ENTER 1 FOR INSERT\nENTER 2 FOR FIND\nENTER 3 FOR DELETE\nENTER 4 FOR INORDER TRAVERSAL\nENTER 5 FOR PREORDER TRAVERSAL\nENTER 6 FOR POSTORDER TRAVERSAL\nENTER 7 FOR LEVELORDER TRAVERSAL\n");
	while((scanf("%d",&n))!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&o);
			insert(m,o);
		}
		else if(n==2)
		{
			scanf("%d",&o);
			u=find(m,o);
			if(u==1)
				printf("ELEMENT FOUND\n");
			else
				printf("ELEMENT NOT FOUND\n");
		}
		else if(n==3)
		{
			scanf("%d",&o);
			delete(m,o);
		}
		else if(n==4)
		{
			printf("INORDER TRAVERSAL IS\n");
			inorder(m);
			printf("\n");
		}
		else if(n==5)
		{
			printf("PREORDER TRAVERSAL IS\n");
			preorder(m);
			printf("\n");
		}
		else if(n==6)
		{
			printf("POSTORDER TRAVERSAL IS\n");
			postorder(m);
			printf("\n");
		}
		else if(n==7)
		{
			printf("LEVELORDER TRAVERSAL IS\n");
			levelorder(m,0);
			for(i=0;a[i][0]!='\0';i++)
			{
				for(j=0;a[i][j]!='\0';j++)
					printf("%d ",a[i][j]);
				printf("\n");
			}
			for(x=0;x<100;x++)
				for(y=0;y<100;y++)
					a[x][y]='\0';
		}
		else
			printf("INVALID ENTRY\n");
	}
	return 0;
}
