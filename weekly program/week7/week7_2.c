//25. จงเขียนโปรแกรมรับตัวเลข 1 ตัวแล้วให้คอมพิวเตอร์วาดรูปเครื่องหมาย * เป็นปิระมิดที่มีความสูงเท่ากับตัวเลขที่รับเข้ามา ดังตัวอย่าง (Level 3)
#include <stdio.h>
void printStar(int numStars){  
    int i;  
    for (i=1; i<=numStars; i = i+1)  
        printf("*");  
}  
void printSpace(int numSpaces){  
    int i;  
    for (i=1; i<=numSpaces; i = i+1)  
        printf(" ");  
}  
 
int main()
{  
    int num;
    scanf("%d",&num);
        for ( int i = 0; i < num; i++ )
        {
            printSpace( num - i - 1 );
            printStar( 2 * i + 1 );
            printf("\n");
        }
        printf("\n"); 
    return 0;
}