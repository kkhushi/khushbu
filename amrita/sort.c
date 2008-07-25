#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[11],i,j,t;
	
	printf("      ==============================\n");
	printf("      ***PROGRAMME OF BUBBLE SORT***\n");
	printf("      ==============================\n");
	printf("ENTER THE ARRAY\n");
	for(i=1;i<=10;i++)
	{
		printf("\nENTER A[%d]= ",i);
		scanf("%d",&a[i]);
	}
	for(i=1;i<10;i++)
	{
		for(j=10;j>=i+1;j--)
		{
			if(a[j-1]>a[j])
			{
				t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}
		}
	}
	printf("\nPRESS ENTER");
	
	printf("\nTHE SORTED ARRAY IN ASCENDING ORDER IS--\n");
	for(i=1;i<=10;i++)
		printf("%4d",a[i]);
	printf("\n");
	printf("\n");
        printf("\nTHE SORTED ARRAY IN DESCENDING ORDER IS--\n");
        for(i=10;i>0;i--)
        printf("%4d",a[i]);
        
        printf("\n");
 
	exit(0);
}
