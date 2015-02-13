#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node
{
	int data;
	node *next;
};


node* enque(node *root,int data)
{
	node *temp,*head;
	head=root;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(root==NULL)
		return temp;
	else
	{
		while(root->next!=NULL)
			root=root->next;
		root->next=temp;
		return head;
	}
}

int global;

node* deque(node *root)
{
		global=root->data;

		return root->next;
	
	
	
}

int main()
{
	int n,dis[1000],parent[1000],data,i,s,j,k,end;
	char state[1000];
	node *root=NULL;
	
	scanf("%d",&n);
	int ad[n+1][n+1];
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		{
			scanf("%d",&data);
			ad[j][k]=data;
		}
	}


	for(i=1;i<=n;i++)
	{
		
		dis[i]=10000;
		state[i]='N';
		parent[i]=0;
	}
	scanf("%d%d",&s,&end);
	dis[s]=0;
	state[s]='I';
	parent[s]=0;
	root=enque(root,s);
	while(root!=NULL)
	{
		root=deque(root);
		i=global;
		for(k=1;k<=n;k++)
		{
			if(ad[i][k]==1 && state[k]=='N')
			{
				state[k]='I';
				parent[k]=i;
				dis[k]=dis[i]+1;
				root=enque(root,k);
			}
		}
		state[i]='F';
		//printf("k");
	}
	printf("%d\n",dis[end]);
	






	return 0;
}
