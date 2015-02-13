#include<stdio.h>
int main()
{
	int a[1000],h,t,n,o,z,i;
	h=0;//head
	t=0;//tail
	z=0;//number of elements
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			if(t==1000)
			{
				if(z=1000)
				{
					printf("SORRY MEMORY FULL");
					break;
				}
				else
					t=0;
			}
			scanf("%d",&o);
			a[t]=o;
			t++;
			z++;
		}
		if(n==2)
		{
			z--;
			h++;
		}
		if(n==3)
		{
			if(h<t)
			{
				for(i=h;i<t;i++)
					printf("%d ",a[i]);
				printf("\n");
			}
			else if(h==t)
			{
				if(z!=1000)
					printf("NO NUMBER\n");
				else
				{
					printf("%d ",a[h]);
					i=h+1;
					while(i!=t)
					{
						if(i==1000)
							i=0;
						printf("%d ",a[i]);
						i++;
					}
					printf("\n");
				}
			}
			else
			{
				i=h;
				while(i!=t)
				{
					if(i==1000)
						i=0;
					printf("%d ",a[i]);
					i++;
				}
				printf("\n");
			}
		}
	}
	return 0;
}
