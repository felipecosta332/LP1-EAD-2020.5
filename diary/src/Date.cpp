#include "../inc/Date.hpp"

Date::Date() : day(0),month(0),year(0) {}

std::string Date::to_string() {     
    return std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year); 
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