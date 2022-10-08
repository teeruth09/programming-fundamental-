/*
#include<stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
int random(int lower, int upper)
{
	return(rand() % upper - lower + 1);
}
void fill_data_to_buffer()
{
	for (int j = 0; j <= 10000; j++)
	{
		for (int y = 0; y < screen_y; ++y) {
			for (int x = 0; x < screen_x; ++x) {
				consoleBuffer[x + screen_x * y].Char.AsciiChar == random(65, 90);

				consoleBuffer[x + screen_x * y].Attributes = (random(0, 255), random(0, 255));
			}
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
		&windowSize);
}
int main()
{
	setConsole(screen_x, screen_y);
	fill_data_to_buffer();
	fill_buffer_to_console();
	Sleep(5000);
	return 0;
}
*/

/*
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE rHnd;
DWORD fdwMode;

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
		&windowSize);
}

void init_star()
{
	for (int i = 0; i < scount; i++)
	{
		star[i] = { rand() % screen_x, rand() % screen_y };
	}
}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y - 1) {
			star[i] = { (rand() % screen_x),1 };
		}
		else {
			star[i] = { star[i].X,star[i].Y + 1 };
		}
	}
}
//Draw ship


void fill_star_to_buffer()
{
	for (int i = 0; i < scount; i++)
	{
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}
int main()
{
	int i;
	srand(time(NULL));
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	init_star();
	setMode();
	i = 0;
	while (i < 1000)
	{
		star_fall();
		//clear_buffer();
		fill_star_to_buffer();
		fill_buffer_to_console();
		Sleep(200);
		i++;
	}
	return 0;
}
*/

#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>

#define screen_x 80
#define screen_y 25
#define scount 40

HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;

CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
COORD ship;

int set_color = 7;
int life = 10;
bool play = true;

// Set cursor
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
void clear_buffer()
{
	for (int y = 0; y < screen_y; y++)
	{
		for (int x = 0; x < screen_x; x++) 
		{
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
//Debug 
void init_star()
{
	for (int i = 0; i < scount; i++)
	{
		//star[i] = {(rand() % screen_x), (rand() % screen_y)};
		star[i].X = rand() % screen_x;
		star[i].Y = rand() % screen_y;
	}
}
void star_fall()
{
	for (int i = 0; i < scount; i++) 
	{
		if (star[i].Y >= screen_y - 1) 
		{
			//star[i] = { (rand() % screen_x),1 };
			star[i].X = rand() % screen_x;
			star[i].Y = 1;
		}
		else 
		{
			//star[i] = { star[i].X,star[i].Y + 1 };
			star[i].X = rand() % screen_x;
			star[i].Y = star[i].Y + 1;
		}
	}
}
void fill_star_to_buffer()
{
	for (int i = 0; i < scount; i++)
	{
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
//Ship
void draw_ship(int x, int y, int color)
{
	//print <-0-> and color
	ship.X = x;
	ship.Y = y;
	consoleBuffer[ship.X + screen_x * ship.Y].Char.AsciiChar = '<';
	consoleBuffer[ship.X + screen_x * ship.Y].Attributes = color;
	consoleBuffer[ship.X + screen_x * ship.Y + 1].Char.AsciiChar = '-';
	consoleBuffer[ship.X + screen_x * ship.Y + 1].Attributes = color;
	consoleBuffer[ship.X + screen_x * ship.Y + 2].Char.AsciiChar = '0';
	consoleBuffer[ship.X + screen_x * ship.Y + 2].Attributes = color;
	consoleBuffer[ship.X + screen_x * ship.Y + 3].Char.AsciiChar = '-';
	consoleBuffer[ship.X + screen_x * ship.Y + 3].Attributes = color;
	consoleBuffer[ship.X + screen_x * ship.Y + 4].Char.AsciiChar = '>';
	consoleBuffer[ship.X + screen_x * ship.Y + 4].Attributes = color;
}
//check 
void check_collision()
{
	for (int i = 0; i < scount; i++)
	{
		if ((ship.X == star[i].X || ship.X + 1 == star[i].X || ship.X + 2 == star[i].X || ship.X + 3 == star[i].X || ship.X + 4 == star[i].X) && ship.Y == star[i].Y)
		{
			star[i].X = rand() % screen_x;
			star[i].Y = 1;
			life--;
		}
		if (life == 0)
		{
			play = false;
		}
	}
}
//goto xy
void gotoxy(int x, int y)
{
	COORD c = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Set color
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
//Life
void Life()
{
	setcolor(3, 0);
	gotoxy(0, 1);
	printf("Your Life : %d", life);
}

int main()
{
	setcursor(0);
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	init_star();
	setMode();
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	int posX = screen_x;
	int posY = screen_y;
	
	int set_color = 7;

	//Debug
	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) 
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i)
			{
				if (eventBuffer[i].EventType == KEY_EVENT &&eventBuffer[i].Event.KeyEvent.bKeyDown == true) 
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) //key ESC
					{
						play = false;
					}
					//key c to random color
					else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 99) 
					{
						set_color = rand() % 255 + 1;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) 
				{
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					//Left mouse click to random color
					if (eventBuffer[i].Event.MouseEvent.dwButtonState && FROM_LEFT_1ST_BUTTON_PRESSED) 
					{
						set_color = rand() % 255 + 1;
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) 
					{
						posX = posx;
						posY = posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		draw_ship(posX, posY, set_color);
		fill_buffer_to_console();
		check_collision();
		Life();
		Sleep(100);
	}
	return 0;
}