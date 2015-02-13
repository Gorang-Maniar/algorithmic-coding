#include<stdio.h>
#include<math.h>
int main()
{

	long long int n,i,sum,a,w,p,q;
	scanf("%lld",&p);
	for(q=0;q<p;q++)
	{
		sum=1;
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			printf("No\n");
			continue;	
		}
		else
		{
			w=sqrt(n);
			
			
			for(i=2;i<=w;i++)
			{	if(n%i==0)
				{	
					a=n/i;				
					sum=sum+i+a;
				if(i==a)
					sum=sum-a;
				}
			}
		}

			printf("%lld\n",sum);
			if(sum==n)
			{
				printf("Yes\n");
			}

			else
			{		
				printf("No\n");
			}
	}
	return 0;
}
