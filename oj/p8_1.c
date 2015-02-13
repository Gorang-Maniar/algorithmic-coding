#include<stdio.h>
#include<stdlib.h>

int main()
{


	long long int test;
	long long int len , shift, i, pnt;
	long long int arr[555];
	scanf("%lld",&test);
	while(test!=0)
	{
		scanf("%lld %lld", &len , &shift);
		//printf("input1");

		for(i=0;i<len;i++)
			scanf("%lld", &arr[i]);

		//printf("input");

		//count = len;
		pnt = 0;
		while(len!=0)
		{
			if (len==1)
				printf("%lld",arr[pnt]);
			else
				printf("%lld ", arr[pnt]);

			for(i=pnt; i<len ; i++)
				arr[i]=arr[i+1];

			len--;
			if (len!=0)
				pnt = ( pnt + shift -1 ) % len ;
		}
		test--;
		printf("\n");
	}
//printf("%lld\n",arr[len-1]);



	return 0;
}
