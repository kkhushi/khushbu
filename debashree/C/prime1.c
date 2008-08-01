#include<stdio.h>
#include<stdlib.h>
   int main(void)
{
   int n,c=1,m=0,i,j;
	printf("\nEnter the no of prime nos u want to see:\n");
	scanf("%d",&n);
	i=1;
	while(c<=n)
        {
	   for(j=2;j<i;j++)
           {
		if(i%j==0)
                {
		   m++;

                   break;
                }
	   }

		if(m==0)
        	{
		   printf("\n%d",i);
	           c++;
		}
             m=0;
	     i++;
         }

	return(0);
}
