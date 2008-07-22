//sort.c

#include<stdio.h>

int main(){
   int n, i, j, temp;
   int arr[30];

   printf("Enter the length of array:\t");
   scanf("%d",&n);
   
   printf("Enter the elements for array:\n");
   for(i = 0; i < n; i++)
      scanf("%d",&arr[i]);
   
//sorting the array
   for(i = 0;i < n; i++){
      for(j = i+1; j< n; j++){
         if(arr[i] > arr[j]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }

   printf("\nThe list in ascending order:\n");
   for(i=0;i<n;i++)
      printf("%d ", arr[i]);
   
   printf("\nThe list in descending order:\n");
   for(i=n-1;i>=0;i--)
      printf("%d ", arr[i]);
   return 0;
}

/*Output

Enter the length of array:      12
Enter the elements for array:
12
23
34
45
21
54
12
2
13
24
76
1

The list in ascending order:
1 2 12 12 13 21 23 24 34 45 54 76 
The list in descending order:
76 54 45 34 24 23 21 13 12 12 2 1 */
