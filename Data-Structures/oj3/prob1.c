#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	int x;
	struct element *l;
	struct element *r;
}node;

int temp[1000],r;

void ins();
void preorder_trav();
void inorder_trav();
void postorder_trav();

int main(){
	node *m,*n;
	int t,w;
	scanf("%d",&w);
	for(t=0;t<w;t++)
	{
		int num,preorder[1000],inorder[1000],q,i,j=0,p;
		scanf("%d",&num);
		for(i=0;i<num;i++)
			scanf("%d",&preorder[i]);
		for(i=0;i<num;i++)
			scanf("%d",&inorder[i]);
		scanf("%d",&q);
		
		for(j=0;j<num;j++){
			if(preorder[j] == q)
				break;
		}
		p = j;	
		while(p>0){
			preorder[p] = preorder[p-1];//shifting
			p--;  //backward traversal
		}
		preorder[0] = q;//root

		m = (node *)malloc(sizeof(node));
		m -> x = preorder[0];
		m -> l = NULL;
		m -> r = NULL;

		n = m;

		for(p=1;p<num;p++)
			ins(n,preorder[p]);//insertion
		r = 0;

		inorder_trav(n);//inorder traversal
		for(p=0;p<(num-1);p++)
			printf("%d ",temp[p]);
		printf("%d\n",temp[num-1]);
		r = 0;

		preorder_trav(n);//preorder traversal
		for(p=0;p<(num-1);p++)
			printf("%d ",temp[p]);
		printf("%d\n",temp[num-1]);
		r = 0;
		
		postorder_trav(n);//postorder traversal
		for(p=0;p<(num-1);p++)
			printf("%d ",temp[p]);
		printf("%d\n",temp[num-1]);
		r = 0;
	}
	return 0;
}

void ins(node *m, int p){
	if((m -> x) < p){
		if(m -> r == NULL){
			m -> r = (node *)malloc(sizeof(node));//new node when m->x is < p
			m = m -> r;
			m -> l = NULL;
			m -> r = NULL;
			m -> x = p;
		}
		else 
			ins(m -> r,p); //otherwise
	}
	else if((m -> x) > p){
		if(m -> l == NULL){
			m -> l = (node *)malloc(sizeof(node));//new node when m->x is > p
			m = m -> l;
			m -> l = NULL;
			m -> r = NULL;
			m -> x = p;
		}
		else 
			ins(m -> l,p);//otherwise
	}

}

void preorder_trav(node *m){

	if(m!=NULL){
		temp[r] = m -> x;
		r++;
		preorder_trav(m -> l);
		preorder_trav(m -> r);
	}
}

void inorder_trav(node *m){

	if(m!=NULL){
		inorder_trav(m -> l);
		temp[r] = m -> x;
		r++;
		inorder_trav(m -> r);
	}
}

void postorder_trav(node *m){

	if(m!=NULL){
		postorder_trav(m -> l);
		postorder_trav(m -> r);
		temp[r] = m -> x;
		r++;
	}
}
	
