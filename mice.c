#include<stdio.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
	return(*(int*)a - *(int*)b);
}	
int main()
{
	long long int p,t;
	scanf("%lld",&t);
	for(p=0;p<t;p++)
	{
		long long int n,m;
		scanf("%lld",&n);
		scanf("%lld",&m);
		long long int mouse[n],c1=0,l,hole[m],diff[n],i,j,max=0,k=1,t1[n],t2[n],f1=0;
		for(i=0;i<n;i++)
			scanf("%lld",&mouse[i]);
		for(i=0;i<m;i++)
			scanf("%lld",&hole[i]);
		qsort(mouse+0,n,sizeof(long long int),cmp);
		qsort(hole+0,m,sizeof(long long int),cmp);
		//if(m>n)
		//	n=m;
		if(m==n)
		{
			for(j=0;j<n;j++)
			{
				diff[j]=mouse[j]-hole[j];
				if(diff[j]<0)
					diff[j] = -diff[j];
				if(max<diff[j])
					max=diff[j];
			}
		}
		else
		{
		for(j=0;j<n;j++)
		{
			while(k<m)
			{ 

				if(mouse[j]<=hole[k])
				{	
					t1[j]=mouse[j]-hole[k];
					t2[j]=mouse[j]-hole[k-1];
					if(t2[j]<0)
						t2[j] = -t2[j];
					if(t1[j]<0)
					t1[j]=-t1[j];

					if(f1==1){
					if(t1[j]>t2[j]){
						for(l=0;l<j;l++){
						if(t1[j]>t2[l]){
							c1=1;
							break;
						}
						}
						if(c1!=1)
						{
							for(l=0;l<j-1;l++)
							diff[l]=t2[l];
							diff[j]=t2[j];
						}
					}
					
					else{
						diff[j]=t1[j];
						f1=1;
					}
					}	
					else{
						if(t1[j]>=t2[j])
							diff[j]=t2[j];
						else
							diff[j] = t1[j];
					}
	
						k++;
					break;
				}
				else
				k++;	
			}
		}
		}
		for(j=0;j<n;j++){
			if(max<diff[j])
				max = diff[j];
		}
		printf("%lld\n",max);
	}
	return 0;
}
