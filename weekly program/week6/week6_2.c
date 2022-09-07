//59. จงเขียนโปรแกรมรับตัวอักษร 1 ชุด แล้วแสดงผลลัพธ์จากหลังมาหน้า (Level 3)

#include<stdio.h>
#include<string.h>
int main()
{  
    char *start,*end,str[100];
    end = str;
    start = str;
    end = start;
    
    printf("Input:");
    scanf("%[^\n]s",str);
    while(*end != '\0')
    {
        end++;
    }
    printf("Output:");
    while(end-start >= 0 )
    {
        printf("%c",*end);
        end--;
    }
    return 0;
}
