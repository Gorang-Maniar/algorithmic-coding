#include<stdio.h>
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int n,p;
		scanf("%d %d",&n,&p);
		int fit[n+1],i,ct=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&fit[i]);
			if(fit[i]>=p)
				ct++;
		}
		printf("%d\n",ct);
	}
	return 0;
}
