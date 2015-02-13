#include<stdio.h>
int main()
{
	int s,i,j,temp,a[200000];
	scanf("%d",&s);
	for(i=0;i<s;i++)
		a[i] = rand()%1000000+1;
	for(i=0;i<s;i++){
		for(j=i+1;j<s;j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(i=0;i<s;i++)
		printf("%d",a[i]);
	return 0;
}


