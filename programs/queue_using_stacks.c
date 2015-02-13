//queue using stacks
#include<stdio.h>
int main()
{
	int a[1000],b[1000],n,o,i,z,j,k;
	i=0;
	printf("PRESS 1 FOR PUSH\nPRESS 2 FOR POP\nPRESS 3 FOR PRINTING THE NUMBERS\n");
	while(scanf("%d",&n)!=EOF)
	{
		//scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&o);
			a[i]=o;
			i++;
		}
		else if(n==2)
		{
			i--;
			j=0;
			while(i>0)
			{
				b[j]=a[i];
				i--;
				j++;
			}
			printf("%d\n"a[i]);
			j--;
			i=0;
			while(j>=0)
			{
			
				a[i]=b[j];
				i++;
				j--;
			}
		}
		else if(n==3)
		{
			for(k=0;k<i;k++)
			{
				printf("%d ",a[k]);
			}
			printf("\n");
		}
		else
			printf("INVALID INPUT\n");
	}
	return 0;
}
