#include<stdio.h>
void main(){
int arr[10],a=0,i,j,temp;
printf("Enter 10 numbers");
for(a=0;a<10;a++){scanf("%d",&arr[a]);} //User inputs. Let them do some work :)

for(i=0;i<10;i++){                      //First Pass...
	
		for (j=1;j<10-i;j++){         //Main Sorting, 2nd pass...
			if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;}
		}
	
	
}
printf("Now, the sorted array by Bubble Sort Algorithm is : \n");
for(a=0;a<10;a++){printf("%d ",arr[a]);}
}
