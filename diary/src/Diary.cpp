#include "../inc/Diary.hpp"

Diary::Diary(const std::string& filename) : 
    filename(filename), 
    messages_size(0), 
    messages_capacity(10), 
    messages(nullptr)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary() {
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_size < messages_capacity) {
        messages[messages_size].content = message;
        messages[messages_size].date.set_from_string(get_current_date());
        messages[messages_size].time.set_from_string(get_current_time());
        messages_size++;
    }
}

void Diary::write()
{
    // gravar as mensagens no disco
}
