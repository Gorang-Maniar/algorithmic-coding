/* print array using pointers*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[5],i;
	int *ptr;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	ptr=a;
	for(i=0;i<5;i++)
		
		printf("%d",*(ptr+i));
	for(i=0;i<5;i++)
		printf("%d\n",ptr[i]);
	

	/*printf("%d\n",ptr);this prints address of a;
	printf("%d\n",(ptr+1));address of a gets incremented by 4
*/
	return 0;
}
