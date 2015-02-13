#include<stdio.h>

int main()
{
	int su;
	scanf("%d",&su);
	if(su <= 10)
	{
		printf("0\n");
	}
	else
	{
		if (su<20)
		{
			printf("4\n");
		}
		else if(su == 20)
		{
			printf("15\n");
		}
		else if(su == 21)
		{
			printf("4\n");
		}
		else
			printf("0\n");
	}
return 0;	
}
