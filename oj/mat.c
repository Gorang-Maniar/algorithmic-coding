#include<stdio.h>
int main()
{
	int m,n,i,j,col;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	scanf("%d",&col);
	{	for(i=0;i<m;i++)
			printf("%d",a[i][col-1]);
printf("\n");
		}
if(col>m)
	printf("error\n");
	
	return 0;
}
