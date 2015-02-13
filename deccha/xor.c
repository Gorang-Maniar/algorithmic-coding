#include<stdio.h>
int xor(int a,int b,int arr[])
{
	if(a==b)
	{
		return arr[a];
	}
	else{
		int w,c=arr[b];
		for(w=a;w<b;w++)
			c=c^arr[w];
		return c;
	}
}
int main()
{
	int p,q;
	scanf("%d",&p);
	for(q=0;q<p;q++)
	{
		int n,k,i,j,r,t=0,max=0;
		scanf("%d %d",&n,&k);
		int arr[n+1];
		for(r=0;r<n;r++)
			scanf("%d",&arr[r]);
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				t = xor(i,j,arr);
				t = t^k;
				if(max<t)
				{
					max=t;
			//		printf("i=%d j=%d\n",i,j);
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}

