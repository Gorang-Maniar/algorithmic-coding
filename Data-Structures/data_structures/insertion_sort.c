#include<stdio.h>
int main(){

	int i,j,s,temp,a[1000000];

//	printf("Enter total elements: ");
	scanf("%d",&s);

//	printf("Enter %d elements: ",s);
	for(i=0;i<s;i++)
	//	scanf("%d",&a[i]);
		a[i] = rand()%1000000+1;
	for(i=1;i<s;i++){
		temp=a[i];
		j=i-1;
		while((temp<a[j])&&(j>=0)){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}

//	printf("After sorting: ");
	for(i=0;i<s;i++)
		printf(" %d",a[i]);

	return 0;
}
