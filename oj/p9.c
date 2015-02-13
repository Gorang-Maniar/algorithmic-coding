#include<stdio.h>
int main()
{
	int i,p,a[100],n,c,d,s;
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&n);
		for(c=0;c<n;c++)
			scanf("%d ",&a[c]);
		for(c=0;c<n;c++)
		{
			for(d=0;d<(n-c);d++)
			{
				if(a[d]>a[d+1])
				{
					s=a[d];
					a[d]=a[d+1];
					a[d+1]=s;
				}
			}
		}
		for(c=0;c<n;c++)
			printf("%d ",a[c]);
	}
	return 0;
}
