#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n,k,l,r,c,p,count,arr[1000][1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{

		scanf("%d %d %d",&r,&c,&p);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				scanf("%d",&arr[i][j]);
		}

		count=0;
		while(count<=((r*c)-p))
		{
			int i,k=0,l=0;
			while(k<r && l<c)
			{
				for(i=l;i<c;++i)
					printf("%d",arr[k][i]);
				k++;
				count++;
				for(i=k;i<r;++i)
					printf("%d",arr[i][r-1]);
				c--;
				count++;
				if(k<r)
				{
					for(i=c-1;i>=l;--i)
					      printf("%d",arr[r-1][i]);
						r--;
				count++;
				}
				if(l<c)
				{
					for(i=r-1;i>=k;--i)
						printf("%d",arr[i][l]);
					l++;
					count++;
				}
			}
		}

	}
	return 0;
}
