#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=1;a<10;a++)
	{
		for(b=1;b<10;b++)
		{
			for(c=1;c<10;c++)
			{
				if(c==(2*a))
				{
					if((2*((10*a)+b))==((10*b)+c))
					{
						printf("%d%d%d%d\n",a,b,b,c);
					}
				}
			}
		}
	}
	return 0;
}

