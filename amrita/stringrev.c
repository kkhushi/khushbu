#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
  { int i,l;
    char a[20];
    printf("enter the string:");
    scanf("%s",a);
    printf("\n the entered string is: %s",a);
    for(i=0;a[i]!='\0';i++)
     { }
    printf("\n the length of the string is %d",i);

    printf("\n the reversed string is:");
    for(l=i;l>=0;l--)
     printf("%c",a[l]);
    exit(0);
}

