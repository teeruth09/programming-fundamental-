#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
//set color
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
//draw ship
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
//erase ship
void erase_ship(int x, int y)
{
	//COORD c = { x, y };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
//bullet
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("^");	
}
//erase_bullet
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}

int main()
{
	setcursor(0);
	
	char ch = ' ';
	int x = 38, y = 20;

	char direction = '0';
	
	int statebullet[5] = { 0,0,0,0,0 };
	int bx[5];
	int	by[5];
	int n = 0;
	draw_ship(x, y);
	do {
		
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a')
			{
				direction = 'L'; //left
			}
			if (ch == 'd')
			{
				direction = 'R';//right
			}
			if (ch == 's')
			{
				direction = 'S';//Stop
			}
			if (ch == ' ' && statebullet[n] == 0)
			{
				statebullet[n] = 1; //statebullet On
				bx[n] = x + 3;
				by[n] = y - 1;
				n++;
				//reset bullet
				if (n > 4 )
				{
					n = 0;
				}
			}
			fflush(stdin);
		}

		//check
		if (direction == 'L' && x != 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direction == 'R' && x != 80)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 'S' || x == 0 || x == 80)
		{
			draw_ship(x, y);
		}
	//Run statebullet
		for (int j = 0; j < 5; j++)
		{
			if (statebullet[j] == 1)
			{
				erase_bullet(bx[j], by[j]); //erase current bullet 
				if (by[j] == 2)
				{
					statebullet[j] = 0; //ออกจอแล้วถึงเคลียร์
				}
				else
					draw_bullet(bx[j], --by[j]); //วาดใหม่ด้านบน
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}