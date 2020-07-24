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
	std::string ADRESS_API = "http://localhost:3000";
	CURL* curl;
	CURLcode code;
	

public:

	//size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s);

	void setADRESS(std::string ADRESS_API);

	json requestPOST(std::string URL, json j);
	
	std::string getADRESS();

};

