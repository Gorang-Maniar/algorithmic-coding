/* print digits of input number */
#include<stdio.h>
void digits(int a)
{int b;
	if(a==0)
	return;
	else
	{
		b=a%10;
		a=a/10;
		digits(a);
		printf("%d ",b);
	
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	digits(a);
printf("\n");
	return 0;
}

