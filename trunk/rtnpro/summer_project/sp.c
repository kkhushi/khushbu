#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   FILE *p1, *p2;
   char c, phone_no[20],usr_name[20],passwd[20];
   
  
   printf("Enter phone number: ");
   scanf("%s", phone_no);
   printf("Enter User Name: ");
   scanf("%s", usr_name);
   printf("Enter password: ");
   scanf("%s", passwd);

   p1 = fopen("wvdial.conf.bak", "r");
   p2 = fopen("wvdial.conf", "w");

  if ((p1=fopen("wvdial.conf.bak","r"))==NULL)
    printf("\nCannot open file!!!\n");

  else{
	for(;(c=getc(p1))!=';';){
	 fputc(c,p2); 
	 }
         
         for(;(c=getc(p1))!='=';)
	   {
	     fputc(c,p2);
	   }
         fprintf(p2,"= %s", phone_no);
	 for(;(c=getc(p1))!='\n';);
 	 
         fputc('\n', p2);

    /*Writing the User name*/
        for(;(c=getc(p1))!=';';){
         fputc(c,p2); 
         }
         
         for(;(c=getc(p1))!='=';)
           {
             fputc(c,p2);
           }
         fprintf(p2,"= %s", usr_name);
         for(;(c=getc(p1))!='\n';);
         
         fputc('\n', p2);

       /*Writing password*/
         for(;(c=getc(p1))!=';';){
         fputc(c,p2); 
         }
         
         for(;(c=getc(p1))!='=';)
           {
             fputc(c,p2);
           }
         fprintf(p2,"= %s", passwd);
         for(;(c=getc(p1))!='\n';);
         
         fputc('\n', p2);
        for(;(c=getc(p1))!=EOF;)
           fputc(c,p2);



      }

fclose(p1);
fclose(p2);

exit(1);
return 0;

}
