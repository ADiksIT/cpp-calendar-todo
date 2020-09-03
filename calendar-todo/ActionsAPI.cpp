#include "ActionsAPI.h"

ActionsAPI::ActionsAPI() {
    this->proxy = api.getADRESS();
}

json ActionsAPI::login(json postData) {
    return api.POST(proxy + "/api/auth/login", postData);
}

json ActionsAPI::registration(json postData) {
    return api.POST(proxy + "/api/auth/register", postData);
}

json ActionsAPI::getTodos(const std::string &key) {
    return api.GET(proxy + "/api/todoes/all/" + key);
}

void ActionsAPI::setTodosKey(const std::string& key)
{
    if (!key.empty())
    {
        this->todosKey = key;
    }
}

std::string ActionsAPI::getTodosKey() const
{
    return this->todosKey;
}

void ActionsAPI::setUserKey(std::string key)
{
    if (!key.empty())
    {
        this->userKey = key;
    }
}

std::string ActionsAPI::getUserKey() const
{
    return this->userKey;
}