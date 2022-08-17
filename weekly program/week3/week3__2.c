//จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นสามเหลี่ยมที่มีด้านเท่ากับตัวเลขที่รับเข้ามา  (Level 2)

#include<stdio.h>
int main()
{
   int n;
   printf("Enter number:");
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
   }
   return 0;
}