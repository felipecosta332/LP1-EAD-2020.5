#ifndef APP_H
#define APP_H

#include "Diary.h"
#include <iostream>
#include <string>

struct App {
    Diary diary;
    std::string format;

    App(const std::string& filename, const std::string& format);
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string& message);
    void search();
    void search(std::string what);
    void list_messages(const std::string& format);
    int interactive();
};

void setConfig(std::string* path, std::string* format);

#endif