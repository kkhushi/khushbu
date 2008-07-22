//string.c

#include<stdio.h>

int len(char* str){               //returns length of string
   int l=0;
   while(*str++ != '\0'){
     l++;
   }
   return l;
}

int compare(char *str1 ,char *str2){    //campare given strings
   while (*str1 == *str2++)
       if (*str1++=='\0')
          return(0);
   return(*str1 - *(--str2));
} 
 
    
int palindrome(char *str ){       //checks palindrome 
   int flag = 0;
   char *temp = str;
   while(*temp!='\0') temp++;
   temp--;
   while(str < temp){
      if(*(str++)!=*(temp--)){
         flag = 1;
         break;
      }
   } 
   return(flag);
}

void reverse(char *str){          //reverses the string
   char *temp;
   char swap;
   temp = str;
   while(*temp!='\0') temp++;
   temp--;
   while(str < temp){
      swap = *str;
      *str++ = *temp;
      *temp-- = swap;
   }
}
 
  
void find(char *str,int start,int end){      //finds substring between two indices
   char sub[end-start+1];
   int i;
   while(start--)str++;
   for(i =0;i<end-start-1;i++)
      sub[i] = *(str++);   
   sub[i]= '\0';
   printf("\tYou found %s\n",sub);  
}   

void concate(char *str1,char *str2){                    //concatenates strings
   while(*str1!='\0')str1++;

   do{
     *(str1++) = *(str2++);
   }while(*str2!='\0');
   *str1='\0';
} 

int main(){
   int choice=1,i,j;
   char str1[30], str2[30];
   printf("You want to play around with Strings...\n\nEnter your string:\t");
   scanf("%s",str1);
   printf("Your string is %s",str1);
   fflush(stdin);
   printf("\n\n**************Choose From Menu***************\n\n");
   printf("1.\tFind length\n2.\tCompare\n3.\tCheck palindrome\n4.\tReverse\n5.\tFind substring\n6.\tConcatenate\n7.\tChange String\nPress 0 to EXIT\n");
   while(choice){
      printf("\nEnter Your Choice:\t");
      scanf("%d",&choice);
      switch(choice){
      case 1:
         printf("\tThe Length of %s is %d\n",str1,len(str1));
         break;
      case 2:
         printf("\tEnter second string:\t");
         scanf("%s",str2);
         printf("\tString to compare is %s\n", str2);
         i = compare(str1,str2);
         if(i > 0)printf("\t%s is greater than %s\n",str1,str2);
         else if(i < 0)printf("\t%s is greater than %s\n",str2,str1);
              else printf("\tBoth strings are equal\n");
         break;
      case 3:
         i = palindrome(str1);
         if(i==0)printf("\t%s is palindrome\n",str1);
         else printf("\t%s is not a palindrome\n",str1);
         break;
      case 4:
         reverse(str1);
         printf("\tThe reversed string is %s\n",str1);
         break;
      case 5 :
         printf("\tEnter start index:\t");
         scanf("%d",&i);
         printf("\tEnter number of characters to pick:\t");
         scanf("%d",&j);
         find(str1,i,j);
         break;
      case 6 :
         printf("\tEnter second string:\t");
         scanf("%s",str2);
         concate(str1,str2);
         printf("\tString after concatenation\t%s\n",str1);
         break;
      case 0:
         printf("\nExiting.....................\n\n\n");
         return 0;
      case 7:
         printf("\tEnter new string:\t");
         scanf("%s",str1);
         printf("\tNew string is\t%s\n",str1);
         break; 
      default : 
         printf("\tInvalid choice\n"); 
      }
   }   
   return 0;
}
/*You want to play around with Strings...

Enter your string:      khushbu
Your string is khushbu

**************Choose From Menu***************

1.      Find length
2.      Compare
3.      Check palindrome
4.      Reverse
5.      Find substring
6.      Concatenate
7.      Change String
Press 0 to EXIT

Enter Your Choice:      1
        The Length of khushbu is 7

Enter Your Choice:      2
        Enter second string:    megha
        String to compare is megha
        megha is greater than khushbu

Enter Your Choice:      2
        Enter second string:    aditya
        String to compare is aditya
        khushbu is greater than aditya

Enter Your Choice:      2
        Enter second string:    khu
        String to compare is khu
        khushbu is greater than khu

Enter Your Choice:      2
        Enter second string:    khushbu
        String to compare is khushbu
        Both strings are equal

Enter Your Choice:      3
        khushbu is not a palindrome

Enter Your Choice:      4
        The reversed string is ubhsuhk

Enter Your Choice:      5
        Enter start index:      2
        Enter number of characters to pick:     4
        You found hsuh

Enter Your Choice:      5
        Enter start index:      2
        Enter number of characters to pick:     3
        You found hsu

Enter Your Choice:      6
        Enter second string:    khushbu
        String after concatenation      ubhsuhkkhushbu

Enter Your Choice:      3
        ubhsuhkkhushbu is palindrome

Enter Your Choice:      7
        Enter new string:       khushbu_mohta
        New string is   khushbu_mohta

Enter Your Choice:      1
        The Length of khushbu_mohta is 13

Enter Your Choice:      9
        Invalid choice

Enter Your Choice:      0

Exiting.....................
*/
