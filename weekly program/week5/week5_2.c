//จงเขียนฟังก์ชั่นเพื่อหาว่าตัวเลขที่รับเข้ามาเป็นจำนวนเฉพาะหรือไม่ (Level 3)
#include<stdio.h>
int main()
{
    int n,check = 0;
            scanf("%d", &n);
            for (int i = 2; i <= n / 2; ++i)
            {    
                if (n % i == 0)
                {
                    check = 1;
                    break;
                }
            }
            if (n == 1)
            {
                printf("1 is neither prime nor composite.");
            }
            else 
            {
                if (check == 0)
                    printf("%d is a prime number.", n);
                else
                    printf("%d is not a prime number.", n);
            }
    return 0;
}