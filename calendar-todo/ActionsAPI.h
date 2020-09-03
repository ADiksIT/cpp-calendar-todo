#pragma once
#include "API.h"
class ActionsAPI
{
	API api;
	std::string proxy;
    std::string todosKey;
    std::string userKey;
public:
	ActionsAPI();

	json login(json postData);

	json registration(json postData);

	json getTodos(const std::string& key);

    void setTodosKey(const std::string& key);
    std::string getTodosKey() const;

    void setUserKey(std::string key);
    std::string getUserKey() const;
};

