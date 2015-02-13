/* reverse string */
#include<stdio.h>
#include<string.h>
void rev(char s[], int len)
{
	int i,c,j;
	j=len-(i+1);
	if(i<j)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		i++;
		rev(s,len);
		
	}
}
int main()
{
	char s[1000],p[1000];
	int len;
	scanf("%s",s);
	len=strlen(s);
	rev(s,len);

	return 0;
}
