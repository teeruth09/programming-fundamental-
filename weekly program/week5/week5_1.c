//จงเขียนฟังก์ชั่นเพื่อหาว่าตัวเลขที่รับเข้ามาเป็นจำนวนเฉพาะหรือไม่ (Level 3)
#include<stdio.h>
int isPrime(int);
int main()
{
    int x;
    scanf("%d",&x);
    if(isPrime(x)==1) printf("prime number");
    else printf("not prime number");
    return 0;
}
int isPrime(int a)
{
    int b;
     int c=0;
    for(b=2;b<=a;b++)
    {
       if(a%b==0)
       {
            c++;
       }   
    }
    if(c==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}