#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
    int n;
    struct elem* next;
    struct elem* pre;
}node;
node* push(int e,node *t)
{
    t->next=(node *)malloc(sizeof(node));
    t->next->pre=t;
    t=t->next;
    t->next=NULL;
    t->n=e;
    return t;
}
node* calc(int e,node *t)
{
    node *u;
    if(e=='+')
    {
        t->pre->n=(((int)(t->n)-48)+((int)(t->pre->n)-48));
        u=t;
        t=t->pre;
        t->next=NULL;
        free(u);
        return t;
    }

    if(e=='/')
    {
        t->pre->n=(((int)(t->n)-48)/((int)(t->pre->n)-48));
        u=t;
        t=t->pre;
        t->next=NULL;
        free(u);
        return t;
    }

    if(e=='*')
    {
        t->pre->n=(((int)(t->n)-48)*((int)(t->pre->n)-48));
        u=t;
        t=t->pre;
        t->next=NULL;
        free(u);
        return t;
    }

    if(e=='-')
    {
        t->pre->n=(((int)(t->n)-48)-((int)(t->pre->n)-48));
        u=t;
        t=t->pre;
        t->next=NULL;
        free(u);
        return t;
    }
}
int main()
{
    node *l,*m;
    int i;
    char s[1000];
    scanf("%s",s);
    i=0;
    l=(node *)malloc(sizeof(node));
    l->n='y';
    l->next=NULL;
    l->pre=NULL;
    m=l;
    while(s[i]!='\0')
    {   
        if((((int)s[i]-48)>=0)&&(((int)s[i]-48)<10))
            m=push(((int)s[i]-48),m);
        else
            m=calc(((int)s[i]-48),m);
    }
    printf("%c",m->n);
    return 0;
}


