#include "Auth.h"
#include<vector>
int daysOfMonth(int month, int year)
{
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else
		return 30;
}
bool Auth::login()
{
	std::string mes[2] = { "Enter your e-mail: ", "Enter your password: " };
	//json j = jsonData(mes);
	json j = {
		{"email", "r@gmail.com"},
		{"password", "r@gmail.com"},
	};

	json anw = http.login(j);

	std::cout << anw["message"] << std::endl;

	json userKey = anw["user"]["_id"];
	json todoesKey = anw["user"]["todoes"];

	http.setTodosKey(todoesKey.dump().substr(2, 24));
	http.setUserKey(userKey.dump().substr(1, 24));

	std::cout << http.getTodosKey() << std::endl;
	std::cout << http.getUserKey() << std::endl;

	json answer = http.getTodos(http.getTodosKey());


	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	timeinfo->tm_mon = 7;
	timeinfo->tm_wday = 6;
	std::string dt = asctime(timeinfo);
	std::cout << dt << std::endl;

	std::vector<std::string>dataDays = { "Mon", "Tue", "Web", "Thu", "Fri", "Sat", "Sun" };
	std::cout << timeinfo->tm_wday << std::endl;

	strftime(buffer, sizeof(buffer), "-%m-", timeinfo);
	std::string str(buffer);

	std::vector<json>data;
	int countDays = 0;
	
	for (auto i : answer["2020"]) {
		std::size_t found = i["date"].dump().find(str);
		if (found != std::string::npos)
		{
		std::string a = i["date"].dump();
		std::string year = a.substr(1, 4);
		std::string month = a.substr(6, 2);
		countDays = daysOfMonth(stoi(month), stoi(year));
		data.push_back(i);
		}
	}

	for (auto i : data)
	{
		std::cout << i << std::endl;
	}
	std::cout << countDays << std::endl;

	int indexDay = 0;
	int index = 0;
	for (auto i : dataDays)
	{
		std::cout << i << "\t";
		std::size_t found = dt.find(i);
		if (found != std::string::npos)
			indexDay = index;
		index++;
	}

	std::cout << indexDay << std::endl;

	for (size_t i = 0; i < countDays + indexDay; i++)
	{
		if (i % 7 == 0)
		{
			std::cout << "\n";
		}
		if (i < indexDay)
		{
			std::cout << " \t";
		}
		else 
		{
			std::cout << i - indexDay + 1 << "\t";
		}
		
	}
	std::cout << "\n";

	//for (auto i : answer["2020"]) {
	//    std::cout << i["date"] << std::endl;
	//}

	//// current date/time based on current system
	//time_t now = time(0);

	//// convert now to string form
	//tm* tm = localtime(&now);
	//std::string a = (std:: string)(tm->tm_mon + 1);

	//std::cout << << std::endl;

	return anw["isCorrected"];
}

bool Auth::registration()
{
	std::string mes[2] = { "Enter e-mail for registration: ", "Create password: " };
	json j = jsonData(mes);

	json anw = http.registration(j);
	std::cout << anw["message"] << std::endl;
	
	return anw["isCorrected"];
}

json Auth::jsonData(std::string* mes)
{
	std::string email, password;

	std::cout << mes[0];
	std::cin >> email;

	std::cout << mes[1];
	std::cin >> password;

	json j = {
		{"email", email},
		{"password", password},
	};

	return j;
}
