#pragma once
#define CURL_STATICLIB

#include <string>
#include <iostream>
#include "curl/curl.h"
#include "nlohmann/json.hpp"

#pragma comment(lib, "curl/libcurl_a_debug.lib")

#pragma comment(lib, "Wldap32.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Normaliz.lib")

using json = nlohmann::json;

class API
{
	std::string ADRESS_API = "https://it-step-orginizer.herokuapp.com";
	CURL* curl;
	CURLcode code;
	

public:
	void setADRESS(std::string ADRESS_API);

	json GET(const std::string& URL);
	json POST(const std::string& URL, json j);
	
	std::string getADRESS();

};

