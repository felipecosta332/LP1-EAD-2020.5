#ifndef DIARY_H
#define DIARY_H

#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Diary {
    Diary(const std::string& filename);

    std::string filename;
    std::vector<Message> messages;

    std::vector<Message*> search(std::string what);
    void add(const std::string& message);
    void write();
};

#endif