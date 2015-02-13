// quadratic probing
#include<stdio.h>

int main()
{
	int t,ta[17]={0},n,a,b=0,c,i,j,h;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);

		if(n==1)
		{
			scanf("%d",&a);
			i=0;
			h=(a+(i*i))%17;

			while(ta[h]!=0 && ta[h]!=-1)
			{
				i++;
				h=(a+(i*i))%17;
			}
			ta[h]=a;
			b++;
		}
		else if(n==2)
		{
			scanf("%d",&a);
			i=0;
			h=(a+(i*i))%17;

			while(ta[h]!=a && ta[h]!=0)
			{
				i++;
				h=(a+(i*i))%17;
			}
			if(ta[h]==0 && a!=0)
				printf("not found\n");
			else
				printf("found at %dth position\n",h);
		}
		else if(n==3)
		{
			scanf("%d",&a);
			i=0;
			h=(a+(i*i))%17;

			while(ta[h]!=a && ta[h]!=0)
			{
				i++;
				h=(a+(i*i))%17;
			}
			if(ta[h]==0 && a!=0)
				printf("not found\n");
			else
			{
				ta[h]=-1;
				b--;
			}
		}
		else if(n==4)
		{
			for(i=0;i<17;i++)
				printf("%d ",ta[i]);
			printf("\n");
		}
		//if(b==17)
		//	printf("table full\n");
	}
	return 0;
}
