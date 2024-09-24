//
// Created by ROG on 2024/9/24.
//

#ifndef EVENT_H
#define EVENT_H
#include <string>


class Event {
public:
    std::string data;

    int code;
    Event(const std::string& data) : data(data){}

    Event(int code) : code(code) {}

};



#endif //EVENT_H
