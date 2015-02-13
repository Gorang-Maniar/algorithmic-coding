#include<stdio.h>
int main()
{
long long int i,n,p,q,r,s,t,a;
scanf("%lld",&n);
for(i=0;i<n;i++)
{
scanf("%lld",&p);
q=p/9;
r=p-9*q;
t=0;
for(a=1;a<=r;a++)
{
t=t+(2*a-1); 
}
s=(9*q*9*q)+t;
printf("%lld\n",t);
}
return 0;
}
