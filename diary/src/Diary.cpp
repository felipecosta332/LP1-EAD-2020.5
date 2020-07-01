#include "../inc/Diary.h"

Diary::Diary(const std::string& filename) : filename(filename) {
    std::ifstream reader;
    std::string line;
    std::stringstream stream;
    Date date;
    Message message;
    char discard;
    reader.open(filename, std::ios::in);
    while (reader >> line) {
        if (line[0] == '#') {
            reader >> line;
            stream << line;
            stream >> date.day;     
            stream >> discard;     
            stream >> date.month;     
            stream >> discard;     
            stream >> date.year;
            stream = std::stringstream();
        } else if (line[0] == '-') {
            message.date = date;
            reader >> line;
            stream << line;
            stream >> message.time.hour;
            stream >> discard;     
            stream >> message.time.minute;
            stream >> discard;     
            stream >> message.time.second;
            std::getline(reader, message.content, ' ');
            std::getline(reader, message.content);
            stream = std::stringstream();
            messages.push_back(message);
        }
    }
    reader.close();
}

void Diary::add(const std::string& message) {
    Message newMessage;
    newMessage.content = message;
    newMessage.date.set_from_string(get_current_date());
    newMessage.time.set_from_string(get_current_time());
    messages.push_back(newMessage);
}

void Diary::write() {
    if (messages.size() > 0) {
        std::ofstream writer;
        Date date = messages[0].date;
        writer.open(filename, std::ios::out);
        writer << "# " << messages[0].date.to_string() << std::endl;
        for (int i = 0; i < messages.size(); i++) {
            if (!date.isEqual(messages[i].date)) {
                date = messages[i].date;
                writer << "\n\n# " << messages[i].date.to_string() << std::endl;
            }
            writer << "\n- " << messages[i].time.to_string() << " " << messages[i].content;
        }
        writer.close();
    }
}

std::vector<Message*> Diary::search(std::string what) {
    std::vector<Message*> matches;
    for (int i = 0; i < messages.size(); i++) {
        if (messages[i].content.find(what) != std::string::npos) {
            matches.push_back(&messages[i]);
        }
    }
    return matches;
}