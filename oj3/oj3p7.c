#include<stdio.h>
int main()
{
	long long int p,q;
	scanf("%lld",&q);
	for(p=0;p<q;p++)
	{
	int i,j,f,c[10000]={0},s,count1=0,count2=0;
	char inp[10000],test[1000];
	scanf("%s%s",inp,test);
	while(inp[count1]!='\0')
		count1++;
	while(test[count2]!='\0')
		count2++;
	for(i=0;i<count1;i++)
	{
		if(inp[i]==test[0])
		{
			f=0;
			for(j=0;j<count2;j++)
			{
				if(inp[j+i]==test[j])
				{f++;}
			
				else
					break;
			}	
		
	

		if(f==count2)
		{	for(s=i;s<i+count2;s++)
			{
				c[s]=1;
			}
		}
		}
	}
		for(i=0;i<count1;i++)
		{
			if(c[i]==0)
				printf("%c",inp[i]);
			
		}
		printf("\n");
	}
	return 0;
}
