#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=2*a-1;j++)
        {
            if(j<=i|| j>= 2*a-i || i==a)
            {
                printf("*");
            }   
            else
            {
                printf(" ");           
            }     
        }
         printf("\n");   
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=2*a-1;j++)
        {
            if(j<=a-i || j>= a+i)
            {
                printf("*");
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
