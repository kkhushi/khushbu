#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int   main(void)

{	char a[20],b[20],c[20];
	int i,j;
	printf("\nEnter the first string\n");
	scanf("%s",a);
	printf("\nEnter the second string\n");
	scanf("%s",b);
	for(i=0;a[i]!='\0';i++)
	{c[i]=a[i];}
	for(j=0;b[j]!='\0';j++)
	{c[i+j]=b[j];}
	printf("The concatenated string is:%s\n",c);
	return(0);
}

