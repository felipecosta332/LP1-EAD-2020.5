#include "App.h"

App::App(const std::string& filename) : diary(filename) {}

int App::run(int argc, char* argv[]) {
    if (argc == 1) {
        return show_usage();
    }
    if (argc > 3) {
        std::cout << "Too many arguments in the command line!" << std::endl;
        std::cout << "You only need three arguments at most." << std::endl;
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
        if (argc > 2) {
            std::cout << "Too many arguments in the command line!" << std::endl;
            std::cout << "You only need two for the 'list' command." << std::endl;
        }
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

void App::add(const std::string& message) {
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
    std::vector<Message*> matches = diary.search(what);
    if (matches.size() < 1) {
        std::cout << "There is no message with the string \"" << what << "\" in its content." << std::endl;
    } else {
        std::cout << "The messages found with the string are:" << std::endl;
        for (int i = 0; i < matches.size(); i++) {
            std::cout << matches[i]->date.to_string() << " " << matches[i]->time.to_string() << " " << matches[i]->content << std::endl;
        }
    }
}

void App::list_messages() {
    for (size_t i = 0; i < diary.messages.size(); i++) {
        std::cout << diary.messages[i].date.to_string() << " " << diary.messages[i].time.to_string() << " " << diary.messages[i].content << std::endl;
    }
}

int App::show_usage() {
    return 1;
}
