#include<stdio.h>
#include<stdlib.h>

void main(){
int a=0;
static char str[100];
gets(str);

do{
if(str[a]>78)
{str[a]=65+str[a]-78;a++;}
else if (str[a]>109)
{str[a]=97+str[a]-109;a++;}

else 
str[a]=str[a]+13;
a++;

}while(str[a]!=NULL);

puts(str);

}
