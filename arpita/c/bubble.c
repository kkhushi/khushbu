#include<stdio.h>
int main(void)
{
  int i,j,a[5],t;
  
  printf("\nEnter 5 numbers:\n");
  for(i=0;i<=4;i++)
    {   
      scanf("\n%d",&a[i]);
    }

  for(i=0;i<4;i++)
    {   for(j=0;j<4;j++)
          {  if(a[j]>a[j+1])
                  { t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                  }
         }
    }
    
printf("\nThe numbers sorted in ascending order are:");
for(i=0;i<5;i++)
   {  printf("\n%d\n",a[i]);
   }
 

  for(i=0;i<4;i++)
    {   for(j=0;j<4;j++)
          {  if(a[j]<a[j+1])
                  { t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                  }
         }
    }
 

printf("\nThe numbers sorted in descending order are:");
for(i=0;i<5;i++)
   {  printf("\n%d\n",a[i]);
   }

return(0);
}      

