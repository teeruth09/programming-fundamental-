//รับข้อมูล String 1 ชุด แล้วแสดงผลลัพธ์โดยเปลี่ยนตัวอักษรตัวพิมพ์เล็กให้กลายเป็นตัวอักษรตัวพิมพ์ใหญ่ และตัวอักษรตัวพิมพ์ใหญ่กลายเป็นตัวอักษรตัวพิมพ์เล็ก
#include<stdio.h>
#include <string.h> 

void stringswap(char *s)
{
    int i,j;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
      else if ( (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s[i] = s[i] + 32;
        }
    }
    for(i = 0;s[i] !='\0';i++)
    {
            while (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] == '\0'))
            {
                for (j = i; s[j] != '\0'; ++j)
                {
                    s[j] = s[j + 1];
                }
                s[j] = '\0';
            }
    }
}
int main()
{
    char s[1000];  
    int i;
    printf("Input : ");
    gets(s);
    stringswap(s);   //Using  fuction
    printf("Output : %s\n",s);
}
