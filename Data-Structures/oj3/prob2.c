#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	int x;
	struct element *l;//left
	struct element *r;//right
}node;
int inp[1000],output[1000],r;

int ser();
node *ins();
void preorder_trav();
void postorder_trav();

int main(){

	int t,n;
	node *s;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		node *s;
		int num,i,p,q;
		scanf("%d",&num);
		for(i=0;i<num;i++)
			scanf("%d",&inp[i]);//input array
		s = ins(0,num-1);//insertion
		r = 0;//making it zero
		preorder_trav(s);//preorder
		for(p=0;p<num-1;p++)
			printf("%d ",output[p]);
		printf("%d\n",output[num-1]);
		inp[num-1] = 0;//required to make zero
		for(q=0;q<num;q++)
			output[q] = 0;//output array made null
		r = 0;
		postorder_trav(s);//postorder traversal
		for(p=0;p<num-1;p++)
			printf("%d ",output[p]);
		printf("%d\n",output[num-1]);

		for(q=0;q<num;q++)
			output[q] = 0;
		r = 0;
		inp[num-1] = 0;
	}
	return 0;
}
// function to insert
node *ins(int begin, int end){
	int w;
	node *m;
	if(begin > end)
		return NULL;
	w = ser(begin, end);

	m = (node *)malloc(sizeof(node));
	m -> x = inp[w];//new node
	m -> r = NULL;
	m -> l = NULL;
	if(begin == end)
		return m;
	m -> r = ins(w+1,end);//insertion towards right
	m -> l = ins(begin,w-1);//insertion towards left 
	return m;
}
// preorder
void preorder_trav(node *m){
	if(m!=NULL){
		output[r] = m -> x;
		r++;
		preorder_trav(m -> l);//recursive call
		preorder_trav(m -> r);//recursive call
	}
}
//postorder
void postorder_trav(node *m){

	if(m!=NULL){
		postorder_trav(m -> l);//recursive call
		postorder_trav(m -> r);//recursive call
		output[r] = m -> x;//outputting array
		r++;
	}
}
//functio to search
int ser(int begin,int end){
	int least;
	int c,j;
	least = inp[begin]; //minimum
	c = begin;
	for(j=begin;j<=end;j++)
	{
		if(least>inp[j])
		{
			least = inp[j];
			c = j;
		}
	}
	return c;
}

