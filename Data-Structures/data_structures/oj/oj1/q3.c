#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char st[1000];
		char inp[1000];
		int temp[1000];
		int q,len,j,l=0,fl=0,top=-1;
		scanf("%s",st);
		len = strlen(st);
		for(q=0;q<len;q++)
			inp[q] = st[q];
		for(l=len-1;l>=len-2;l--){
			if(inp[l]>='0' && inp[l]<='9')
				continue;
			else{
				printf("invalid\n");
				fl=1;
				break;
			}
		}
		if(fl==0)
		{
		for(j=len-1;j>=0;j--){

		if(inp[j]>='0' && inp[j]<='9')
		{
			top++;
			temp[top]=((int)inp[j])-48;
		}
		else if(inp[j]=='*')
		{
			temp[top-1] = temp[top] * temp[top-1];
			temp[top] = '\0';
			top--;
		}
		else if(inp[j]=='/')
		{
			if(inp[top-1]==0){
				fl = 1;
				printf("invalid\n %d",top);
			}
			else{
				temp[top-1] = (temp[top])/(temp[top-1]);
				temp[top] = '\0';
				top--;
			}
		}
		else if(inp[j]=='+'){
			temp[top-1] = temp[top] + temp[top-1];
			temp[top] = '\0';
			top--;
		}
		else if(inp[j]=='-'){
			temp[top-1] = temp[top] - temp[top-1];
			temp[top] = '\0';
			top--;
		}
		else if(inp[j]=='^'){
			temp[top-1] = pow(temp[top], temp[top-1]);
			temp[top] = '\0';
			top--;
		}


		}

		}
		if(fl==0)
			printf("%d\n",temp[top]);
	}
	return 0;
}
