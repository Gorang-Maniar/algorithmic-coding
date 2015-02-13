//implement an adjacency list
#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
	int a;
	struct elem *next;
}node;
int main()
{
	int n,i,x,flag;
	printf("NUMBER OF VERTICES IN GRAPH:\n");
	scanf("%d",&n);
	node *arr[n+1],*l;
	printf("ENTER NEIGHBOURS OF EACH VERTEX ENDING WITH -1\n");
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
	return 0;
}
