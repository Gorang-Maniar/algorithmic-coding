#include<stdio.h>
int main()
{
	int m,n,i,j,ser;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[m][n]);
	}
	scanf("%d",&ser);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	if(a[i][j]==ser)
			printf("found\n%d%d\n",i,j);
			else
				printf("not found\n");
		}
	}
return 0;
}
