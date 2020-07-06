#include "App.h"

App::App(const std::string& filename, const std::string& format) : diary(filename), format(format) {}

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
        if (argc == 2) {
            list_messages(format);
        } else {
            list_messages(argv[2]);
        }
    } else if (action == "search") {
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
    } else if (action == "interactive") {
        interactive();
    } else {
        return show_usage();
    }

    return 0;
}

void App::add() {
    std::string message;
    std::cout << "Enter your message: ";
    getline(std::cin, message);

    add(message);
}

void App::add(const std::string& message) {
    diary.add(message);
    diary.write();
}

void App::search() {
    std::string what;
    std::cout << "Enter the string to be searched: ";
    getline(std::cin, what);

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

void App::list_messages(const std::string& format) {
    for (size_t i = 0; i < diary.messages.size(); i++) {
        for (int j = 0; j < format.size(); j++) {
            if (format[j] == '%' && j + 1 < format.size()) {
                switch (format[j + 1]) {
                    case 'd':
                        std::cout << diary.messages[i].date.to_string();
                        break;
                    case 't':
                        std::cout << diary.messages[i].time.to_string();
                        break;
                    case 'm':
                        std::cout << diary.messages[i].content;
                        break;
                }
                j++;
            } else {
                std::cout << format[j];
            }
        }
        std::cout << std::endl;
    }
}

int App::show_usage() {
    return 1;
}

int App::interactive() {
    int trash;
    char action;
    std::string input;
    while (true) {
        trash = system("clear");
        std::cout << "Diary Manager" << std::endl;
        std::cout << "\nChoose an action:\n" << std::endl;
        std::cout << "1) List messages" << std::endl;
        std::cout << "2) Add new message" << std::endl;
        std::cout << "3) Search message" << std::endl;
        std::cout << "\n0) Finish\n" << std::endl;
        std::cout << "Command: ";
        std::cin >> action;
        trash = system("clear");
        switch (action) {
            case '1':
                std::cout << "Do you want to list in a specific format(y/n)? ";
                std::cin >> action;
                if (action == 'y') {
                    std::cout << "Please enter the format you want:" << std::endl;
                    getline(std::cin, input);
                    getline(std::cin, input);
                    list_messages(input);
                } else {
                    list_messages(format);
                }
                std::cout << "Show menu to choose next operation(y/n)? ";
                std::cin >> action;
                if (action != 'y') {
                    return 0;
                }
                break;
            case '2':
                std::cout << "Enter your message: " << std::endl;
                getline(std::cin, input);
                getline(std::cin, input);
                add(input);
                break;
            case '3':
                std::cout << "Enter the string to be searched: " << std::endl;
                getline(std::cin, input);
                getline(std::cin, input);
                search(input);
                std::cout << "Show menu to choose next operation(y/n)? ";
                std::cin >> action;
                if (action != 'y') {
                    return 0;
                }
                break;
            case '0':
                return 0;
        }
    }
}

void setConfig(std::string* path, std::string* format) {
    std::ifstream config("diary.config", std::ios::in);
    if (config.is_open()) {
        std::string input;
        while (getline(config, input)) {
            std::stringstream line(input);
            getline(line, input, '=');
            if (input.compare("path") == 0) {
                getline(line, *path);
            }
            if (input.compare("default_format") == 0) {
                getline(line, *format);
            }
        }
    } else {
        std::ofstream newConfig("diary.config", std::ios::out);
        newConfig << "path=diary.md" << std::endl;
        newConfig << "default_format=%d %t: %m";
        newConfig.close();
        *path = "diary.md";
        *format = "%d %t: %m";
    }
    config.close();
}