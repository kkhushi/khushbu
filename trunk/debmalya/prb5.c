#include<stdio.h>
#include<stdlib.h>
void main(){
	int a=0, whtspc=0, dwt=0;
	static char str[200];
	gets(str);

	while(str[a]!=NULL)
	{
		if (str[a]==' '){
			++whtspc;++a;}
		else if (str[a]=='.'){
			++dwt;++a;}
		else
	++a;
	}

printf("The number of Characters in string is : %d", a);
printf("The number of Words in string is : %d", ++whtspc);
printf("The number of Lines in string is : %d", ++dwt);

}



