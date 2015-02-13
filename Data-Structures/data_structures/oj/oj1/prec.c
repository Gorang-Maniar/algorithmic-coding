#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int len=0,j,a,w,c=0,k=0,q,t;

		char st[101]={0},inp[101],ans[101]={0};
		st[c] = 0;
		c++;
		/*		while((t=getchar())!='\n'){
				inp[q] = t;
				q++;
				}
		 */scanf("%s",inp);
		len = strlen(inp);
		//	while(inp[len]!='\n')
		//		len++;
		for(j=len-1;j>=0;j--)
		{
			if(inp[j] >= '0' && inp[j] <= '9')
				//		printf("%c",inp[j]);
			{
				ans[a] = inp[j];
				a++;
			}
			else if(inp[j] == '*' || inp[j] == '/')
			{
				if(st[c-1] == '^')
				{
					//			printf("%c",st[c-1]);
					ans[a] = st[c-1];
					a++;
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
							//	printf("%c",st[c-1]);
							ans[a] = st[c-1];
							a++;
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
		for(k=c;k>=1;k--){
			ans[a]=st[k];
			a++;
		}
		for(w=a-1;a>=0;a--)
			printf("%c",ans[w]);

		printf("\n");
	}
	return 0;
}
