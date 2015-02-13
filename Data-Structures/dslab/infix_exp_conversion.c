//infix expression to postfix conversion
#include<stdio.h>
#include<stdlib.h>
typedef struct elem
{
    char a;
    struct elem* next;
    struct elem* pre;
}node;
node* push(char n,node *e)
{
   //printf("HI");
   e->next=(node *)malloc(sizeof(node));
   e->next->pre=e;
   e=e->next;
   e->a=n;
   e->next=NULL;
   return e;
}
node* pop(node *e)
{
    //printf("HI");
    node *t;
    t=e;
    if(t->a!='(')
        printf("%c",t->a);
    e=e->pre;
    free(t);
    e->next=NULL;
    return e;
}
int main()
{
    node *l,*m;
    int i;
    char s[1000];
    scanf("%s",s);
    i=0;
    //printf("HI");
    m=(node *)malloc(sizeof(node));
    m->pre=NULL;
    m->a='z';
    m->next=NULL;
    l=m;
    while(s[i]!='\0')
    {
        //printf("HI");
        if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^')||(s[i]=='(')||(s[i]==')'))
        {
           if(s[i]=='(')
               l=push(s[i],l);
           if(s[i]==')')
           {
               while(l->a!='(')
               {
                   l=pop(l);
               }
               l=pop(l);
           }
           if(s[i]=='-')
           {
               while((l->a!='(')&&(l->pre!=NULL))
                   l=pop(l);
               l=push(s[i],l);
           }
           if(s[i]=='^')
           {
               while((l->a!='+')&&(l->a!='-')&&(l->a!='/')&&(l->a!='*')&&(l->pre!=NULL)&&(l->a!='('))
               {
                   l=pop(l);
               }
               l=push(s[i],l);
           }
           if(s[i]=='/')
           {
               while((l->a!='+')&&(l->a!='-')&&(l->a!='*')&&(l->a!='(')&&(l->pre!=NULL))
               {
                   l=pop(l);
               }
               l=push(s[i],l);
           }

           if(s[i]=='*')
           {
               while((l->a!='+')&&(l->a!='-')&&(l->a!='(')&&(l->pre!=NULL))
               {
                   l=pop(l);
               }
               l=push(s[i],l);
           }

           if(s[i]=='+')
           {
               while((l->a!='-')&&(l->a!='(')&&(l->pre!=NULL))
               {
                   l=pop(l);
               }
               l=push(s[i],l);
           }
        }
        else
            printf("%c",s[i]);
        i++;
    }
    while(l->pre!=NULL)
        l=pop(l);
    printf("\n");
    return 0;
}
