//จงเขียนฟังก์ชั่น factorial (Level 3)

#include <stdio.h>
long int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * factorial(n - 1);
}

int main()
{
  int n;
  printf("Enter a Number to Find Factorial: ");
  scanf("%d", &n);
  printf("%d! = %d",n, factorial(n));
  return 0;
}