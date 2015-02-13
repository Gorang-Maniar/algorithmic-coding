#include<stdio.h>
#include<math.h>
int main()
{int n,count,i;
	scanf("%d",&n);
	count=0;
	if(n%2==0)
		printf("No\n");
	else
	{
		count=0;
		for(i=3;i<sqrt(n);i=i+2)
		{
			if(n%i==0)
				if((n-1)%(i-1)==0)
			count++;
		}
		if(count>=3)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
