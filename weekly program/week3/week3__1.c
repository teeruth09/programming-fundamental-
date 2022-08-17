//จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นสามเหลี่ยมที่มีด้านเท่ากับตัวเลขที่รับเข้ามา  (Level 2)

#include<stdio.h>
int main()
{
    int a,c,n;
    printf("Enter number:");
    scanf("%d",&n);
    a=1;
    while(a<=n*n)
    {
        c=a/n;
        if(n*c+c>=a){
            printf("*");
        }
        if(a%n==0&&a!=1){
            printf("\n");
        }
    a=a+1;
    }
    return 0;
}