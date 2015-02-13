#include<stdio.h>
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		long long int i,t,n,k,max=0;
		scanf("%lld %lld",&n,&k);
		long long int a[n+1],b[n+1];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i] = k/a[i];
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			t = a[i]*b[i];
			if(t>max)
				max=t;
		}
		printf("%lld\n",max);
	}
	return 0;
}

