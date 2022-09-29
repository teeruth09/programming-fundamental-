//รับข้อมูล String 1 ชุด แล้วแสดงผลลัพธ์โดยเปลี่ยนตัวอักษรตัวพิมพ์เล็กให้กลายเป็นตัวอักษรตัวพิมพ์ใหญ่ และตัวอักษรตัวพิมพ์ใหญ่กลายเป็นตัวอักษรตัวพิมพ์เล็ก
#include<stdio.h>
int main()
{
    char s[100];
    char *pointer;
    printf("Input : ");
    scanf("%s",s);
    pointer=s;
    printf("Output : ");
    
    while(*pointer != '\0')
    {
        if(*pointer >= 'a' && *pointer <= 'z')
        {
            printf("%c",*pointer-32);
        }
        else if(*pointer >= 'A' && *pointer <= 'Z')
        {
            printf("%c",*pointer+32);
        }
        pointer++;
    }
    return 0;
}