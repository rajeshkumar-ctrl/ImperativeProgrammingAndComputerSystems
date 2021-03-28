#include<stdio.h>
int main()
{
int n_m;
scanf("%d",&n_m);
printf("%d",n_m);
for(int i=0; n_m!=1;i++)
{
    if(n_m%2==0)
    {
        n_m=n_m/2;
        printf(",%d",n_m);
    }
    else if(n_m%2==1)
    {
        n_m=3*n_m+1;
        printf(",%d",n_m);
    }
}
return 0;
}
