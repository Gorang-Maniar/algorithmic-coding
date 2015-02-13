/* C program that uses Stack operations to perform the following:
i) Converting infix expression into postfix expression
*/
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char k);
char pop();
void main()
{
 int l,i;
 char ch,e[max];
// clrscr();
 printf("enter infix exp with () to convert to postfix \n");
 gets(e);
 l=strlen(e);
 printf("the postfix is :\n");
 for(i=0;i<=l-1;i++)
 {
  ch=e[i];
  if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/')push(ch);
  else if(ch!=')')putchar(ch);
  else
   {
     do
     {
      ch=pop();
      if(ch!='(')putchar(ch);
     }
     while(ch!='(');
   }
 }
//getch();
}
void push(char k)
{
 if(top+1==max)printf("stack is full\n");
 else {top++;stack[top]=k;}
 return;
}
char pop()
{
 char a;
 if(top<0){printf("stack is empty\n");return('\0');}
 else {a=stack[top];top--;return(a);}
}
