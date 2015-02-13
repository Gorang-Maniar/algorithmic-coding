/*binary search using recursions*/
#include<stdio.h>
#include<stdlib.h>
int bins(int a[],int bot,int top,int x)
{
	if(bot>top)
		return -1;
	int mid,n;
	mid=(bot+top)/2;
	if(a[mid]==x)
		return mid;
	else if(a[mid]<x)
		return bins(a,mid+1,top,x);
	else if(a[mid]>x)
		return bins(a,bot,mid-1,x);
}
int main()
{
	int p,n,i,bot,top,a[100],x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	bot=0;
	top=n-1;
p=bins(a,bot,top,x);
printf("%d\n",p+1);
	return 0;
}