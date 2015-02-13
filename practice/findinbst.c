//implement find in bst

#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}node;
void insert(node *r, int val){
	if(val>(r->data)){
	
		if((r->right)==NULL){
			r->right=(node *)malloc(sizeof(node));
			r = r -> right;
			r-> left = NULL;
			r -> right = NULL;
			r -> data = val;
		}
		else
			insert(r -> right,val);
	}
	else{
		if((r->left)==NULL){
			r->left=(node *)malloc(sizeof(node));
			r = r -> left;
			r-> left = NULL;
			r -> right = NULL;
			r -> data = val;
		}
		else
			insert(r -> left,val);
	}
}

int find_num(node *x,int num,int c){
	if(x!=NULL){
	//	printf("aa\n");
	if((x->data)==num)
		return 1;
	else if((x->data)>num)
		find_num(x->left,num,c++);
	else if((x->data)<num)
		find_num(x->right,num,c++);
	else 
		return 0;
	}
}


void inorder_trav(node *x){
	if(x!=NULL){
		inorder_trav(x -> left);
		printf("%d ",x->data);
		inorder_trav(x -> right);
	}
}

void preorder_trav(node *x){
	if(x!=NULL){
		printf("%d ",x->data);
		preorder_trav(x->left);
		preorder_trav(x->right);
	}
}

void postorder_trav(node *x){
	if(x!=NULL){
		postorder_trav(x->left);
		postorder_trav(x->right);
		printf("%d ",x->data);
	}
}

int main(){
	int t,u;
	printf("Enter the number of trees you wish to make:\n");
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		node *l;
		int i,n,root,up,f,ct=0,findvar;
		printf("Enter the number of elements in tree:\n");
		scanf("%d",&n);
		printf("Enter the %d elements:\n",n);
		scanf("%d",&root);
		l = (node *)malloc(sizeof(node));
		l -> left = NULL;
		l -> right = NULL;
		l -> data = root;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&up);
			insert(l,up);
		}
		printf("Enter the number you wish to find:\n");
		scanf("%d",&f);
		findvar=find_num(l,f,ct);
		if(findvar==1)
			printf("%d is found in the tree\n",f);
		else
			printf("%d is not a member of the tree %d\n",f,findvar);

/*		printf("Inorder traversal of the tree:\n");
		inorder_trav(l);
		printf("\n");
		printf("Preorder traversal of the tree:\n");
		preorder_trav(l);
		printf("\n");
		printf("Postorder traversal of the tree:\n");
		postorder_trav(l);
		printf("\n");

*/
	}
	return 0;
}

