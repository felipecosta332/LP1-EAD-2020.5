#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <iostream>
#include <sstream> 
#include <string>

struct Time {
    Time();
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    std::string to_string();
    void set_from_string(const std::string& time);
};

std::string format_current_date(const std::string& format);

std::string get_current_date();

std::string get_current_time();

#endif