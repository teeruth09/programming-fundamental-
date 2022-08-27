//จงเขียนฟังก์ชั่น factorial (Level 3)

#include<stdio.h>
int main()
{
int n, i, fact = 1;
printf("Enter a Number to Find Factorial: ");
scanf("%d",&n);

if (n < 0)
printf("Error! You have entered negative number and Factorial for negative number does not exist.");
else
{
for(i = 1; i <= n; ++i)
{
fact =fact*i;              
}
printf("%d! = %d", n, fact);
}
return 0;
}