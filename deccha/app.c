#include<stdio.h>
#include<stdlib.h>
int cmp (const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		long long int n,i,j,ct=0;
		scanf("%lld",&n);
		long long int arr[n+1];
		scanf("%lld",&arr[0]);
		for(i=1;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		qsort(arr,n,sizeof(long long int),cmp);

		for(j=1;j<n;j++)
		{
			if(arr[j]==arr[j-1])
			{	
				ct++;
			}
		}
		if(arr[0]==arr[n-1])
			printf("1\n");
		else
			printf("%lld\n",(n-ct));
	}
	return 0;
}

