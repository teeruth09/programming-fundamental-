//จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นจำนวนเท่ากับตัวเลขที่รับเข้ามา ดังตัวอย่าง (Level 1)
#include<stdio.h>
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
    {
        printf("*");
    }
    return 0;
}