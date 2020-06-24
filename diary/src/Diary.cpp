/*
Presença de Hoje: Alocar o array de mensagens dinamicamente, de forma que comporte até 10 mensagens, 
e adicionar mensagens nele até este limite.
*/

#include "../include/Diary.h"

Diary::Diary(const std::string& filename) : 
    filename(filename), 
    messages_size(0), 
    messages_capacity(10), 
    messages(nullptr)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_size < messages_capacity) {
        messages[messages_size].content = message;
        messages_size++;
    }
}

void Diary::write()
{
    // gravar as mensagens no disco
}
