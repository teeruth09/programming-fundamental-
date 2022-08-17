/*ให้ P(x) คือผลรวมตัวเลขตั้งแต่ 1..(x-1) ที่หาร x ได้ลงตัว เช่น P(28) = 1+2+4+7+14 = 28 ให้
เขียนการทํางานในการหาตัวเลข 1-10,000 ว่ามีตัวเลขใดบ้างที่ให้ค่า P(x)=x 
*/
#include<stdio.h>
int main()
{
    int sum=0;
for(int i=1;i<=10000;i++)
{
    for(int j=1;j<i;j++)
    {
        if(i%j==0)
        {
            sum=sum+j;
        }
        
    }
    if(i==sum)
    {
        printf("P(x)=x is %d\n",i);
        
    }
    sum=0;
}
    return 0;
}


