#include<stdio.h>
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int n,p;
		char s[5];
		scanf("%d %s %d",&n,s,&p);
		if(s[0]=='o')
		{
			printf("%d\n",(2*p));
		}
		else
		{
			printf("%d\n",(2*p)-1);
		}
	}
	return 0;
}
