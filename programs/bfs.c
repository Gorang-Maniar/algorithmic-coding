//implement a breadth first search
#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
	int a;
	struct elem *next;
}node;
int main()
{
	int n,i,x,flag,s,j;
	printf("NUMBER OF VERTICES IN GRAPH:\n");
	scanf("%d",&n);
	node *arr[n+1],*l;
	int q[n],sta[n+1],dis[n+1];
	printf("ENTER NEIGHBOURS OF EACH VERTEX ENDING WITH -1\n");
	for(i=0;i<(n+1);i++)
		arr[i]=NULL;
	for(i=1;i<=n;i++)
	{
		flag=0;
		scanf("%d",&x);
		while(x!=(-1))
		{
			if(flag==0)
			{
				arr[i]=(node*)malloc(sizeof(node));
				l=arr[i];
				l->a=x;
				l->next=NULL;
				flag++;
			}
			else
			{
				l->next=(node*)malloc(sizeof(node));
				l=l->next;
				l->a=x;
				l->next=NULL;
			}
			scanf("%d",&x);
		}
	}
	//adjacency matrix is
	printf("ADJACENCY LIST IS\n");
	for(i=1;i<=n;i++)
	{
		l=arr[i];
		printf("%d --> ",i);
		while((l->next)!=NULL)
		{
			printf("%d ",l->a);
			l=l->next;
		}
		printf("%d\n",l->a);
	}
	for(i=1;i<=n;i++)
	{
		sta[i]=0;
		dis[i]=99999;
	}
	printf("ENTER STARTING NODE\n");
	scanf("%d",&s);
	j=0;
	q[j]=s;
	sta[s]=1;
	dis[s]=0;
	flag=1;
	printf("THE BFS AND CORRESPONDING DISTANCE AGAINST IT IS:\n");
	while(j!=n)
	{
		l=arr[q[j]];
		while(l!=NULL)
		{
			if((sta[l->a])==0)
			{
				q[flag]=l->a;
				dis[l->a]=dis[q[j]]+1;
				sta[l->a]=1;
				flag++;
			}
			l=l->next;
		}
		printf("%d ",q[j]);
		j++;
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",dis[q[i]]);
	printf("\n");
	return 0;
}
