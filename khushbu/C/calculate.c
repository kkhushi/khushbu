//calculate.c

#include<stdio.h>
#include<math.h>

int main(){

   float num1,num2;
   int ch = 0;

   printf("\n\n*******************KCalculator**********************\n");
   printf("1.\tAdd n1+n2\n2.\tSubtract n1-n2\n3.\tMultiply n1*n2\n4.\tDivide n1/n2 \n5.\tSquare n1\n6.\tSquareroot n1\n7.\tExit\n");

   do{
      printf("\n\nEnter your choice :\t");
      scanf("%d",&ch);
      switch(ch){
         case 1:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1);
            printf("\tEnter n2:\t");
            scanf("%f",&num2);
            printf("\tSum is %f",num1+num2);
            break;
         case 2:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1); 
            printf("\tEnter n2:\t");
            scanf("%f",&num2);
            printf("\tDifference is %f",num1-num2);
            break;
         case 3:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1); 
            printf("\tEnter n2:\t");
            scanf("%f",&num2);
            printf("\tProduct is %f",num1*num2);
            break;
         case 4:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1); 
            printf("\tEnter n2:\t");
            scanf("%f",&num2);
            printf("\tSum is %f",num1/num2);
            break;
         case 5:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1); 
            printf("\tSquare is %f",num1*num1);
            break;
         case 6:
            printf("\n\tEnter n1:\t");
            scanf("%f",&num1); 
            printf("\tSquareroot is %f",sqrt(num1));
            break;
         case 7:
            printf("\tExiting.............\n");
            break; 
         default:
            printf("\n\nInvalid Entry Choose 1, 2, 3, 4, 5, 6 or 7");
      }
   }while(ch!=7);
   return 0;
}


/*
 *
 * *******************KCalculator**********************
 * 1.      Add n1+n2
 * 2.      Subtract n1-n2
 * 3.      Multiply n1*n2
 * 4.      Divide n1/n2 
 * 5.      Square n1
 * 6.      Squareroot n1
 * 7.      Exit
 *
 *
 * Enter your choice :     1
 *
 *         Enter n1:       23
 *         Enter n2:       34
 *         Sum is 57.000000
 *
 * Enter your choice :     2
 *
 *         Enter n1:       34
 *         Enter n2:       23
 *         Difference is 11.000000
 *
 * Enter your choice :     3
 *
 *         Enter n1:       45
 *         Enter n2:       12
 *         Product is 540.000000
 *
 * Enter your choice :     4
 *
 *         Enter n1:       56
 *         Enter n2:       32 
 *         Sum is 1.750000
 *
 * Enter your choice :     5
 *
 *         Enter n1:       23
 *         Square is 529.000000
 *
 * Enter your choice :     6
 *
 *         Enter n1:       3445
 *         Squareroot is 58.694122
 *
 * Enter your choice :     7
 *        Exiting.............
 *khushbu@khushbu-desktop:~$ 
 */
