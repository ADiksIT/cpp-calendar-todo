#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Auth.h";
#include "FileSystem.h";
#include "Menu.h";

namespace fs = std::filesystem;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
	Menu menu;
	return 0;
}
