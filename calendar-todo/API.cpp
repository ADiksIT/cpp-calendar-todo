#include "API.h"

inline void API::setADRESS(std::string ADRESS_API) 
{ 
	this->ADRESS_API = ADRESS_API; 
}

void API::setUserKey(std::string userKey)
{
	this->userKey = userKey;
}

void API::setTodosKey(std::string todosKey)
{
	this->todosKey = todosKey;
}

std::string API::getUserKey()
{
	return this->userKey;
}

std::string API::getTodosKey()
{
	return this->todosKey;
}

size_t curlWriteFunc(void* contents, size_t size, size_t nmemb, std::string* s)
{
	size_t newLength = size * nmemb;
	try
	{
		s->append((char*)contents, newLength);
	}
	catch (std::bad_alloc & e)
	{
		return 0;
	}

	return newLength;
}

json API::requestPOST(std::string URL, json j)
{

	curl_global_init(CURL_GLOBAL_ALL);
	this->curl = curl_easy_init();

	std::string answer;

	if (curl)
	{
		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, "Accept: application/json");
		headers = curl_slist_append(headers, "Content-Type: application/json");
		headers = curl_slist_append(headers, "charsets: utf-8");

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

		std::string json = j.dump();
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteFunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());

		this->code = curl_easy_perform(curl);

		if (this->code)
		{
			std::cout << "ERROR CURL CODE: " << this->code << std::endl;
		}
	}

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	if (answer != "")
	{
		json jAnswer = json::parse(answer);
		return jAnswer;
	}
	return j;
}

json API::GET(std::string URL)
{
	curl_global_init(CURL_GLOBAL_ALL);
	this->curl = curl_easy_init();

	std::string answer;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());


		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteFunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
	
		this->code = curl_easy_perform(curl);

		if (this->code)
		{
			std::cout << "ERROR CURL CODE: " << this->code << std::endl;
		}
	}

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	if (answer != "")
	{
		json jAnswer = json::parse(answer);
		return jAnswer;
	}
	return answer;
}

std::string API::getADRESS()
{
	return this->ADRESS_API;
}
