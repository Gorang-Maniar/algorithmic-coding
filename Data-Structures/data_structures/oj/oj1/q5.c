#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
}*last;

void create(int num){
	struct node *q,*temp;
	temp = malloc(sizeof(struct node));
	temp->data = num;
	if(last == NULL){
		last = temp;
		temp->next = last;
	}
	else{
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}

}
void delete(int num){
	struct node *temp,*q;
	q=last;
	if(q->data == num){
		temp = q;
		last->next = q->next;
		free(temp);
		return;
	}
}
int main(){
	int j,p,k;
//	node *head;
	scanf("%d",&p);
	for(j=0;j<p;j++){
		int c,n,m,p,i;
		last = NULL;
		scanf("%d",&n);
//		scanf("%d",&head->data);
		for(i=0;i<n;i++){
			scanf("%d",&m);
			create(m);
		}
		scanf("%d",&k);
		last = last->next;
		//	while(last->next!=NULL){
		printf("%d",last->data);
		//		last=last->next;
		//	}
		while(last->next!=last){
	//		last = last->next;
			while(c!=k){
				last=last->next;
				c++;
			}
			if(c==k){
				delete(last->data);

					last = last->next;
		}
		printf("%d",last->data);
	}
	}
	return 0;
}
