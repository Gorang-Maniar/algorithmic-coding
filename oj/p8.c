#include<stdio.h>
int main()
{
	int n,i,q,x,p,j,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			scanf("%d",&p);
			scanf("%d",&x);
			for(q=0;q<p;q++)
			
				scanf("%d",&a[q]);
		while(p!=0)
		{

			for(q=0;q<p;)
			{
			q=q+x-1;
			j=0;
			for(j=q;j<p;j++)
			a[j]=a[j+1];
			if(j>p)
				j=j%p;
			
			}

			p--;
		}
		printf("%d",a[0]);
		for(i=0;i<p-1;i++)
		printf("%d ",a[j]);
		printf("%d\n",a[p-1]);
	}
	return 0;
}

