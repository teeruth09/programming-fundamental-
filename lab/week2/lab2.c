/*1.รับตัวเลขเก็บไว้ในตัวแปร n
2.i=2
3.ทำงานต่อไปนี้ซ้ำเมื่อ i<=n
  1.ถ้าnหารiแล้วเศษ=0
    1.n=n/i
    2.ถ้าn=1
        1.ถ้าเป็นจริงแสดงผลค่า i
        2.ถ้าเป็นเท็จแสดงผลค่า i x
  2.ถ้าnหารiแล้วเศษไม่เท่ากับ0
    1.เพิ่มค่าi
*/


#include<stdio.h>
int main(){
    int n,i=2;
    printf("Enter number:");
    scanf("%d",&n);
        while (i<=n)
        {
            if(n%i==0){
                n=n/i;
                if(n==1){
                printf("%d",i);
                }
                else{
                    printf("%d x ",i);
                }
            }
            else{
                i++;
            }
        }     
    return 0;
}

