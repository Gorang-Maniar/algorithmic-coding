#include<stdio.h>
int comp(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x,c,q=0,ct=0,w,max,k,l;
		scanf("%d",&max);
		int h[max];
		for(x=0;x<max;x++)
			scanf("%d",&h[x]);
		scanf("%d",&l);
		qsort(h,max,sizeof(int),comp);
		
		k=l;
		c=max;
	//	for(i=0;i<max;i++)
	//		printf("%d ",h[i]);
		
		while(c!=1)
		{
			if(l<max)
				k=l%max;
			else
				k=l;
			if(q>=max)
				q=q-max;
			while(ct!=(k-1))
			{
				if(q==max-1 && h[max-1]==0)
				{
					q=0;
				}
				else if(q==max-1 && h[max-1]!=0)
				{
					q=0;
					ct++;
				}
				else if(h[q]==0)
				{
					q++;
				}
				else if(h[q]!=0)
				{
					q++;
					ct++;
				}
				if(q==max)
					q=0;
			}
			if(ct==k-1)
			{
				while(h[q]==0)
				{
					q++;
					if(q==max)
						q=0;
				}
				h[q]=0;
				while(h[q]==0)
				{
					q++;
					if(q>=max)
						q=0;
				}
				c--;
				ct=0;
				//for(w=0;w<max;w++)
				//	printf("%lld ",h[w]);
				//printf("\n");
			}
		}
		for(w=0;w<max;w++)
		{
			if(h[q]!=0)
			{
				printf("%d\n",h[q]);
				break;
			}
		}
	}
	return 0;
}
