#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "Date.hpp"
#include "Time.hpp"
#include <string>

struct Message
{
    std::string content;
    Date date;
    Time time;
};

#endif