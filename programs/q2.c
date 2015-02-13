#include<string.h>
#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char inp[101],temp[101]={0},out[101]={0};
		int len,j,c,p,x;
		scanf("%s",inp);
		len = strlen(inp);
			c=0;
		for(j=len-1;j>=0;j--){
			if(inp[j]>=0 && inp[j]<10){
				out[p] = inp[j];
				p++;
			}
			else if(inp[j] == '+' || '-'){
				while(temp[c] != '-' && temp[c]!= '+'&& c!=-1){
					out[p] = temp[c];
				//	temp[c] = 0;
					c--;
					p++;
				}
				c++;
				temp[c] = inp[j];
				c++;
			}
			
			else if(inp[j] == '*' || '/' ){
				while(temp[c] != '^' && temp[c]!= '(' && temp[c]!= ')' ){
					out[p] = temp[c];
					c--;
					p++;
				}
				c++;
				temp[c] = inp[j];
				c++;
			}
			else if(inp[j] == '^'){
				while(temp[c] != '(' || ')' ){
					out[p] = temp[c];
					c--;
					p++;
				}
				c++;
				temp[c] = inp[j];
				c++;
			}
			else if(inp[j] == ')'){ 
				temp[c] = inp[j];
				c++;
			}
			else if(inp[j] == '('){
				while(temp[c] != ')'){
					out[p] = temp[c];
					c--;
					p++;
				}
				c--;
			}
		}
		while(c!=-1){
		out[p] = temp[c];
		c--;
		p++;
		}
		for(x=p-1;x>=0;x--)
			printf("%c",out[x]);
			printf("\n");
	}
	return 0;
}
				

				


				

