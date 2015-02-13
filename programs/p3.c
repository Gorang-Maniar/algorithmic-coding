#include<stdio.h>
int main()
{
	int p,q;
	long long int n,i=1,sum=0;
	scanf("%d",&p);
	for(q=0;q<p;q++)
	{
		sum=0;
		i=1;	
		scanf("%lld",&n);
		
		while(i<n)
	
		{		
			if(n%i==0)
				sum = sum+i;
			i++;
		}	
		
		printf("%lld\n",sum);
		if(sum==n)
		{			printf("Yes\n");
	
		
		}
		
		else
		{			printf("No\n");
		 
		}

	}

	return 0;
}
