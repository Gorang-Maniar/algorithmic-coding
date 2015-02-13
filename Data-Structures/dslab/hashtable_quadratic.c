#include<stdio.h>
int main()
{
	int table[17]={0},a,x,n,i;
	printf("ENTER 1 FOR INSERTION(ANY NUMBER EXCEPT 0)\nENTER 2 FOR LOOKUP\nENTER 3 FOR DELETION\nENTER 4 TO PRINT THE NUMBERS IN THE ARRAY\n");
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&a);
			for(i=0;i<17;i++)
			{
				if((table[(a+i*i)%17]==0)||(table[(a+i*i)%17]==-1))
				{
					table[(a+i*i)%17]=a;
					break;
				}
			}
		}
		else if(n==2)
		{
			scanf("%d",&a);
			for(i=0;i<17;)
			{
				if(table[(a+i*i)%17]==a)
				{
					printf("FOUND THE NUMBER AT POSITION %d\n",(a+i*i)%17);
					break;
				}
				else if(table[(a+i*i)%17]==-1)
					i++;
				else if(table[(a+i*i)%17]==0)
				{
					printf("ELEMENT NOT FOUND\n");
					break;
				}
				else
					i++;
			}
		}
		else if(n==3)
		{
			scanf("%d",&a);
			for(i=0;i<17;)
			{
				if(table[(a+i*i)%17]==a)
				{
					printf("%d IS DELETED\n",table[(a+i*i)%17]);
					table[(a+i*i)%17]=-1;
					break;
				}
				else if(table[(a+i*i)%17]==0)
				{
					printf("ELEMENT NOT FOUND\n");
					break;
				}
				else
					i++;
			}
		}
		else if(n==4)
		{
			for(i=0;i<17;i++)
				printf("%d ",table[i]);
			printf("\n");
		}
		else
			printf("INVALID INPUT\n");
	}
	return 0;
}
