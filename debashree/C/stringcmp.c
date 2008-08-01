#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{	char s1[30],s2[30];
	int i,c=0;
	printf("Enter the first string:\n");
	 scanf("%s",s1);
	printf("Enter the second string:\n");
	scanf("%s",s2);
	for(i=0;s1[i]!='\0'&& s2[i]!='\0';i++)
	if(s1[i]!=s2[i])
	{
           c= s1[i]-s2[i];
	   break;
	}
	if(s1[i]=='\0'&& s2[i]!='\0')
	  c=32-s2[i];
        else
	if(s1[i]!='\0'&& s2[i]=='\0')
	  c=s1[i]-32;
	printf("The diference is %d\n",c);
      return(0);
}
