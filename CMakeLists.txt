cmake_minimum_required(VERSION 3.17)
project(calendar_todo)

set(CMAKE_CXX_STANDARD 14)

include_directories(calendar-todo)
include_directories(calendar-todo/curl)
include_directories(calendar-todo/nlohmann)

add_executable(calendar_todo
        calendar-todo/curl/curl.h
        calendar-todo/curl/curlver.h
        calendar-todo/curl/easy.h
        calendar-todo/curl/mprintf.h
        calendar-todo/curl/multi.h
        calendar-todo/curl/stdcheaders.h
        calendar-todo/curl/system.h
        calendar-todo/curl/typecheck-gcc.h
        calendar-todo/curl/urlapi.h
        calendar-todo/nlohmann/json.hpp
        calendar-todo/API.cpp
        calendar-todo/API.h
        calendar-todo/Auth.cpp
        calendar-todo/Auth.h
        calendar-todo/main.cpp
        calendar-todo/Menu.h
        .gitattributes
        .gitignore
        calendar-todo.sln)
