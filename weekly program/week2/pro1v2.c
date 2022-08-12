//จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นจำนวนเท่ากับตัวเลขที่รับเข้ามา ดังตัวอย่าง (Level 1)
#include<stdio.h>
int main()
{
    int n,i=1;
    printf("Enter n:");
    scanf("%d",&n);
    printf("%d\n",n);
    while(i<=n)
    {
        printf("*");
        i++;
    }
    return 0;
}
