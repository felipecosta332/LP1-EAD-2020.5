#include "../inc/Time.h"

std::string format_current_date(const std::string& format) {
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date() {
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
    return format_current_date("%H:%M:%S");
}

Time::Time() : hour(0),minute(0),second(0) {} 

std::string Time::to_string() {
    std::stringstream stream;
    if (hour < 10) {
        stream << '0';
    }
    stream << hour << ':';
    if (minute < 10) {
        stream << '0';
    }
    stream << minute << ':';     
    if (second < 10) {
        stream << '0';
    }
    stream << second;     
    return stream.str();
} 

void Time::set_from_string(const std::string& time) {     
    std::stringstream stream(time);     
    char discard;     
    stream >> hour;     
    stream >> discard;     
    stream >> minute;     
    stream >> discard;     
    stream >> second; 
}
