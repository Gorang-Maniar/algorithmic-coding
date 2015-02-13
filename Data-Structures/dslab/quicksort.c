//implementing quicksort
#include<stdio.h>
int a[100];
void quicksort(int first,int last)
{
	int high,low,temp,x;
	if(first<last)
	{
		high=last;
		low=first;
		x=first;
		while(high>low)
		{
			while((a[low]<=a[x])&&(high>low))
				low++;
			while(a[high]>a[x])
				high--;
			if(low<high)
			{
				temp=a[low];
				a[low]=a[high];
				a[high]=temp;
			}
		}
		temp=a[x];
		a[x]=a[high];
		a[high]=temp;
		quicksort(first,high-1);
		quicksort(high+1,last);
	}
}
int main()
{
	int i,n;
	printf("ENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER\n");
	scanf("%d",&n);
	printf("ENTER %d ELEMENTS\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
