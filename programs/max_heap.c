//make a max heap with insert and delete
#include<stdio.h>
int a[100]={'\0'};
void check_insert(int n)//shuffle up
{
	int parent,temp;
	n--;
	while(n>1)
	{
		parent=n/2;
		if(a[parent]<a[n])
		{
			temp=a[parent];
			a[parent]=a[n];
			a[n]=temp;
			n=parent;
		}
		else
			break;
	}
	return;
}
int insert(int x,int n)
{
	int i,temp;
	i=n;
	a[n]=x;
	while(a[i]>a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
	}
	i++;
	return i;
}
void check_delete(int n)//shuffle down
{
	int i,temp,max;
	i=1;
	n--;
	while(i<=(n/2))
	{
		//	printf("i in check_delete %d\n",i);
		if((a[i]<a[(2*i)+1])&&(a[i]<a[(2*i)])&&(a[(2*i)+1]!='\0')&&(a[(2*i)]!='\0'))
		{
			if(a[(2*i)]<a[(2*i)+1])
			{
				temp=a[i];
				a[i]=a[(2*i)+1];
				a[(2*i)+1]=temp;
				i=(2*i)+1;
				//			printf("SWAPPED 1 %d & %d\n",a[i],a[(2*i)+1]);
			}
			else
			{
				temp=a[i];
				a[i]=a[(2*i)];
				a[(2*i)]=temp;
				i=(2*i);
				//			printf("SWAPPED 1 %d & %d\n",a[i],a[(2*i)]);
			}
		}
		else if((a[i]<a[(2*i)+1])&&(a[(2*i)+1]!='\0'))
		{
			temp=a[i];
			a[i]=a[(2*i)+1];
			a[(2*i)+1]=temp;
			i=(2*i)+1;
			//		printf("SWAPPED 2 %d & %d\n",a[i],a[(2*i)+1]);
		}
		else if((a[i]<a[(2*i)])&&(a[(2*i)]!='\0'))
		{
			temp=a[i];
			a[i]=a[(2*i)];
			a[(2*i)]=temp;
			i=(2*i);
			//		printf("SWAPPED 2 %d & %d\n",a[i],a[(2*i)]);
		}
		else
			break;
	}
	return;
}
void print(int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
int main()
{
	int n,i,o;
	i=1;
	a[0]=10000000;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&o);
			i=insert(o,i);
		}
		else if(n==2)
		{
			if(i!=0)
			{
			printf("%d IS DELETED\n",a[1]);
			//		printf("i value:%d\n",i);
			i--;
			a[1]=a[i];
			a[i]='\0';
			check_delete(i);
			}
			else
				printf("NO HEAP FOUND\n");
		}
		else if(n==3)
			print(i);
		else
			printf("INVALID ENTRY\n");
	}
	return 0;
}
