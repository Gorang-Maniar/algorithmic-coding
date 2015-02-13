#include<stdio.h>
long long int expo(int base,int exponent)
{
	long long int value;

	if (exponent == 0) {
		value = 1;
	} else {
		value = expo(base * base,exponent/2);
		if (exponent & 1) {
			value *= base;
		}
	}
	return value;
}
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		long double x,k;
		scanf("%Lf %Lf",&x,&k);
		if(k==1)
			printf("%Lf\n",x/2);
		else{
			int ct=0;
			long long int p=k;
			while(p!=0){
				p=p/2;
				ct++;
			}
			long double ex = expo(2,ct);
			double mul = 2*(k-(expo(2,ct-1)))+1;
			long double ans = (x/ex)*mul;
			printf("%Lf\n",ans);
		}
	}
	return 0;
}

