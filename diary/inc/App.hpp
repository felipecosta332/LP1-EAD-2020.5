#ifndef APP_HPP
#define APP_HPP

#include "Diary.hpp"
#include <iostream>
#include <string>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string message);
    void list_messages();
};

#endif