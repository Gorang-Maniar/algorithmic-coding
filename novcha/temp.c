#include<stdio.h>
int power(int x,int y) {
	if(y == 0)
		return 1;

	int d = power(x, y/2);

	if(y%2 == 0)
		return (d*d)%10;
	else
		return (x*d*d)%10;
}
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int n,m,q,i,j,r,w;
		scanf("%d %d %d",&n,&m,&q);
		for(j=0;j<q;j++)
		{
		int f=1,f1=1,ans=0;
			scanf("%d",&r);
			if(r<=n/2)
			{
				r = n-r;
			}

			for(i=r+1;i<=n;i++)
			{
				w = i%10;
				f = f*power(w,w);
			}
			for(i=2;i<=n-r;i++)
			{
				w = i%10;
				f1 = f1*power(w,w);
			}
			ans = f/f1;
			printf("%d\n",ans%m);
		}
	}
	return 0;
}
