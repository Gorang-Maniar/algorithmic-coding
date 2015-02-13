#include<stdio.h>
#include<string.h>
/*int stringcmp(char str1[],char str2[])
  {
  int i=0,f=0;
  while(str1[i]!='\0' && str2[i]!='\0')
  {
  if(str1[i] != str2[i])
  {
  f=1;
  break;
  }
  i++;
  }
  if(f==0 && str1[i]=='\0' && str2[i]=='\0')
  return 1;
  else
  return 0;
  }*/


void stringcpy(char str2[],char str1[])
{
	int i=0;
	while(str1[i]!='\0')
	{
		str2[i]=str1[i];
		i++;
	}

	str2[i]='\0';
}


int main()
{
	int x,i,j,k,ct,d,len=0,p,b;
	char inp[1000],temp[1000],answer[1000];
	while(scanf("%s",inp)!=EOF)
	{

	while(inp[len]!='\0')
	{len++;}

	p=0;
	x=0;
	for(i=0;i<len;i++)
	{

		for(j=i;inp[i+j]!='\0';j++)
		{
			ct=0;
			d=0;

			for(k=i;k<=j;k++)
			{

				if(inp[k]!=inp[i+j-k])
				{	ct++;
					break;
				}


			}

			if(ct==0)
			{


				for(k=i;k<=j;k++)
				{	temp[d]=inp[k];
					d++;
				}
				temp[d]='\0';
			}
			
			
				if(x==0)
				{
					stringcpy(answer,temp);
					x=1;
					p=d;
				}
			
			else
			{
				if(d>=p)
				{
				if(d==p)
				{
					if(strcmp(answer,temp)>0)
					
					{	
						stringcpy(answer,temp);
						p=d;
					}
				}
				else
				{
					stringcpy(answer,temp);
					p=d;
				}
				}
			}
		}
	}
	printf("%s\n",answer);
	}

	return 0;
}
