#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <fstream>
#include "Auth.h";

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
    std::string name, password;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your password: ";
    std::cin >> password;

    auth.setUserName(name);
    auth.setUserPassword(password);

    fs::path p = fs::current_path() / "db";

    if (auth.getUserName().size() == 0)
    {
        std::cout << "Your data is not coorected registration failed!!!" << std::endl;
          
    }
    else 
    {

        std::string str;
        std::ifstream in(p / "login.txt");
        if (in.is_open())
        {
            while (getline(in, str))
            {
                std::cout << "login and password: " << str << std::endl;
                size_t a = str.find(name);
                if (a != std::string::npos)
                {
                    std::cout << "all were well" << std::endl;
                }
                else 
                {
                    std::cout << "registration faliled user has benn life" << std::endl;
                }
            }
            in.close();
        }
        else 
        {
            std::cout << "file не удалось открыть" << std::endl;
        }


        fs::create_directories("db/users/" + name);
        p /= "login.txt";
        fs::create_directories(p.parent_path());

        std::ofstream ofs(p, std::ios::app);
        ofs << name << " " << password + "\n";

        ofs.close();
    }


    //std::cout << "Start enter pleace your name: " << std::endl;
 //   fs::path p = fs::current_path() / "users";
 //   std::cout << p << std::endl;
 //   if (fs::is_empty(p)) 
 //   {
 //       std::cout << "Derictory clear" << std::endl;
 //   }
 //   else 
 //   {
 //       std::cout << p << "\n";
 //       std::cout << "Derictory NO clear" << std::endl;
//}
	//std::string name;
	//std::cin >> name;
	//fs::create_directories("users/" + name);
	//std::cout << "End" << std::endl;
   /* const fs::path tmp_dir{ fs::temp_directory_path() };
    std::cout << std::boolalpha
        << "Temp dir: " << tmp_dir << '\n'
        << "is_empty(): " << fs::is_empty(tmp_dir) << '\n';

    const fs::path tmp_name{ tmp_dir / std::tmpnam(nullptr) };
    std::cout << "Temp file: " << tmp_name << '\n';

    std::ofstream file{ tmp_name.string() };
    std::cout << "is_empty(): " << fs::is_empty(tmp_name) << '\n';
    file << "cppreference.com";
    file.flush();
    std::cout << "is_empty(): " << fs::is_empty(tmp_name) << '\n'
        << "file_size(): " << fs::file_size(tmp_name) << '\n';
    file.close();
    fs::remove(tmp_name);*/

	return 0;
}
