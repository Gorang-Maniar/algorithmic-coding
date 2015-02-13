#include<stdio.h>
int count;
int power(int n,int i)
{
	if(i==0)
		return 1;
	int r,h;
	h=n;
	for(r=0;r<i-1;r++)
	{
		n=n*h;
	}
	return n;
}

void ans(long long int c,int m,int l)
{
	int d=0,j=1;
	while(d!=c)
	{
		d = c%(power(10,j));
		if(d%m == l)
		{
			if(d!=0)
		//	printf("%d\n",d);
			count++;
		}
		j++;
	}
}
int main()
{
	long long int n;
	int i,q;
	scanf("%lld",&n);
	scanf("%d",&q);
	if(n<0)
		n=-n;
	for(i=0;i<q;i++)
	{
		count=0;
		int m,l;
		scanf("%d %d",&m,&l);
		long long int c =n;
		while(c!=0)
		{
			ans(c,m,l);
			c = c/10;
		}
		printf("%d\n",count);

	}
	return 0;
}

