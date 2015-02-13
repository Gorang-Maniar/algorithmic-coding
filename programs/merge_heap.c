//merge two min heaps two make a heap
#include<stdio.h>
int a[100]={'\0'};
int check_delete(int n)//shuffle down
{
	int i,temp,max;
	i=1;
	n--;
	while(i<=(n/2))
	{
		if((a[i]>a[(2*i)+1])&&(a[i]>a[(2*i)])&&(a[(2*i)]!='\0')&&(a[(2*i)+1]!='\0'))
		{
			if(a[(2*i)]>a[(2*i)+1])
			{
				temp=a[i];
				a[i]=a[(2*i)+1];
				a[(2*i)+1]=temp;
				i=(2*i)+1;
			}
			else
			{
				temp=a[i];
				a[i]=a[(2*i)];
				a[(2*i)]=temp;
				i=(2*i);
			}
		}
		else if((a[i]>a[(2*i)+1])&&(a[(2*i)+1]!='\0'))
		{
			temp=a[i];
			a[i]=a[(2*i)+1];
			a[(2*i)+1]=temp;
			i=(2*i)+1;
		}
		else if((a[i]>a[(2*i)])&&(a[(2*i)]!='\0'))
		{
			temp=a[i];
			a[i]=a[(2*i)];
			a[(2*i)]=temp;
			i=(2*i);
		}
		else
			break;
	}
	return n;
}
int main()
{
	int n,q,i,o,parent,temp,x,b[100]={0},j;
	printf("ENTER THE NUMBER OF ELEMENTS IN THE FIRST HEAP\n");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS OF FIRST HEAP\n");
	i=1;
	for(j=1;j<=n;j++)
	{
		scanf("%d",&o);
		a[i]=o;
		i++;
		x=i-1;
		while(x>1)
		{
			parent=x/2;
			if(a[parent]>a[x])
			{
				temp=a[parent];
				a[parent]=a[x];
				a[x]=temp;
				x=parent;
			}
			else
				break;
		}
	}
	printf("ENTER THE NUMBER OF ELEMENTS IN THE SECOND HEAP\n");
	scanf("%d",&q);
	i=1;
	printf("ENTER THE ELEMENTS OF SECOND HEAP\n");
	for(j=1;j<=q;j++)
	{
		scanf("%d",&o);
		b[i]=o;
		i++;
		x=i-1;
		while(x>1)
		{
			parent=x/2;
			if(b[parent]>b[x])
			{
				temp=b[parent];
				b[parent]=b[x];
				b[x]=temp;
				x=parent;
			}
			else
				break;
		}
	}
	printf("SORTED ARRAY 1 IS\n");
	for(j=1;j<=n;j++)
	{
		printf("%d\t",a[j]);
	}
	printf("\n");
	printf("SORTED ARRAY 2 IS\n");
	for(j=1;j<=q;j++)
	{
		printf("%d\t",b[j]);
	}
	printf("\n");
	printf("NOW TO MERGE ARRAY 1 IN ARRAY 2\n");
	{
		while(n>0)
		{
			printf("%d IS DELETED\n",a[1]);
			for(j=1;j<=n;j++)
			{
				printf("%d\t",a[j]);
			}
			printf("\n");
			b[i]=a[1];
			i++;
			x=i-1;
			while(x>1)
			{
				parent=x/2;
				if(b[parent]>b[x])
				{
					temp=b[parent];
					b[parent]=b[x];
					b[x]=temp;
					x=parent;
				}
				else
					break;
			}
			a[1]=a[n];
			a[n]='\0';
			n=check_delete(n);
		}
	}
	printf("FINALLY SORTED AND MERGED ARRAY 2\n");
	for(j=1;j<i;j++)
	{
		printf("%d\t",b[j]);
		a[j]=b[j];
	}
	printf("\n");
	printf("DOING HEAP SORT ON THAT ARRAY WE GET\n");
	while(i>1) 
	{
	         printf("%d ",a[1]);
	         i--;
	         a[1]=a[i];
	         a[i]='\0';
	         check_delete(i);
	}
	printf("\n");
	return 0;
}
