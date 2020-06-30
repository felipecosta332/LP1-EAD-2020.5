#include "../inc/App.h"

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[]) {
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
    } else {
        return show_usage();
    }

    return 0;
}

void App::add() {
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message) {
    diary.add(message);
    diary.write();
}

void App::search() {
    std::string what;
    std::cout << "Enter the string to be searched:" << std::endl;
    std::getline(std::cin, what);

    search(what);
}

void App::search(std::string what) {
    Message* message = diary.search(what);
    if (message == nullptr) {
        std::cout << "There is no message with the string \"" << what << "\" in its content." << std::endl;
    } else {
        std::cout << "The first message found with the string is:" << std::endl;
        std::cout << message->date.to_string() << " " << message->time.to_string() << " " << message->content << std::endl;
    }
}

void App::list_messages() {
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

int App::show_usage() {
    return 1;
}
