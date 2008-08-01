#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int    main(void)
      { char a[20];
	int j,i;
	printf("Enter any string of characters:\n");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++);
	printf("The length of string is %d",i);

	printf("\nThe string in reverse order is:");
	for(j=i;j>=0;j--)
	{printf("%c",a[j]);}
	return(0);
      }		
