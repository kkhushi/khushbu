#include <stdio.h>
#include <string.h>

struct dict {             // creating dictionary.. Oxford ! haha
	int code;
	char dict_str[5];
			} ; 
struct dict dctnry[500];



int chk_dict(void *wc_ptr){    // Directory Checking function
 printf("chk = %s", wc_ptr);
int i=0,a=1000,b=0;
char wc_1[6]={0};
strcpy(wc_1,wc_ptr);

	for(i=0;i<=300;i++){
	
	b=strcmp(wc_1, dctnry[i-1].dict_str);
	
	if (b==0){
		a=i+1;
		break;}
	else{
	a=1;}	
	}
	
return (a-1);
	
}





void add_dict(void *wc_add_ptr){    // function to add wc in dict
int count =256;
	
	while (dctnry[count].code!='\0'){    // finding the last element in dictionary
	count++;
	 }
	
	strcpy(dctnry[count].dict_str, wc_add_ptr); //adding wc
	dctnry[count].code = dctnry[count-1].code+1;


}




int main(){


FILE *fp;
int count=0,inp_len=0, j=0, if_in_dict=10;
int match_found=0; // This is the match found FLAG

char input[100];
char nc[5]={0}, w[5]={0},wc[6]={0};
char output[][200]={0};  // not enough?



fp=fopen("haima.txt","w");  


for(count=0; count< 256; count++){
	dctnry[count].code=count;
	dctnry[count].dict_str[0]=count;}




printf("\nEnter uncompressed text(AND PUT # IN THE END OF THE STRING):");								
scanf("%s", &input);         // Obtaining input
inp_len=strlen(input); //obtaining the length of the input string


//Main engine
for(count=0;count<inp_len; count++){
	
	nc[0]=input[count];
	strcpy(wc,w);	// fixing wc here... 
	strcat(wc,nc);   // concateneting w and c   
	
	

	if_in_dict=chk_dict(&wc);
		
	
	
	if (if_in_dict!=0 && match_found!=0){  
		strcpy(w,wc);
		match_found=dctnry[if_in_dict-1].code;
		
	}
	


	else if (if_in_dict!=0 && match_found==0){  
		strcpy(w,wc);
		match_found=dctnry[if_in_dict-1].code;
		
	}


	else if (if_in_dict==0 && match_found!=0){
	add_dict(&wc);
	
	w[1]='\0';w[2]='\0';w[3]='\0';	
	w[j]=input[count];
	fprintf(fp,"%d\n",match_found); // printing the match value
	match_found=0;   // setting the FLAG false again	
		
	}
	

	else 
	{
	add_dict(&wc);
	fprintf(fp,"%s\n",w);	
	w[1]='\0';w[2]='\0';w[3]='\0';	
	w[j]=input[count];
		
	}

}

fcloseall(); return 0;
}


