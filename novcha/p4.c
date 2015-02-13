//Chef and Segment Game
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
		long long int x,k;
		scanf("%lld %lld",&x,&k);
		if(k==1){
			double ans = x/2;
			printf("%lf\n",ans);
		}
		else{
			int i=0,p,d,m;
			double t=k,a=k,y=x,z;
			double ans;
		while(t!=0){
			t=t/2;
			i++;
		}
		p = power(2,i);
		double s =p;
		d = a-(p/2);
		m = power(2,d)+1;
		z = m;
		ans = (y/s)*z;
		printf("i=%d p=%d d=%d m=%d ans=%lf\n",i,p,d,m,ans);
		}
	}
	return 0;
}

