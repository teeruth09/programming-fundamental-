//74. รับค่าตัวเลข 2 จำนวน เก็บใน x และ y ตามลำดับ จากนั้นให้ทำการสลับค่ากัน โดยห้ามสร้างตัวแปรเพิ่ม (Level 5)
#include <stdio.h>
void swap()
{
    int a, b;
    a = a + b;
    b = a - b;
    a = a - b;
}
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("Before Swap: \n");
    printf("a: %d \n", a);
    printf("b: %d \n", b);
    swap();
    printf("After Swap: \n");
    printf("a: %d \n", a);
    printf("b: %d \n", b);
    return 0;
}