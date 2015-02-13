#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long long int a,b,c,i,j,arra[100],k,arrb[100],reva[100],revb[100],sum1,sum2;
	while((scanf("%llu%llu",&a,&b))!=EOF)
	{	
	while(a!=0)
	for(i=0;i<32;i++)
	{
		arra[i]=a%2;
		arrb[i]=b%2;
			a=a/2;
			b=b/2;
	}
	sum1=0;
	sum2=0;
	for(k=0;k<32;k++)
	{
		sum1=sum1+arra[k]*pow(2,31-k);
		sum2=sum2+arrb[k]*pow(2,31-k);
	}	
	c=sum1+sum2;
	printf("%llu\n",c);
	}
	return 0;
}
