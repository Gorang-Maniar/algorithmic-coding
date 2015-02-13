//Distinct characters subsequence
#include<stdio.h>
#include<string.h>
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		char str[100004];
		scanf("%s",str);
		int arr[27]={0},len,i,count=0;
		len = strlen(str);
		for(i=0;i<len;i++)
		{
			if(arr[str[i]-97]!=1)
			{
				arr[str[i]-97]=1;
				count++;
			}
		}
		printf("%d\n",count);
	}
}

