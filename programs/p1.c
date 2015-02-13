#include<stdio.h>
int main()
{
	long long int i,k,m,n,count1,count2,p,a,j,b,temp=0,car=0,pro[40002];
	char inp1[10000],inp2[10000];
	scanf("%lld",&n);
	for(m=0;m<n;m++)
	{
		count1=0;
		count2=0;
		scanf("%s%s",inp1,inp2);
		while(inp1[count1]!='\0')
			count1++;
		while(inp2[count2]!='\0')
			count2++;
	
		//for(i=0;i<count1;i++)

			a=0;
			if(inp1[0]=='-')
			{
			for(i=0;i<count1-1;i++)
				inp1[i]=inp1[i+1];
			count1--;
			a=1;
			
			}
			
		
	//	for(i=0;i<count2;i++)
	
			b=0;
			if(inp2[0]=='-')
			{
		for(i=0;i<count2-1;i++)
				inp2[i]=inp2[i+1];

				count2=count2-1;
				b=1;
			}
			for(i=0;i<count1;i++)
			     inp1[i]=inp1[i]-48;
			for(i=0;i<count2;i++)
			     inp2[i]=inp2[i]-48;

		
		for(p=0;p<(count1+count2);p++)
		pro[p]=0;
		for(i=(count1-1);i>=0;i--)
		{
			for(j=(count2-1);j>=0;j--)
				pro[i+j]+=inp1[count1-1-i]*inp2[count2-1-j];
		}
		temp=0;
		car=0;
		for(k=0;k<=count1+count2-2;k++)
		{
			temp=pro[k];
			pro[k]=(pro[k]+car)%10;
			car=(temp+car)/10;
			
		}
		
		i=0;
		if(car==0 && pro[k-1]==0)
		{
			printf("0");
		}
		else
		{
		if(car==0)
		{
			if(a!=b)
				printf("-");
			for(i=(count1+count2-2);i>=0;i--)
			printf("%lld",pro[i]);

		}
		else 
		{	
			if(a!=b)
			printf("-");
			printf("%lld",car);
		for(i=(count1+count2-2);i>=0;i--)
		printf("%lld",pro[i]);
		}
		}
		printf("\n");
	}
	return 0;
}


