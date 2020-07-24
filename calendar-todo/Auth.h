#pragma once

#include <iostream>
#include <string>
#include "API.h"


class Auth
{
	std::string name;
	std::string password;
	API api;

	bool isValidation(std::string value)
	{
		return value.find_first_of(":*&/;,+-=") != std::string::npos ? true : false;
	}

	void warningUser(std::string data) 
	{
		std::cout << "Введенные вами данные: " << data << " не коректные, повторите заново" << std::endl;
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

	bool login();
	
	bool registration();

	json jsonData(std::string* mes);

	std::string getUserName() const {
		
			return this->name;
		
	}
	

	std::string getUserPassword() const
	{
		return this->password;
	}
};

