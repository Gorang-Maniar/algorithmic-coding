#include <stdlib.h>
#include <stdio.h>
extern void initializeData(int *array, int size);
void initializeData(int *array, int size)
{
 int i;
	srand(time(NULL));
	for(i=0; i<size; ++i)
	{
		array[i] = rand()%20;
	}
	
	for(i=0; i< size; ++i)
	{
		printf("%d\n", array[i]);
	}
	printf("===\n");
}
