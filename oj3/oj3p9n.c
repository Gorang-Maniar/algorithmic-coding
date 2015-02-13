#include<stdio.h>
#include<string.h>
int main()
{
	int p,q;
	scanf("%d",&p);
	for(q=0;q<p;q++)
	{
	int i,j,n,flag;
	char inp[2000],test[2000],temp[4000];
	scanf("%s",inp);
	n=strlen(inp);
	i=0;
	while(i<(2*n))
	{
		for(j=0;j<n;j++)
		{
	temp[i]=inp[j];
	i++;
	}
	}
	scanf("%s",test);
	for(i=0;i<2*n;i++)
	{
		if(temp[i]==test[0])
		{
			flag=1;
			for(j=0;j<n;j++)
		{	//printf("%c %c\n",temp[i+j],test[j]);
			if(temp[i+j]!=test[j])
			{flag=0;
				break;}
		}
		}

		if(flag==1)
			break;
	}


	if(flag==1)

		printf("YES\n");
	else
		printf("NO\n");


	}
	return 0;
}
