#ifndef DIARY_HPP
#define DIARY_HPP

#include "Message.hpp"
#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
};

#endif