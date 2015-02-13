#include<stdio.h>
void array(int a[],int m)
{
	int i;
	
	for(i=0;i<m;i++)
	{printf("%d ",a[i]);}
	printf("\n");
}
int main()
{
	int m,i;
	scanf("%d",&m);
	int a[m];
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	array(a,m);
	return 0;
}

