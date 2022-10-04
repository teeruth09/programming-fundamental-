#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>

// Set color
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Ship
void draw_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 4);
	printf("<-0->");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf("     ");
}
// Bullet
void draw_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 1);
	printf("^");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");
}
//Star
void drawStar()
{
	int x, y;
	x = rand() % 71 + 10; // (10,70)
	y = rand() % 6 + 2;   // (2,5)
	setcolor(3, 0);
	gotoxy(x, y);
	printf("*");
}
//Set cursor
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; 
	DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else {
		return buf[0];
	}
}

int main()
{
	setcursor(0);
	srand(time(NULL));
	char ch = ' ';
	int x = 38, y = 20;
	char direction = '0';
	int statebullet[5] = { 0,0,0,0,0 };
	int bulletX[5], bulletY[5];
	int score = 0;
	for (int i = 0; i < 20; i++)
	{
		drawStar();
	}
	setcolor(2, 0);
	draw_ship(x, y);
	int n = 0;
	do {
		if (_kbhit())
		{
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
			//Bullet Motion
			if (ch == ' ' && statebullet[n] == 0)
			{
				Beep(700, 100);
				statebullet[n] = 1; //statebullet On
				bulletX[n] = x + 2;
				bulletY[n] = y - 1;
				n++;
				//reset bullet
				if (n == 5)
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
				erase_bullet(bulletX[j], bulletY[j]); //erase current bullet 
				if (bulletY[j] > 0 && cursor(bulletX[j], bulletY[j] - 1) != '*')
				{
					draw_bullet(bulletX[j], --bulletY[j]);
				}
				else if (cursor(bulletX[j], bulletY[j] - 1) == '*')
				{
					erase_bullet(bulletX[j], bulletY[j] - 1);
					drawStar();
					score++;
					Beep(700, 400);
					statebullet[j] = 0;
				}
				else
				{
					statebullet[j] = 0;
				}
			}
		}
		setcolor(2, 0);
		gotoxy(90, 3);
		printf("Score : %d", score);
		Sleep(100);
	}while (ch != 'x');
	return 0;
}