#include "../inc/Diary.h"

Diary::Diary(const std::string& filename) : 
    filename(filename), 
    messages_size(0), 
    messages_capacity(10), 
    messages(nullptr)
{
    messages = new Message[messages_capacity];
    std::ifstream reader;
    std::string line;
    std::stringstream stream;
    Date date;
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
            if (messages_size >= messages_capacity) {
                messages_capacity *= 2;
                Message* new_array = new Message[messages_capacity];
                for (int i = 0; i < messages_size; i++) {
                    new_array[i] = messages[i];
                }
                delete[] messages;
                messages = new_array;
            }
            messages[messages_size].date = date;
            reader >> line;
            stream << line;
            stream >> messages[messages_size].time.hour;
            stream >> discard;     
            stream >> messages[messages_size].time.minute;
            stream >> discard;     
            stream >> messages[messages_size].time.second; 
            reader >> messages[messages_size].content;
            stream = std::stringstream();
            messages_size++;
        }
    }
    reader.close();
}

Diary::~Diary() {
    delete[] messages;
}

void Diary::add(const std::string& message) {
    if (messages_size >= messages_capacity) {
        messages_capacity *= 2;
        Message* new_array = new Message[messages_capacity];
        for (int i = 0; i < messages_size; i++) {
            new_array[i] = messages[i];
        }
        delete[] messages;
        messages = new_array;
    }
    messages[messages_size].content = message;
    messages[messages_size].date.set_from_string(get_current_date());
    messages[messages_size].time.set_from_string(get_current_time());
    messages_size++;
}

void Diary::write() {
    if (messages_size > 0) {
        std::ofstream writer;
        Date date = messages[0].date;
        writer.open(filename, std::ios::out);
        writer << "# " << messages[0].date.to_string() << std::endl;
        for (int i = 0; i < messages_size; i++) {
            if (!date.isEqual(messages[i].date)) {
                date = messages[i].date;
                writer << "\n\n# " << messages[i].date.to_string() << std::endl;
            }
            writer << "\n- " << messages[i].time.to_string() << " " << messages[i].content;
        }
        writer.close();
    }
}

Message* Diary::search(std::string what) {
    for (int i = 0; i < messages_size; i++) {
        if (messages[i].content.find(what) != std::string::npos) {
            return &messages[i];
        }
    }
    return nullptr;
}