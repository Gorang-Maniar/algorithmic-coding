
#include<stdio.h>
#include<stdlib.h>

int main(){
	int inp[100000];
	FILE * input;
input = fopen("words","r");
if(input == (FILE*) NULL)
{
	printf("can't open\n");
	exit(EXIT_FAILURE);
}
else{
	for(i=0;i<99172;i++)
	{
		fscanf(input, "%f", &inp[i]);
	}

}
exit(EXIT_SUCCESS);
}
