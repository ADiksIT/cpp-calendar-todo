#pragma once

#include <iostream>
#include <string>
#include "ActionsAPI.h"

class Auth
{
	ActionsAPI http;
	json jsonData(std::string* mes);
public:
	bool login();
	
	bool registration();

};

