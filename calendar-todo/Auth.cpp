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
void setMonth(json answer, const int month) 
{
	time_t rawtime;
	char buffer[80];

	time(&rawtime);

	struct tm* timeinfo = localtime(&rawtime);


	timeinfo->tm_mon = month;
	timeinfo->tm_mday = 1;

	mktime(timeinfo);

	std::string dt = asctime(timeinfo);

	std::vector<std::string>dataDays = { "Mon", "Tue", "Web", "Thu", "Fri", "Sat", "Sun" };

	strftime(buffer, sizeof(buffer), "-%m-", timeinfo);
	std::string str(buffer);

	std::vector<json>data;
	int countDays = 0;

	std::string year = std::to_string(timeinfo->tm_year + 1900);
	for (auto i : answer[year]) {
		std::size_t found = i["date"].dump().find(str);
		if (found != std::string::npos)
		{
			std::string date = i["date"].dump();
			std::string year = date.substr(1, 4);
			std::string month = date.substr(6, 2);

			countDays = daysOfMonth(stoi(month), stoi(year));
			data.push_back(i);
		}
	}
	

	//for (auto i : data)
	//{
	//	std::cout << i << std::endl;
	//}

	//int indexDay = 0, index = 0;

	//for (auto i : dataDays)
	//{
	//	std::cout << i << "\t";
	//	std::size_t found = dt.find(i);
	//	if (found != std::string::npos)
	//		indexDay = index;
	//	index++;
	//}

	//for (size_t i = 0; i < countDays + indexDay; i++)
	//{
	//	if (i % 7 == 0)
	//		std::cout << "\n";

	//	if (i < indexDay)
	//		std::cout << " \t";
	//	else
	//		std::cout << i - indexDay + 1 << "\t";
	//}
	//std::cout << "\n";
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

	//===================================================
	json answer = http.getTodos(http.getTodosKey());

	setMonth(answer, 8);

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
