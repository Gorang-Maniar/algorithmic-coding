#include <stdio.h>
extern void displayData(int *array, int size);
void displayData(int *array, int size)
{
 int i;
	for(i=0; i< size; ++i)
	{
		printf("%d\n", array[i]);
	}
}
