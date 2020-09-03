#include "API.h"

inline void API::setADRESS(std::string ADRESS_API) 
{ 
	this->ADRESS_API = ADRESS_API; 
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

json API::GET(const std::string& URL)
{
	auto curl = curl_easy_init();
	std::string response_string;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteFunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl = nullptr;
	}
	json jAnswer = json::parse(response_string);
	return jAnswer;
}

json API::POST(const std::string& URL, json j)
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

	if (!answer.empty())
	{
		json jAnswer = json::parse(answer);
		return jAnswer;
	}
	return j;
}

std::string API::getADRESS()
{
	return this->ADRESS_API;
}
