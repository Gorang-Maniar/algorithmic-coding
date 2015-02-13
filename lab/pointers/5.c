/*2d array*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[2][2],i,j;
	int *ptr;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	}
	
//	ptr=a;

	for(i=0;i<2;i++)
	{
		ptr=a[i];
		for(j=0;j<2;j++)
		{
			//	printf("%d\n",ptr[i][j]);
			//printf("%d\n",*((*(ptr+i)+j)));
			printf("%d\n",*(ptr+j));
		}
	}
	return 0;
}
