#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,s=0,r,u,t,v,a,w,b,reverse=0,count=0,rem,temp,f,i,p;
	double ratio;
		

	
		while(scanf("%lld",&n)!=EOF)
		{
		if(n==0)
		{
			printf("YES\n");
			printf("0\n");
		}
		else
		{
		temp=n;
		reverse=0;
		while(temp!=0)
		{
			rem=temp%10;
			reverse=reverse*10+rem;
			temp/=10;
		}
		if(reverse!=n)
			printf("NO\n");
		else if(reverse==n)
		{	printf("YES\n");	
		count=0;
			a=n;
			while(a)
			{
				a=a/10;
				count++;
			}
				if((count%2)!=0)
				{
					s=0;
					b=n;
					while(b)
					{
						r=b%10;
						s=s+r;
						b=b/10;
						
					}
					printf("%lld\n",s);
				}
				else if((count%2)==0)
				{
					u=count/2;
					t=pow(10,u);
					v=n/(long long int)t;
					w=n%(long long int)t;
					if(w==0)
						printf("0.00\n");
					else
						ratio=(double)v/w;
					printf("%.2lf\n",ratio);
				}
			}
		}		
	}
	
	return 0;
}
