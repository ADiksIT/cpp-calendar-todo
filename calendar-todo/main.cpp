#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Auth.h";
#include "FileSystem.h";


namespace fs = std::filesystem;

enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Auth auth;
    auth.registration();
	return 0;
}
