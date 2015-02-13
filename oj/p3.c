#include<stdio.h>
#include<math.h>
int main()
{
	int p,q;
	long long int n,i=1,sum=0,a;
	scanf("%d",&p);
	for(q=0;q<p;q++)
	{
		sum=0;
		i=1;	
		scanf("%lld",&n);
	if(n==1)
	{
	printf("0\n");
	printf("No\n");
	return n;
	}
		for(i=2;i<=sqrt(n);i++)
			{	if(n%i==0)
					a=n/i;
if(a!=i)
			sum=sum+i+a;
	else 
sum=sum+a;		}
		sum=sum+1;	
			i++;
	
			
		
		printf("%lld\n",sum);
if(sum==1)
printf("No\n");

else if(sum==n)
		{			printf("Yes\n");
	
		
		}
		
		else
		{			printf("No\n");
		 
		}

	}

	return 0;
}
