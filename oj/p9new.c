#include<stdio.h>
int main()
{
	int i,p,a[500],n,c,d,s,q;
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&n);	
	for(c=0;c<n;c++)
			scanf("%d",&a[c]);

		for(c=0;c<n-1;c++)
		{
			for(d=c+1;d<n;d++)
				if(a[c]>a[d])
				{
					s=a[c];
					a[c]=a[d];
					a[d]=s;
				}
			printf("%d ",a[c]);
		}
		printf("%d\n",a[n-1]);
	
	}
	return 0;
}
