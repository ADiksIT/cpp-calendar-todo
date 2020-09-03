#pragma once

#include <iostream>
#include <string>
#include "API.h"
#include "ActionsAPI.h"


class Auth
{
	

	ActionsAPI http;
	json jsonData(std::string* mes);
	json request();
public:
	bool login();
	
	bool registration();



};

