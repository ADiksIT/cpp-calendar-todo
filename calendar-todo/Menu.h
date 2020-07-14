#pragma once
#include "Auth.h";
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <windows.h>


//using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
//
enum KEYBOARD_CODE { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, ENTER = 13, ESC = 27, SPACE = 32 };
//
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
//
void setCursor(int x, int y) {
	COORD coordination = { x,y };
	SetConsoleCursorPosition(hStdOut, coordination);
}

class Menu 
{
	Auth auth;
public:
	Menu()
	{
		std::string menu[2] = { "Login", "Registration" };
		startMenu(menu, 2);
	}

	void startMenu(std::string* arr, int length)
	{
		bool (Auth:: *sets[2])(void) = { &Auth::login, &Auth::registration };
		int input, position = 0;
		bool check = false;
		do
		{
			for (size_t i = 0; i < length; i++)
			{
				setCursor(50, i + 10);
				if (i == position)
				{
					setColor(Red, Black);
				}
				else
				{
					setColor(White, Black);
				}
				std::cout << arr[i] << std::endl;
			}		
			input = _getch();
			switch (input)
			{
			case UP:
				if (position == 0)
				{
					break;
				}
				position--;
				break;
			case DOWN:
				if (position == length)
				{
					break;
				}
				position++;
				break;
			case ENTER:
				system("cls");
				setColor(White, Black);
				check = (auth.*sets[position])();
				system("pause");
				system("cls");
				break;
			}
		} while (check != true);
		std::cout << "you exit" << std::endl;
	}
};