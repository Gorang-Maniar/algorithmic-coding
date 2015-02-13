#include<stdio.h>
#include<stdlib.h>
int main()
{
	int u,t;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		int n,i,j,k,w,f=0,count=0,fl[1004]={0},fg[1004]={0};
		scanf("%d",&n);
		char maze[1004][1004];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			
			int c;
			do c = getchar(); while (isspace(c));
			maze[i][j] = c;
			}
		}

		for(i=n-1;i>=0;i--)
		{
			
			for(j=n-1;j>=0;j--)
			{
				f=0;
				if(maze[i][j]!='#' && fl[j]!=1 &&fg[i]!=1)
				{
						f=1;
				}
				else if(maze[i][j]=='#')
				{
					fl[j]=1;
					fg[i]=1;
				}
				if(f==1)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

