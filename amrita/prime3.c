#include<stdio.h>
int main()
{  int n,i,c=0,j,d=1;
     printf("\nEnter the no. of prime no.'s you wanna see:\n");
       scanf("%d",&n);
     j=1;
     while(d<=n)
     { for(i=2;i<=j/2;i++)
      {   if(j%i==0)
            {    c++;
                   break;
} }
   if(c==0)
    {printf("\n%d",j);
    printf("\n");
     d++;
    }
    j++;
   c=0;
}
return(0);
}

