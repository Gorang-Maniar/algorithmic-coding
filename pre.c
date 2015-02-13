#include<stdio.h>
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		long long int s,e;
		int i,j,n,fl=0;
		scanf("%lld %lld",&s,&e);
		scanf("%d",&n);
		long long int arr[n][3];
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				scanf("%lld",&arr[i][j]);
				if(arr[i][j]>s && arr[i][j]<e)
					fl=1;
			}
		}
		if(fl==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}


