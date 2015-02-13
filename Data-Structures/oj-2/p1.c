#include<stdio.h>

int matrioska(int arr[],int val,int a);
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int arr[1000]={0};
		int j,num,a,val,cal,f=0;
		scanf("%d",&num);
		for(j=0;j<num;j++)
			scanf("%d",&arr[j]);
		int frs=(-1)*(arr[0]);
		for(j=0;j<num;j++)
		{
			if(arr[j]==frs && arr[j+1]!=0)
			{
				f=1;
			}
		}
		for(a=0;a<j;a++)
		{
			if(num%2!=0)
			{
				f=1;
				break;
			}
			else if(arr[0]>=0)
			{
				f=1;
				break;
			}
			if(arr[a]<0)
			{
				if(arr[0]>arr[1])
				{
					f=1;
					break;
				}
				val=(-1)*(arr[a]);
				cal=matrioska(arr,val,a);
				if(cal==1){
					f=1;
					break;
				}
			}
		}
		if(f==1)
			printf(":-( Try again.\n");
		else
			printf(":-) Matrioshka!\n");
//		arr[]={0};
	}
	return 0;
}
int matrioska(int arr[],int val,int a)
{
	int ptr=a+1;
	int value=(-1)*(arr[ptr]);
	int var = value;
	int flag=0;
	while(arr[a]!=val)
	{
		if(arr[a]==val)
			break;
		else if(arr[a]>value)
		{
			flag=1;
			break;
		}
		else if(arr[a]==value)
		{
			if(arr[a+1]!=val)
			{
				value=(-1)*(arr[a+1]);
				var=var+value;
				if(var>=val)
				{
					flag=1;
					break;
				}
			}
		}
		a++;
	}
	if(flag==1)
		return 1;
	else
		return 0;
}





