#pragma once

#include <iostream>
#include <string>
#include "API.h"
#include "ActionsAPI.h"
#include "CalendarUI.h"


class Auth
{
	

	ActionsAPI http;
	CalendarUI ui;
	json jsonData(std::string* mes);
	
public:
	bool login();
	
	bool registration();



};

