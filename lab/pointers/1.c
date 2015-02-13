/*pointers intro*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=15;
	int *ptr;
ptr=&a;
printf("%d\n",*ptr);

int **ptr2;
ptr2=&ptr;
printf("%d\n",*(*ptr2));

	return 0;
}
