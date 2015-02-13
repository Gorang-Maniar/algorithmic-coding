//Let us construct palindrome
#include<stdio.h>
#include<string.h>
int palindrome(char str[],int s,int e)
{
	int i,fl=0,j=0;
	for(i=s;i<=(s+e)/2;i++)
	{
		if(str[i] != str[e-j])
		{
			fl=1;
			return 1;
		}
		j++;
	}
	return 0;
}
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		char s[100005];
		scanf("%s",s);
		int len,i,ans=0,flag=0;
		len = strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]!=s[len-1-i])
			{
				ans=4;
				break;
			}
		}
		if(ans==0)
			printf("YES\n");
		else{
			for(i=0;i<len;i++)
			{
				if(s[i]!=s[len-i-1])
				{
					if(s[i+1]==s[len-i-1])
					{
						if(i+2>=len-i-2)
							flag=2;
						else{
						ans = palindrome(s,i+2,len-i-2);
						if(ans==1)
							flag=1;
						else
							flag=2;
						}
					} 
					if(s[i]==s[len-i-2])
					{
						if(i+1>=len-i-3)
							flag=2;
						else{
						ans = palindrome(s,i+1,len-i-3);
						if(ans==1)
							flag=1;
						else
							flag=2;
						}
					}
						if(flag==1)
						{
							printf("NO\n");
							break;
						}

						else if(flag==2)
						{
							printf("YES\n");
							break;
						}
					else
					{
						printf("NO\n");
						break;
					}
				}
			}
		}
	}
	return 0;
}


