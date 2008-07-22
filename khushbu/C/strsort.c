#include<stdio.h>
#include<string.h>

int compare(char *str1 ,char *str2){    //campare given strings
   while (*str1 == *str2++)
       if (*str1++=='\0')
          return(0);
   return(*str1 - *(--str2));
} 

struct string{
   char str[20];
};

int main()
{
   int n,i,j;
   char temp[20];

   printf("Enter size of array:\t");
   scanf("%d",&n);

   struct string arr[n];

   printf("Enter array elements:\n");
   for(i = 0;i < n; i++)
      scanf("%s",arr[i].str);

   for(i = 0; i < n; i++){
      for(j = i+1; j < n; j++){
         if(compare(arr[i].str,arr[j].str) > 0){
            strcpy(temp,arr[i].str);   
            strcpy(arr[i].str,arr[j].str);
            strcpy(arr[j].str,temp);
         }
      }
   }
   printf("\nThe strings in ascending order:\n");
   for(i = 0; i< n; i++)
      printf("%d.\t%s\n",i+1,arr[i].str);

   printf("\nThe array in decending order:\n");
   for(i = n-1,j=1; i>0,j<n+1;j++, i--)
      printf("%d.\t%s\n",j,arr[i].str);

return 0;
}
/*
Enter size of array:    10
Enter array elements:
khushi
prakhar
amrita
bose_arutra
kushal
kishangoyal
ria
rtnpro
tuxmaniac
arpita

The strings in ascending order:
1.      amrita
2.      arpita
3.      bose_arutra
4.      khushi
5.      kishangoyal
6.      kushal
7.      prakhar
8.      ria
9.      rtnpro
10.     tuxmaniac

The array in decending order:
1.      tuxmaniac
2.      rtnpro
3.      ria
4.      prakhar
5.      kushal
6.      kishangoyal
7.      khushi
8.      bose_arutra
9.      arpita
10.     amrita
*/
