#include<stdio.h>
#include<math.h>
void prime(int);
void perfect(int);
	
int main(){
	int n=0;
	int ch=0;
	printf("\n\n\n********Choose From Menu*********\n1.\tPrime numbers\n2.\tPerfect numbers\n3.\tExit\n");
	printf("\n\nEnter your choice:\t");
	scanf("%d",&ch);
	do{
	
		
			
		switch(ch){
		case 1:
			printf("\n\tEnter value for N :\t");
			scanf("%d",&n);
			prime(n);
			n = 0;
			break; 
	 	case 2:
			printf("\n\tEnter value for N :\t");
			scanf("%d",&n);
			perfect(n);
			n = 0;
			break;
	        default:
			printf("\n\tInvalid Entry Choose 1, 2 or 3\n");

		}
	
		printf("\n\nEnter your choice:\t");
		scanf("%d",&ch);
	
	}while(ch!=3);
	return 0;
}

void prime(int n){
	long int x ,count = 0,i,j;
	x = n;
        printf("\tThe first %d prime numbers are\t",n);
        for(i = 2;;i++){
             for(j = i-1;j>2;j--){
                   if(i%j==0){
                         count++;
                   }
              }
              if(count==0){
                   printf("%d ",i);
                   x--;
              }else
                   count = 0;
              if(x == 0)break;
         }
}

void perfect(int n){
	long int x, sum = 0, i , j;
	x = n;
        printf("\tThe first %d perfect numbers are\t",n);
	for(i = 3;;i++){
		for(j = i-1;j>0;j--){
			if(i%j==0){
				sum +=j;
			}
		}
		if(sum == i){
			printf("%d ",i);
			x--;
		}	
		
		sum = 0;
		if(x==0)break;
	}
}
