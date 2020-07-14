#pragma once
#include <iostream>
#include <string>
#include "FileSystem.h";


class Auth
{
	std::string name;
	std::string password;

	bool isValidation(std::string value)
	{
		return value.find_first_of(":*&/;,+-=") != std::string::npos ? true : false;
	}

	void warningUser(std::string data) 
	{
		std::cout << "��������� ���� ������: " << data << " �� ���������, ��������� ������" << std::endl;
	}

public:
	void setUserName(std::string name) 
	{
		if (isValidation(name))
			warningUser(name);
		else
			this->name = name; 
	}

	void setUserPassword(std::string password)
	{
		if (isValidation(password))
			warningUser(password);
		else
			this->password = password;

	}

	bool registration() 
	{
		FileSystem fls;
		std::string name, password;

		std::cout << "������� ��� ����� ��� �����������: ";
		std::cin >> name;

		std::cout << "�������� ���������� ������: ";
		std::cin >> password;

		setUserName(name);
		setUserPassword(password);


		fs::path p = fls.getPath();
		if (getUserName().size() != 0)
		{
			std::string str;
			std::ifstream in(fls.getPathLoginFile());
			if (in.is_open())
			{
				bool key = false;
				while (getline(in, str))
				{
					key = false;
					size_t pos = str.find(getUserName());
					if (pos != std::string::npos)
						break;
					else
						key = true;
				}
				if (key)
				{
					fs::path p = fls.createUserDerictories(name);
					fls.writingRegToFile(p, name, password);
					std::cout << "�� ���� ����������������!!!" << std::endl;
				}
				else
				{
					std::cout << "�� �� ���� ����������������!!!" << std::endl;
				}
			}
			else
			{
				fs::path p = fls.createUserDerictories(name);
				fls.writingRegToFile(p, name, password);
			}
			in.close();
		}
		return false;
	}

	bool login() 
	{
		FileSystem fls;
		std::string name, password;

		std::cout << "������� ��� ����� ��� �����: ";
		std::cin >> name;

		std::cout << "������� ��� ������, ����������: ";
		std::cin >> password;


		fs::path p = fls.getPath();
		std::string str;
		std::ifstream in(fls.getPathLoginFile());
		if (in.is_open())
		{
			bool key = false;

			while (!key)
			{
				getline(in, str);

				key = false;

				size_t pos = str.find(name + " " + password);

				if (pos != std::string::npos) 
					key = true;
			}
			if (key)
			{
				std::cout << "����� ������������ ����, �� � �����" << std::endl;
				in.close();
				return true;
			}
			else
			{
				std::cout << "������ ������������ ���, �������� ������������ �������� ������" << std::endl;
				in.close();
				return false;
			}
		}
	}

	std::string getUserName() const
	{
		return this->name;
	}

	std::string getUserPassword() const
	{
		return this->password;
	}
};

