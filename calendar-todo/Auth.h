#pragma once

#include <iostream>
#include <string>
#include "API.h"


class Auth
{
	API api;
public:
	bool login();
	
	bool registration();

	json jsonData(std::string* mes);

};

