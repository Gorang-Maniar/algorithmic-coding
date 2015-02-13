#include<stdio.h>
int main()
{
	int q,t,ct=0;
	scanf("%d",&q);
	for(t=0;t<q;t++)
	{
		char str[10];
		scanf("%s",str);
		if(str[1]=='i')
		{
			ct++;
		}
		else if(str[1]=='b')
		{
			if(str[3]>str[5])
			{
				
