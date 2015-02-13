#include<stdio.h>
int main()
{
	int t,q;
	scanf("%d",&t);
	for(q=0;q<t;q++)
	{
		int r,c;
		scanf("%d %d",&r,&c);
		char arr[102][102]={0};
		int temp[102]={0},f=0,a,ct=0,ct1=0,i,j,fl[102][102]={0};
		for(i=0;i<r;i++)
		{
				scanf("%s",arr[i]);
			for(j=0;j<c;j++)
			{
				if(arr[i][j]=='H')
				{
					fl[i][j]=1;
					temp[i]++;
				}
				else
					fl[i][j]=0;
			}
			//getchar();
		}
		for(a=0;a<r;a++)
		{
		//	for(j=0;j<c;j++)
		//	printf("%c",arr[a][j]);
			if(temp[a]>0)
				ct++;
		}
			for(i=0;i<r;i++)
			{
				for(j=c-1;j>=0;j--)
				{
					if(fl[i][j]=='1')
					{
						temp[i]=j;
						ct1+=j;
						break;
					}
				}
			}
						
		if(ct%2==0)
		{


				if(ct1%2==0)
				{
					printf("Phoenix wins\n");
				}

				else
					printf("Edgeworth wins\n");
		}
		else
		{
				printf("Phoenix wins\n");

	}
	return 0;
}

