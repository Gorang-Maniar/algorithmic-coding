/* add to num using recursions */
#include<stdio.h>
int add(int a,int b)
{
	static int c=0;

	if(c==b)
		return a;
	else
	{
		c++;
		a++;
		add(a,b);
	}
}
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=add(a,b);
	printf("%d\n",c);
	return 0;
}
