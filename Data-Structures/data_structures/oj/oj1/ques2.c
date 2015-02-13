#include<stdio.h>
#include<string.h>
int rank(char ch)
{
	if(ch=='(' || ch==')')
		return 6;
	else if(ch=='^')
		return 2;
	else if(ch=='/' || ch=='*')
		return 3;
	else if(ch=='+' || ch=='-')
		return 4;
	else 
		return 5;
}
void rev(char arr[], int l){
	int a,temp;
	for(a=0;a<l/2;a++)
	{
		temp = arr[a];
		arr[a] = arr[l-a-1];
		arr[l-a-1] = temp;

	}
}

int valid(char str[], int l){
	int a;
	for(a=0;a<l-1;a++){
		if(str[a] >= '0' && str[a] <='9')
		{
			if(str[a+1]>='0' && str[a+1] <='9')
				return 1;
		}
		else if(str[a] == '+' || str[a] == '-' || str[a] == '*' || str[a] == '/' || str[a] == '^')
		{
			if(str[a+1] == '+' || str[a+1] == '-' || str[a+1] == '*' || str[a+1] == '/' || str[a+1] == '^')
				return 1;
		}
	}
	return 0;
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char inp[1000],stack[1000]={0},ans[1000]={0};
		int c=0,v=0,q,k,len,w=0,l,x=0;
		stack[c]=0;
		c++;
		scanf("%s",inp);
		len = strlen(inp);
		rev(inp,len);
		v=valid(inp,len);
		if(v==0)
		{
			for(q=0;q<len;q++)
			{
				if(inp[q]>='0' && inp[q]<='9')
				{
					ans[w] = inp[q];
					w++;
				}
				else if(inp[q] == '(' || inp[q] == ')')
				{
					if(inp[q] == ')')
					{
						stack[c] = inp[q];
						c++;
					}
					else if(inp[q] == '(')
					{
						while(stack[c-1]!=')')
						{
							ans[w] = stack[c-1];
							w++;
							c--;
						}
						c--;
					}
				}
				else if(inp[q] == '*' || inp[q] == '/')

				{
					if(rank(inp[q])>rank(stack[c-1]))
					{
						while(c>0){
							if(rank(inp[q])>rank(stack[c-1]))
							{
								ans[w] = stack[c-1];
								w++;
								c--;
							}
							else 
								break;
						}
						stack[c]=inp[q];
						c++;
					}
					else
					{
						stack[c] = inp[q];
						c++;
					}
				}

				else if(inp[q] == '+' || inp[q]=='-')
				{
					if(rank(inp[q])>rank(stack[c-1]))
					{
						while(c>0){
							if(rank(inp[q])>rank(stack[c-1]))
							{
								ans[w] = stack[c-1];
								w++;
								c--;

							}
							else
								break;
						}
						stack[c] = inp[q];
						c++;
					}
					else{
						stack[c] = inp[q];
						c++;
					}

				}
				else if(inp[q] == '^')
				{
					if(rank(inp[q])>=rank(stack[c-1]))
					{
						while(c>0){
							if(rank(inp[q])>=rank(stack[c-1]))
							{
								ans[w] = stack[c-1];
								w++;
								c--;

							}
							else
								break;
						}
						stack[c] = inp[q];
						c++;
					}
					else{
						stack[c] = inp[q];
						c++;
					}

				}
			}
		
		c--;
		for(k=c;k>=1;k--)
		{
			ans[w] = stack[k];
			w++;
		}
		l=strlen(ans);
		rev(ans,l);
		for(x=0;x<l;x++)
			printf("%c",ans[x]);
		printf("\n");
		}
		else 
			printf("invalid\n");
	}
	return 0;
}







