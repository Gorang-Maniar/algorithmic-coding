#include<stdio.h>
long long int power(int a, int b)
{
	long long int c=1;
	while(b!=0)
	{
		c=c*a;
		b--;
	}
	return c;
}
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int p,s = n+m,c = power(2,s),d =c*2;
		long long int arr[d][3];
	/*	for(p=0;p<c;p++)
		{
			arr[p][0]=-1; arr[p][1]=-1;
		}*/
		arr[1][0] = n;
		arr[1][1] = m;
		int i=1,j,count=0;
		while(c>1)
		{	
			if(arr[i][0]>0)
			{	arr[2*i][0] = arr[i][0]-1;
			arr[2*i][1] = arr[i][1];
			}
			else
			{
				arr[2*i][0] = -1;
				arr[2*i][1] = -1;
			}
			if(arr[i][1]>0)
			{
				arr[(2*i)+1][0] = arr[i][0];
				arr[(2*i)+1][1] = arr[i][1]-1;
			}
			else
			{
				arr[(2*i)+1][1] = -1;
				arr[(2*i)+1][0] = -1;
			}

	//		printf("c = %d arr[%d][0]=%d arr[%d][1]=%d arr[%d][0]=%d arr[%d][1]=%d\n",c,2*i,arr[2*i][0],2*i,arr[2*i][1],(2*i)+1,arr[(2*i)+1][0],(2*i)+1,arr[(2*i)+1][1]);
			i++;
			c--;
		}
		for(j=2;j<d;j++)
		{
	//		printf("%d %d %d\n",arr[j][0],arr[j][1],j);
			if(arr[j][0]==0 && arr[j][1]==0)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}




		

