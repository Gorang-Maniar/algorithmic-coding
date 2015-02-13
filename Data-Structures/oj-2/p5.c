#include<stdio.h>
#include<stdlib.h>
int arr[100000]={0},var=0;
typedef struct bst{
	int data;
	struct bst *l;
	struct bst *r;
}bst;
/*bst *ser(bst *t, int m)
{
	bst *temp;
	temp = t;
	if(temp -> data == m)
		return temp;
	else if(temp -> data > m)
	{
		temp -> l = ser(temp->l,m);
		temp = temp->l;
	}
	else
	{
		temp -> r = ser(temp -> r,m);
		temp = temp -> r;
	}
}*/

bst *ser(bst *t, int m)
{
	if(t -> data == m)
		return t;
	else if(t -> data > m)
	{
		t -> l=ser(t->l,m);
	}
	else
	{
		t -> r = ser(t -> r,m);
	}
}
bst *ins(bst *t, int n)
{
	if(t==NULL)
	{
		bst *tmp;
		tmp = (bst*)malloc(sizeof(bst));
		tmp -> l = NULL;
		tmp -> r = NULL;
		tmp -> data =n;
		t = tmp;
	}
	else if(t -> data < n)
	{
		t -> r = ins(t -> r, n);
	}
	else if(t -> data >= n)
	{
		t -> l = ins(t -> l,n);
	}
	return t;
}

int bstsort(int a[],int w,int q);
int deep(bst *t, int z);
void getit(bst *t);
int sorting(int a[], int p);

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int l=0, p=0,b,array[10000]={0},f=0,chd[10000]={0},fl=0,inp[10000],arrnd,z,x,c=0,v;
		bst *t;var=0;
		t = NULL;
		scanf("%d",&p);
		for(l=0;l<p;l++)
		{
			scanf("%d",&inp[l]);
			t = ins(t,inp[l]);
//			printf("%d",t->data);
		}
		scanf("%d%d",&z,&x);
		for(l=0;l<p;l++){
			if(z==inp[l])
			{
				fl = 1;
				break;
			}
			else
				fl = 0;
		}
		if(fl == 0)
			printf("$ $\n");
		else
		{
			for(l=0;l<p;l++)
			{
				if((deep(t,z) == deep(t,inp[l])) && (z < inp[l]))
				{
					array[c++] = inp[l];
					f = 1;
				}
			}
			if(f!=1)
				printf("$ $\n");
			else
			{
				arrnd = sorting(array, c);
				bst *tmp;
				tmp = ser(t,arrnd);
				printf("%d ",tmp->data);
				getit(tmp);
				if(var < x)
					printf("$\n");
				else 
					printf("%d\n",bstsort(arr,var,x));
			}
		}
	}
	return 0;
}

int bstsort(int a[],int w,int q)
{
	int e,r,t;
	for(e=0;e<w;e++)
	{
		t = a[e];
		r = e-1;
		while((t < a[r])&&(r>=0))
		{
			arr[r+1] = arr[r];
			r--;
		}
		arr[r+1] = t;
	}
	return arr[q-1];
}

int sorting(int a[], int p)
{
	int i,k,t;
	for(i=0;i<p;i++)
	{
		t = a[i];
		k = i-1;
		while((t < a[k] )&&(k>=0))
		{
			arr[k+1] = arr[k];
			k--;
		}
		arr[k+1] = t;
	}
	return arr[0];
}

int deep(bst *t, int z)
{
	bst *tm;
	tm = t;
	if(tm -> data == z)
		return 0;
	else if(tm -> data > z)
			return 1+deep(tm -> l,z);
	else
		return 1+deep(tm -> r,z);
}

void getit(bst *t)
{
	if(t!=NULL)
	{
		getit(t -> l);
		arr[var++] = t -> data;
		getit(t -> r);
	}
}

