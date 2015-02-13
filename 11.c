#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int t;
    scanf("%d",&t);
    while(t--)
        {
        int n,i;
        int f=0;
	char s2[100];
	char s[100];
        scanf("%s",s2);
        n=strlen(s2);
	strcpy(s,s2);
        for(i=n-1;i>0;i--)
            {
	   
            if(s[i]>s[i-1])
                {
                f=1;
                char temp=s[i];
                s[i]=s[i-1];
                s[i-1]=temp;
                break;
            }
	    }
	char s1[100];
	strcpy(s1,s);
            if(f==1)
            {
		for(i=n-1;i>0;i--)
		{
			if(s1[i]<s1[i-1])
			{
				char temp=s1[i];
				s1[i]=s1[i-1];
				s1[i-1]=temp;
				break;
			}
		}
		if((strcmp(s1,s2))==0)
                	printf("%s\n",s);
		else
			printf("%s\n",s1);
            }
            else
                printf("no answer\n");
            
        }
    
       
    return 0;
}
