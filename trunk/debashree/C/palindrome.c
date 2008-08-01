#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int main(void)

{	char a[20];
	int i,j,n,ch=0;
	printf("Enter the word for checking:\n");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++);
	n=i-1;
	i=0;
	j=n;
while(ch==0)
        {
	   if(a[i]==a[j])
	   {
             i++;
	     j--;
	   }
	   
	   else
	   ch=1;
	   if(i>=n/2)
	   ch=2;
         }
	if(ch==2)
	printf("\n The word is a palindrome.\n");
	else
	printf("\nThe word is not a palindrome.\n");
	return(0);
}

