#include <stdio.h>
#include <string.h>


struct dict {                  // creating dictionary.. aGAIN Oxford ! haha
	int code;
	char dict_str[5];
			} ; 
struct dict dctnry[500];


int chk_dict(int index){    // Directory Checking function
 
int i=0,a=1000;

	for(i=0;i<=300;i++){
			
	if (dctnry[i].code==index){
		a=i;
		break;}
	else{
	a=0;}	
	}
	
return (a);
}



int chk_dict_wc(char *wc_ptr){    // Directory Checking function for wc

int i=0,a=1000,b=0;
char wc_1[6]={0};
strcpy(wc_1,wc_ptr);

	for(i=0;i<=300;i++){
	
	b=strcmp(wc_1, dctnry[i-1].dict_str);
	
	if (b==0){
		a=i;
		break;}
	else{
	a=0;}	
	}
	
return (a);
	
}


void add_dict(char *wc_add_ptr){    // function to add wc in dict
int i=256, count =256;
	
	while (dctnry[i].code!=0){    // finding the last element in dictionary
		count++;i++;
	 			}
	
	strcpy(dctnry[count].dict_str, wc_add_ptr); //adding wc
	dctnry[count].code = dctnry[count-1].code+1;

}




main(){


FILE *fp;
int input=0, count=0, if_in_dict=0,flag=0;

char prev_inp[1]={0},wc[5]={0},output[5]={0};
char curr_op[1]={0};
char code_type='\0', letter_code='\0';

fp=fopen("haimabati.txt","w");  //Opening Output file.. it's for you :)


//building the dictionary... No error
for(count=0; count< 256; count++){
	dctnry[count].code=count;
	dctnry[count].dict_str[0]=count;}


// The main Engine...
do {
printf("\nIs this code a letter? Y/N (# to terminate) :");
code_type=getchar();

	if (code_type=='y' || code_type=='Y'){
		printf("\nenter coded letter : ");
		letter_code=getchar(); //dunno, but the first getchar is taking an extra whitespace, so...
		letter_code=getchar();  // This one is taking real Input...
		
		fprintf(fp,"%c",letter_code);
		
		if(flag==0){   //if it's first time in main loop
		//checking and setting the wc for adding in dict
		wc[0]=letter_code;
		if(chk_dict_wc(&wc)==0){ add_dict(&wc); }   // checking, if wc is in dict
		wc[0]=letter_code;}

		else

		wc[1]=letter_code;
		if(chk_dict_wc(&wc)==0){ add_dict(&wc); }   // checking, if wc is in dict
		wc[0]=letter_code;wc[1]='\0';
	}
	
	
	
	else if(code_type=='n' || code_type=='N'){

		printf("\nEnter compressed code :");								
		scanf("%d",&input);         // Obtaining input
	
				
		if_in_dict=chk_dict(input);
		
	

		if (if_in_dict!=0 ){        // Surely, any valid charecter will be in Dict.. :)
				
			strcpy(output,dctnry[if_in_dict].dict_str);
						
			if(flag==0){  //here it's checking whether it's the first time...
			wc[0]=output[0];}
			
			else{		//If not first time
			curr_op[0]=output[0];
			wc[strlen(wc)]=output[0];
			     }
		
			fprintf(fp,"%s",output);	
	
			if(chk_dict_wc(&wc)==0){ add_dict(&wc); } // checking, if wc is in dict
	
		}
	
	

		else // if control reaches here, that means, you've fumbled to enter right code
		{
		printf("\nInvalid input... Dekhe sune din dada...!\n");
		}

		strcpy(wc,output);
	}
	


	else if(code_type=='#'){   ///Termination
	printf("\n\nLZW Decompression\nAuthor : Debmalya Sinha...\n\nThankyou... \n");
	break;
	}

	
flag++; // this little flag is checking whether it's loop's first iteration
}while(code_type!='#');

fcloseall();  // cleaning upp the tracks...
}


