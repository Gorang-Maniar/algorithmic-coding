#include<stdio.h>
int main(){
	int s,temp,i,j,a[100000];
	scanf("%d",&s);
	for(i=0;i<s;i++)
		a[i] = rand()%100000+1;
	for(i=s-2;i>=0;i--)
	{
		for(j=0;j<=i;j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(i=0;i<s;i++)
		printf("%d ",a[i]);
	return 0;
}
