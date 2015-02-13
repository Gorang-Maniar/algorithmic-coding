#include<stdio.h>
#include<math.h>
long long int power(int a, int b)
{
	long long int c=1,temp=1000000000000000,m=(2*b)+1;
	while(b!=0)
	{
		c=c*a;
	/*	if((c/temp)!=0)
		{
			
			while((c/temp)!=0)
			{
				long long int p=c/temp;
				c = c%temp;
				p = p%m;
				p = p*temp;
				c = c+p;
			}
		}*/
		b--;
	}
	printf("c=%lld\n",c);
	return c;
}
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int a,m;
		long long int ans;
		scanf("%d %d",&a,&m);
		ans=power(a,(m-1)/2);
			printf("ans=%lld\n",ans);
//		if(ans/temp==0)
			ans=(ans-1)%m;
			if(ans==0)
				printf("YES\n");
			else
				printf("NO\n");
	/*	else
		{
			while(ans/temp==0)
			{
				long long int p=ans/temp;
				p = p%m;
				p = p*temp;
				ans = ans+p;
			}
			ans=(ans-1)%m;
			if(ans==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
*/
	}
	return 0;
}
