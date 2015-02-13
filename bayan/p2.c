#include<stdio.h>
#include<string.h>
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int n,i,count=0;
		char name[100];
		scanf("%s",name);
		n = strlen(name);
		for(i=0;i<n;i++)
		{
			if(name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u')
				count++;
		}
		if(count%2==0)
			printf("DOKHTAR\n");
		else
			printf("PESAR\n");
	}
	return 0;
}
