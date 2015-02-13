#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int len,c=0,k=0;

		char j,inp[100], st[100]={0}, ans[100]={0};
		st[c] = 0;
		c++;
		scanf("%s",inp);
		len = strlen(inp);
		for(j=0;j<len;j++)
		{
			if(inp[j] >= 'a' && inp[j] <= 'z')
				printf("%c",inp[j]);
			else if(inp[j] == '*' || inp[j] == '/')
			{
				if(st[c-1] == '^')
				{
					printf("%c",st[c-1]);
					c--;
					st[c]=inp[j];
				}
				else
				{
					st[c]= inp[j];
					c++;
				}
			}


			else if (inp[j] == '+' || inp[j] == '-')
			{
				if(st[c-1] == '*' || st[c-1] == '/' || st[c-1] == '^')
				{
					while(c>0)
					{
						if(st[c-1] == '*' || st[c-1] == '/' || st[c-1] == '^')
						{
							printf("%c",st[c-1]);
							c--;
						}
						else 
							break;
					}
					st[c]=inp[j];
					c++;
				}
				else if(inp[j] == '-' && st[c-1]=='-')
				{
					st[c] = '+';
					c++;

				}
				else

				{
					st[c] = inp[j];
					c++;
				}
			}
			else if(inp[j] == '^')
			{
				st[c] = inp[j];
				c++;
			}
		}
		c--;
		for(k=c;k>=1;k--)
			printf("%c",st[k]);
		printf("\n");
	}


	return 0;
}
