#include<stdio.h>

int main()
{
	int t,n;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		int num,i,j,k,a,b,adj[100][100],count,ans=0;
		scanf("%d",&num);
		for(a=0;a<num;a++)
		{
			for(b=0;b<num;b++)
			{
				scanf("%d",&adj[a][b]);
			}
		}

		for(a=0;a<num;a++)
		{
			for(b=0;b<num;b++)
			{
				if(a==b)
					adj[a][b] = 1;
			}
		}

		for(i=0;i<num;i++)
		{
			for(j=0;j<num;j++)
			{
				if(adj[i][j]==1)
				{
					for(k=0;k<num;k++)
					{
						if(adj[j][k]==1)
							adj[i][k] = 1;
					}
				}
			}
		}
		for(i=0;i<num;i++)
		{
			count = 0;
			for(j=0;j<num;j++)
			{
				if(adj[i][j]==1)
					count++;
			}
			if(count>ans)
				ans = count;
		}
		printf("%d\n",ans);


	}
	return 0;

}

