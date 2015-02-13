#include<stdio.h>
#include<stdlib.h>
int arr[100000],var;
int level[20][1000],q;
typedef struct bst{
	int data;
	struct bst *l;
	struct bst *r;
}bst;
void levelorder(bst *t,int m)
{
	int o=0;
	if(t!=NULL)
	{	
		levelorder(t->l,m+1);
		while(level[m][o]!=2147483647)
			o++;
		level[m][o]=t->data;
		levelorder(t->r,m+1);
	}
}
/*bst *ser(bst *t, int m)
  {
  bst *temp;
  temp = t;
  if(temp -> data == m)
  return temp;
  else if(temp -> data > m)
  {
  temp -> l = ser(temp->l,m);
  temp = temp->l;
  }
  else
  {
  temp -> r = ser(temp -> r,m);
  temp = temp -> r;
  }
  }*/

bst *ser(bst *t, int m)
{
	if(t -> data == m)
		return t;
	else if(t -> data > m)
		return t -> l = ser(t->l,m);
		
	else
		return t -> r = ser(t -> r,m);
}
bst *ins(bst *t, int n)
{
	if(t==NULL)
	{
		bst *tmp;
		tmp = (bst*)malloc(sizeof(bst));
		tmp -> l = NULL;
		tmp -> r = NULL;
		tmp -> data =n;
		t = tmp;
	}
	else if(t -> data < n)
	{
		t -> r = ins(t -> r, n);
	}
	else if(t -> data >= n)
	{
		t -> l = ins(t -> l,n);
	}
	return t;
}
void getit(bst *t);

int main()
{

	int i,n,l,p,flag,q,z,x,a,b;
	bst *t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(a=0;a<100000;a++){
			arr[a]=2147483647;
		}
		for(a=0;a<20;a++){
			for(b=0;b<1000;b++){
				level[a][b] = 2147483647;
			}
		}
		var=0;
		t = NULL;
		scanf("%d",&p);
		for(l=0;l<p;l++)
		{
			scanf("%d",&q);

			t = ins(t,q);
		} 

		//		getit(t);
		scanf("%d%d",&z,&x);
		levelorder(t,0);
		flag=0;
		for(l=0;l<20;l++)
		{
			for(p=0;p<1000;p++)
			{
				if(level[l][p]==z)
				{
					flag=1;
					break;
				}
			}
			if(flag!=0)
				break;
		}
		if(flag==0)
		{
			printf("$ $\n");
		}
		else
		{
			p++;
			if(level[l][p]==2147483647)
			{
				printf("$ $\n");
			}
			else
			{
				printf("%d ",level[l][p]);
				t=ser(t,level[l][p]);
				getit(t);
				if(arr[x-1]==2147483647)
					printf("$\n");
				else
				{
					printf("%d\n",arr[x-1]);
				}
			}
		}
	}
	return 0;
}
void getit(bst *t)
{
	if(t!=NULL)
	{
		getit(t -> l);
		arr[var++] = t -> data;
		//		printf("%d ",arr[var]);
		getit(t -> r);
	}
}
