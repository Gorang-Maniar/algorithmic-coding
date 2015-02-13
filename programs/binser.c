/*binary search*/
#include<stdio.h>
#include<stdlib.h>
int bins(int a[],int n,int x)
{
	int mid,top=n-1,bot=0;
	while(bot<=top)
	{
       mid=bot+top/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
		{
			bot=mid+1;
			bins(a,top,x);
		}
		else if(a[mid]>x)
		{
			top=mid-1;
			bins(a,top,x);
		}
		else
			return-1;
	}
}
int main()
{
	int p,bin,mid,top,x,i,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&x);
p=bins(a,n,x);
printf("%d\n",p+1);
	return 0;
}