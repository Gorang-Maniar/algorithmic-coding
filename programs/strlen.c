#include<stdio.h>
int mystrlen(char a[])
{
	int count=0,i=0;
	while(a[i]!='\0')
	{
		count++;
		i++;
	}
	return count;

}
int main()
{
	int c;
	char s[100];
	scanf("%s",s);
	c=mystrlen(s);
	printf("%d\n",c);
	return 0;
}

