#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>

struct Time {
    int hour;
    int minute;
    int second;
};

struct Date {
    int year;
    int month;
    int day;
};

struct Message {
    Date date;
    Time time;
    std::string content;

    void displayMessage();
    void saveToFile();
    void copyMessage(const Message &other_message);
    bool compare_dates(const Message &other_message);
    bool compare_times(const Message &other_message);
    bool compare_contents(const Message &other_message);
};

#endif