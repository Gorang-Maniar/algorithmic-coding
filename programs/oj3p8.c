#include<stdio.h>
int main()
{
long long int p,q,k,j;
scanf("%lld",&q);
for(p=0;p<q;p++)
{
int i,j,f,c[10000]={0},s,count1=0,count2=0;
char inp[10000],test[1000];
scanf("%s %s",inp,test);
while(inp[count1]!='\0')
	count1++;
while(test[count2]!='\0')
	count2++;
for(i=0;i<count1;i++)
{
	if(inp[i]==test[0] || inp[i]=='?')
	{
		f=0;
		for(j=0;j<count2;j++)
		{
			if(inp[j+i]==test[j] || inp[j+i]=='?')
			{
				//printf("i+j value is %lld, j value is %lld %c %c\n",(i+j),j,test[j],inp[j+i]);
				f++;
			}
			else
				break;
		}
		if(f==count2)
		{
			for(s=0,k=i;s<count2;s++,k++)
			{
				inp[k]=test[s];
				//printf("inp[k] is %c and test[s] is %c,s is %lld,i is %lld\n",inp[k],test[s],s,i);
			}
		}
	}
}
for(j=0;j<count1;j++)
{
	if(inp[j]=='?')
		inp[j]='*';
}
for(k=0;k<count1;k++)
printf("%c",inp[k]);
printf("\n");
}
return 0;
}
