#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,c,x;
		
		c=0;
		x=0;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			c=c+a[i];
		}
		c=c/n;
		for(i=0;i<n;i++)
		{
			if(a[i]>c)
				x++;
		}
		printf("%d\n",x);
	}
	return 0;

}
