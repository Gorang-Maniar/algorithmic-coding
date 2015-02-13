//to find least common descendent of 2 nodes given in a tree
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
int main()
{
	node *l,*m,*a,*b;
	int n,o,i,j,x,y,c,d,arr1[100],arr2[100],a1=0,a2=0;
	printf("ENTER NUMBER OF ELEMENTS\n");
	scanf("%d",&n);
	printf("ENTER ROOT ELEMENT\n");
	scanf("%d",&o);
	l=(node *)malloc(sizeof(node));
	l->left=NULL;
	l->right=NULL;
	l->a=o;
	m=l;
	printf("ENTER THE ELEMENTS\n");
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&o);
		insert(m,o);
	}
	printf("ENTER TWO NODES WHOSE COMMON DESCENDENT HAS TO BE FOUND\n");
	scanf("%d %d",&x,&y);
	c=find(m,x);
	d=find(m,y);
	if((c==(-1))||(d==(-1)))
		printf("NODE NOT PRESENT IN BST\n");
	else
	{
		while((m->a)!=x)
		{
			if((m->a)>x)
			{
				arr1[a1]=m->a;
				a1++;
				m=m->left;
			}
			if((m->a)<x)
			{
				arr1[a1]=m->a;
				a1++;
				m=m->right;
			}
		}
		arr2[a1]=m->a;
		m=l;
		while((m->a)!=y)
		{
			if((m->a)>y)
			{
				arr2[a2]=m->a;
				a2++;
				m=m->left;
			}
			if((m->a)<y)
			{
				arr2[a2]=m->a;
				a2++;
				m=m->right;
			}
		}
		arr2[a2]=m->a;
	}
	if(a1>=a2)
	{
		for(j=(a1-a2);j>=0;j--)
		{
			if(arr1[j]==arr2[j])
				break;
		}
	}
	else
	{
		for(j=(a2-a1);j>=0;j--)
		{
			if(arr2[j]==arr1[j])
				break;
		}
	}
	printf("COMMON NODE IS %d\n",arr1[j]);
	return 0;
}
		
