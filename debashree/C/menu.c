#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{ int c,i,j,k,n,a,b,d,e,f,g,l,m,o;
   while(1)
{ printf("\n\nenter any number");
  printf("\n\n1:addition\n2:subtraction\n3:multiplication\n4:square\n5:squareroot\n6:exit\n");
  scanf("%d",&c);
  switch(c)
{ case 1:

    printf("\nenter 2 numbers:");
     scanf("%d%d",&a,&b);
     j= a+b;
     printf("the sum is %d ",j);
     break;
case 2:
    printf("enter 2 numbers:");
     scanf("%d%d",&d,&e);
     if(d>=e)
     {
      k=d-e;
     }
      else
      k=e-d;
      printf("the difference is %d ",k);
      break;
case 3:
      printf("\nenter 2 numbers f and g:");
     scanf("%d%d\n",&f,&g);
     l= f*g;
     printf("the product is %d ",l);
     break;
case 4:
     printf("\n enter any positive number n:");
     scanf("%d",&n);
     m=n*n;
     printf("the square of given number is:%d",m);
     break;
case 5:
      printf("\n enter any positive number o:");
      scanf("%d",&o);
      printf ("square root(%d): %f\n", o, sqrt (o));
      break;

case 6:
exit(0);
}}
return(0);
}
