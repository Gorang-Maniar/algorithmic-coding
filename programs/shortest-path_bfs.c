//implement bfs such that input is adjacency matrix and output is length of shortest path

#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0,i<n,i++)
	{
		int adjmat[100][100],a,p,num;
		printf("Enter number of vertices in the graph\n");
		scanf("%d",&num);
		printf("Enter the adjacency matrix\n");
		for(x=0;x<num;x++){
			for(y=0;y<num;y++){
				scanf("%d",&adjmat[x][y]);
			}
		}

		
