#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>


namespace fs = std::filesystem;

class FileSystem
{
	const std::string FOLDER_ROOT = "db";
	const std::string LOGIN_TXT = "login.txt";
	const std::string PATH_USERS = "db/users/";
public:

	void writingRegToFile(fs::path p, std::string name, std::string password)
	{
		std::ofstream ofs(p, std::ios::app);
		ofs << name << " " << password + "\n";
		ofs.close();
	}

	fs::path createUserDerictories(std::string userName)
	{
		fs::create_directories(PATH_USERS + userName);
		fs::path p = getPath();
		p /= LOGIN_TXT;
		fs::create_directories(p.parent_path());
		return p;
	}

	fs::path getPath() 
	{
		return fs::current_path() / FOLDER_ROOT;
	}

	fs::path getPathLoginFile()
	{
		return getPath() / LOGIN_TXT;
	}

	std::string getPathUsers() 
	{
		return PATH_USERS;
	}

	std::string getLoginTXT()
	{
		return LOGIN_TXT;
	}
};

