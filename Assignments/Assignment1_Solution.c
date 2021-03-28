#include<stdio.h>
int main()
{
 int i,j;
 int number;
 scanf("%d",&number);

 for(i=1;i<=number;i++)
 {
     for(j=1;j<=2*number+1;j++)
     {
        if(j==number+1)
        {
            printf("  ");
        }
         else if((j>=number-i+1)&&(j<=number+i+1))
         {
            printf("X");
         }
        else
        {
            printf(" ");
        }

    }
        printf("\n");
 }
 return 0;
}
