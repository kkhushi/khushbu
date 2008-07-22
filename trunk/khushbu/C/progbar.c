#include<stdio.h>
#include<unistd.h>

void udelay(int sec){
   usleep(sec);
}

void progressbar(int i){
   int j;

   printf("[%d%]",i*5);
   for(j=0;j<i;j++)printf("##");
   printf("\r");
   fflush(stdout);
   }
int main(){
   int i;
   printf("Progress Bar.....\n");
   for(i=0;i<20;i++){
      progressbar(i+1);
   udelay(300000);}
   printf("\n");
   return;
}
   
