#include "../inc/Date.hpp"

Date::Date() : day(0),month(0),year(0) {}

std::string Date::to_string() {     
    std::stringstream stream;
    if (day < 10) {
        stream << '0';
    }
    stream << day << '/';
    if (month < 10) {
        stream << '0';
    }
    stream << month << '/' << year;     
    return stream.str();
} 

void Date::set_from_string(const std::string& time) {
    std::stringstream stream(time);     
    char discard;     
    stream >> day;     
    stream >> discard;     
    stream >> month;     
    stream >> discard;     
    stream >> year; 
}

bool Date::isEqual(Date date) {
    if (year == date.year && month == date.month && day == date.day) {
        return true;
    }
    return false;
}