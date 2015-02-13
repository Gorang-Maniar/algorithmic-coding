#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int N,A,B;
		scanf("%d %d %d",&N,&A,&B);
		while(A!=B)
		{
			if(A>B)
				A=A/2;
			else if(B>A)
				B=B/2;
		}
		printf("%d\n",A);
	}
	return 0;
}
