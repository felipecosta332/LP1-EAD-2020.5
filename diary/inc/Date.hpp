#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <sstream>

struct Date
{
    Date();
    unsigned int year;
    unsigned int month;
    unsigned int day;
    std::string to_string();
    void set_from_string(const std::string& date);
};

#endif