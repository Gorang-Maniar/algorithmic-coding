#include<stdio.h>
int cmp (const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}
int sanskar(long long int arr,int n,int i)
{
	if(i>=n)
		return 1;
	if(arr[n]==(arr[n-1]+arr[i]))
	{
		sanskar(arr,n-2,i+1);
	}
	if(arr[n]>(arr[n-1]+arr[i]))
	{
		int temp;
		temp = arr[i-1];
		arr[i-1] = arr[i];
		arr[i] = temp;
		sanskar(arr,n,i);
	}
	if(arr[n]<(arr[n-1]+arr[i]))
	{



	
}
int main()
{
	int t,q;
	for(q=0;q<t,q++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		long long int arr[n+1];
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		qsort(arr,n,sizeof(long long int),cmp);



