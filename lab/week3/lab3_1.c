/*ให้เขียนการทํางานของการหาผลบวกของตัวเลขโดดที่ไม่ใช่ 0 ทุกตัวในตัวเลขที่ป้อน ไปเรื่อยๆ
จนกว่าจะเป็นเลขหลักเดียวเช่นเมื่อป้อน input เป็น 123456 จะได้ผลลัพธ์คือ 123456 -> 21-> 3*/

#include<stdio.h>
int main()
{
    int x,i;
    int sum=0;
    printf("Enter x:");
    scanf("%d",&x);
    printf("%d",x);
    while(x > 10)
    {
        while(x%10 > 0)
        {
            i=x%10;
            sum=sum+i;
            x=x/10;
        }
        x=sum;
        sum =0;
        
    }
    printf("->%d",x);
    return 0;
}