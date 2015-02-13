//stacks using queues
#include<stdio.h>
int main()
{
	int a[1000],o,i,n,z,j,k;
	i=0;
	printf("PRESS 1 FOR ENQUEUE\nPRESS 2 FOR DEQUEUE\nPRESS 3 TO PRINT THE NUMBERS\n");
	while(scanf("%d",&o)!=EOF)
	{
		if(o==1)
		{
			scanf("%d",&n);
			a[i]=n;
			i++;
		}
		else if(o==2)
		{
			for(j=0;j<i-1;j++)
			{
				z=a[0];
				for(k=0;k<(i-1);k++)
					a[k]=a[k+1];
				a[k]=z;
				//for(k=0;k<i;k++)
				//	printf("%d ",a[k]);
				//printf("\n");
				
			}
			printf("%d\n",a[0]);
			for(k=0;k<i-1;k++)
			{
				a[k]=a[k+1];
			}
			i--;
		}
		else if(o==3)
		{
			for(j=0;j<i;j++)
				printf("%d ",a[j]);
			printf("\n");
		}
		else
			printf("INVALID INPUT\n");
	}
	return 0;
}
