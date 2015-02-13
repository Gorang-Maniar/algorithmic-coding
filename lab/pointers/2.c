/*size of ptr & printing address of a*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int a;
	a=5;
	ptr=&a;
	printf("%d\n",sizeof ptr);
	printf("%p\n",ptr);


	return 0;
}
