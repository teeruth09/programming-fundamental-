//59. จงเขียนโปรแกรมรับตัวอักษร 1 ชุด แล้วแสดงผลลัพธ์จากหลังมาหน้า (Level 3)

#include<stdio.h>
#include<string.h>
int main()
{
     char str[100];
    int i=0;
    printf("Input:");
   // gets(str);
   scanf("%[^\n]s",str);
  //  printf("Original String: %s",str);
    printf("Output:");
    i = strlen(str)-1;
    while(i>=0)
    {
       // putchar(str[i]);
        printf("%c",str[i]);
        i--;
    }
    return 0;
}