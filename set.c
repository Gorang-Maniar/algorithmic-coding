#include<stdio.h>
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	long long int d[n];
	for(i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	i=0;
	while(i<m)
	{
		char c;
		long long int x,y,j;
		scanf("%c %lld %lld",&c,&x,&y);
		if(c=='U')
		{
			d[x]=y;
			i++;
		}
		if(c=='M')
		{
			long long int max = d[y];
			for(j=x;j<y;j++)
			{
				if(d[j]>max)
					max = d[j];
			}
			printf("%lld\n",max);
			i++;
		}
		if(c=='S')
		{
			long long int sum=0;
			for(j=x;j<=y;j++)
				sum =sum + d[j];
			printf("%lld\n",sum);
			i++;
		}
		if(c=='I')
		{
			int fl=0;
			for(j=x+1;j<=y;j++)
			{
				if(d[j]-d[j-1]<0)
				{
					fl=1;
					break;
				}
			}
			if(fl==1)
				printf("0\n");
			else
				printf("1\n");
			i++;
		}
		if(c=='D')
		{
			int fl=0;
			for(j=x+1;j<=y;j++)
			{
				if(d[j]-d[j-1]>0)
				{
					fl=1;
					break;
				}
			}
			if(fl==1)
				printf("0\n");
			else
				printf("1\n");
			i++;
		}
	}
	return 0;
}
		

