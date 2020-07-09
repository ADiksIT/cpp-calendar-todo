#include <iostream>
#include <string>
//#include <Windows.h>

class Auth
{
	std::string name;
	std::string password;

	bool isValidation(std::string value)
	{
		return value.find_first_of(":*&/;,+-=") != std::string::npos ? true : false;
	}
public:
	void setUserName(std::string name)
	{
		if (isValidation(name))
		{
			std::cout << "Your data: "<< name <<" is not corrected" << std::endl;
		}
		else 
		{
			this->name = name;
		}
	}

	void setUserPassword(std::string password)
	{
		if (isValidation(password))
		{
			std::cout << "Your data: "<< password <<" is not corrected" << std::endl;
		}
		else
		{
			this->password = password;
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
