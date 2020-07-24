#include "Auth.h"

bool Auth::login()
{
	std::string mes[2] = { "Enter your e-mail: ", "Enter your password: " };
	json j = jsonData(mes);

	json anw = api.requestPOST(api.getADRESS() + "/api/auth/login", j);
	std::cout << anw["message"] << std::endl;

	return anw["isCorrected"];
}

bool Auth::registration()
{
	std::string mes[2] = { "Enter e-mail for registration: ", "Create password: " };
	json j = jsonData(mes);

	json anw = api.requestPOST(api.getADRESS() + "/api/auth/register", j);
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
