/* pointers to array*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr1,*ptr2,*ptr3;
	int a[5],i;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	ptr1=a;
	ptr2=&a;
	ptr3=&a[0];
//	ptr4=a[0];it points to value of a[0] and printing its pointers would try to print data at that value hence gives seg fault.
	printf("%d\n%d\n%d\n",*ptr1,*ptr2,*ptr3);

	return 0;
}
