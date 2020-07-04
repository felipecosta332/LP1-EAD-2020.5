#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>

struct Date {
    Date();
    unsigned int year;
    unsigned int month;
    unsigned int day;
    std::string to_string();
    void set_from_string(const std::string& date);
    bool isEqual(Date date);
};

#endif