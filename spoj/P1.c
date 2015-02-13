#include<stdio.h>
int main()
{
	int a,i;
	for(i=0;;i++)
	{
		scanf("%d",&a);
		if(a==42)
			return;
		else
			printf("%d\n",a);
	}
	return 0;
}


