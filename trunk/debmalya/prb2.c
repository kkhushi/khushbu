#include <stdio.h>
#include <math.h>

void add();
void mul();
void sub();
void div();
void sqrtt();

void main(){
	int a; 

	cal:
	printf("enter 1 to add\nenter 2 to sub\nenter 3to multiply\nenter 4 to divide\nenter 5 to find square root\nenter any other to quit\nenter option : ");
	scanf("%d",&a);

switch (a){
	case 1 : 
		add();
		break;
	case 2 :
		sub();
		break;
	case 3 :
		mul(); break;
	case 4 :
		div(); break;
	case 5 :
		sqrtt(); break;
	default :
		printf ("Thank you...");
	}

}

void add(){
	int a, b; 
printf("enter 2 numbers to add");
scanf("%d%d",&a,&b);
printf("The ans is : %d", a+b);
}

void sub(){
	int a, b; 
printf("enter 2 numbers to sub");
scanf("%d%d",&a,&b);
printf("The ans is : %d", a-b);
}

void div(){
	int a, b; 
printf("enter 2 numbers to div");
scanf("%d%d",&a,&b);
printf("The ans is : %d", a/b);
}

void mul(){
	int a, b; 
printf("enter 2 numbers to mul");
scanf("%d%d",&a,&b);
printf("The ans is : %d", a*b);
}

void sqrtt(){
int a;
printf("enter number to find sqrt");
scanf ("%d",&a);
printf ("sqrt of %d is : %f",a,sqrt((double) a));
}
