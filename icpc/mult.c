#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power(int a, int b)
{
	int i;
	if(b==0)
		return 1;
	else
	{
		int r=a;
		for(i=0;i<b-1;i++)
		{
			a=a*r;
		}
	}
	/*
	   while(b!=0)
	   {
	   a = a*a;
	   b--;
	   }
	 */

	return a;
}

int count(long long int temp)
{
	int ct=0;
	if(temp==0)
		ct=1;
	else{
		while(temp!=0)
		{
			temp = temp/10;
			ct++;
		}
	}
	return ct;

}
int main()
{
	int j=1;
	while(1)
	{

		long long int a,b,temp,ans;
		int ct,cta,ctb,ct0=0,i,sp,k,counter=0;
		scanf("%lld %lld",&a,&b);
		if(a==0&&b==0)
			break;
		ans = a * b;
		ct = count(ans);
		long long int arr[ct+1];
		cta = count(a);
		ctb = count(b);
		for(i=0;i<ctb;i++)
		{	
			int t = power(10,i);
			arr[i] = a*((b/t)%10);
			if(arr[i]!=0)
				ct0++;
		}
		if(a==0 || b==0)
		{
			int as,f=0;
			printf("Problem %d\n",j);
			if(cta>ctb)
			{	as = cta;
				f=1;

			}
			else{
				as = ctb;
				f=2;
			}

			for(i=0;i<(as-cta);i++)
			{	if(f==2)
				printf(" ");}
			printf("%lld\n",a);
			for(i=0;i<(as-ctb);i++)
			{	if(f==1)
				printf(" ");}
			printf("%lld\n",b);
			for(i=0;i<as;i++)
				printf("-");
			printf("\n");
			for(i=0;i<(as-1);i++)
				printf(" ");
			printf("0\n");
		}
		else{

			//printf("%d %d %d\n",ct,cta,ctb);
			printf("Problem %d\n",j);
			for(i=0;i<(ct-cta);i++)
				printf(" ");
			printf("%lld\n",a);
			for(i=0;i<(ct-ctb);i++)
				printf(" ");
			printf("%lld\n",b);
			for(i=0;i<ct;i++)
				printf("-");
			printf("\n");

			for(i=0;i<ctb;i++)
			{
				if(arr[i]==0)
				{counter++;}
				else{
					sp = ct - count(arr[i]);
					for(k=0;k<(sp-i);k++)
						printf(" ");
					printf("%lld",arr[i]);
					if(counter!=0){
						for(k=0;k<counter;k++)
							printf("0");
				//		for(k=0;k<(i-counter);k++)
				//			printf(" ");
						printf("\n");
						counter=0;
					}
					else{
				//		for(k=0;k<i;k++)
				//			printf(" ");
						printf("\n");
					}
				}
			}
			if(ct0!=1)
			{
				for(i=0;i<ct;i++)
					printf("-");
				printf("\n");
				printf("%lld\n",ans);
			}
		}
		j++;
	}
	return 0;
}
