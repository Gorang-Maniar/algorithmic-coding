/*command line arguments*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	int i;
printf("%d\n",argc);
for(i=0;i<argc;i++)
	printf("%s\n",*argv++);

	return 0;
}
