#pragma once

#include <iostream>
#include <string>
#include "API.h"


class Auth
{
	API api;

	json jsonData(std::string* mes);
	json request();
public:
	bool login();
	
	bool registration();



};

