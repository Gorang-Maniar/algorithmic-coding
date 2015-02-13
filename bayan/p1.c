#include<stdio.h>
#include<string.h>
int main()
{
	int q,t;
	scanf("%d",&t);
	for(q=0;q<t;q++){
		char arr[6];
		scanf("%s",arr);
		int i,n;
		n = strlen(arr);
		for(i=n-1;i>=0;i--)
			printf("%c",arr[i]);
		printf("\n");
	}
	return 0;
}
