/*calculate (a^n)%m */
#include<stdio.h>
int pow(a,n,m)
{
	int ans;
	if(n==0)
		return 1;
	else
	{
		ans=(a*pow(a,n-1,m))%m;
		return ans;
	}
}
int main()
{
	int a,n,m,f;
scanf("%d%d%d",&a,&n,&m);
	f=pow(a,n,m);
	printf("%d\n",f);
	return 0;
}
