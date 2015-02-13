/*count no. of digits in a no. */
#include<stdio.h>
int c=0;
int count(int a)
{
	if(a==0)
		return 0;
	else
	{
		count(a/10);
	c++;
	}
	return c;
}
int main()
{
	int a,b,c;
	scanf("%d %d",&a,&b);
		c=count(a);
	if(a==0 && b==0)
		printf("0\n");
	else if(a==0 && b==1)
		printf("1\n");
	else if(c==b)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
