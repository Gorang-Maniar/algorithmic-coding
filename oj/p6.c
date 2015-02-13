#include<stdio.h>
int main()
{
	int p,q;
long long int i,n,a,b,c,d=0;
scanf("%lld",&n);  
for(i=0;i<n;i++)
  
  {
          scanf("%lld %lld %lld %d",&a,&b,&c,&p);
  if(p==1)
  {	  printf("%lld\n",a);
	  }
  else if(p==2)
  {	  
	  printf("%lld\n",b);
  }
  else if(p==3)
  {	
	  printf("%lld\n",c);
	  }
  else
  {
	  for(q=1;q<=p-3;q++)
          {
  d=a+b+c;
  a=b;
  b=c;
	  c=d;
      
	  }          
          printf("%lld\n",d);
d=0;
  }
  }
  return 0;
}
