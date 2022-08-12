#include <stdio.h>
int main()
{
    int x, y;
    int i = 2, n = 1;
    printf("Enter first number:");
    scanf("%d", &x);
    printf("Enter second number:");
    scanf("%d", &y);
    while (i <= 13)
    {
        if (x % i == 0 && y % i == 0)
        {
            n = n * i;
            x = x / i;
            y = y / i;
        }
        else
        {
            i++;
        }
    }
    printf("Greatest common divisor = %d", n);
    return 0;
}

/* 
1.รับตัวเลขเก็บไว้ในตัวแปรx,y
2.กำหนดค่า i=2,n=1
3.ทำงานต่อไปนี้ซ้ำเมื่อ i<13
    1.ถ้าxหารiแล้วเศษ=0 และ yหารiแล้วเศษ=0
        1.n=n*i
        2.x=x/i
        3.y=y/i
    2.ถ้าเป็นเท็จ
        1.เพิ่มค่าi
4.แสดงผลลัพท์ของ n