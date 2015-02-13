#include<stdio.h>
int main()
{
int i,j,x,p,q,n,count,dcon=0,a[500];
scanf("%d",&p);
for(q=0;q<p;q++)
{
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%d",&a[i]);
count=0;
for(i=0;i<n;i++)
{
dcon=0;
for(j=i+1;j<n;j++)
{if(a[j]>a[i])
for(x=j-1;x>=0;x--)
{if(a[j]>a[x])
dcon++;
}
}
if(dcon>=count)
count=dcon;
}
printf("%d\n",count);
}
return 0;
}
