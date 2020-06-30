#include "../inc/Diary.h"

Diary::Diary(const std::string& filename) : 
    filename(filename), 
    messages_size(0), 
    messages_capacity(10), 
    messages(nullptr)
{
    /*
    • Carregar as mensagens previamente salvas ao instanciar um Diary (1,5 pontos):
    Ao criar uma variável do tipo Diary e passar um nome de arquivo pra ele, o pro-
    grama deve carregar as mensagens previamente salvas no arquivo, se existirem;
    */
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

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    /*
    • Permitir o armazenamento de qualquer quantidade de mensagens no array de
    mensagens (3,0 pontos):
    Se, ao tentar adicionar uma nova mensagem o array estiver cheio, vocês devem
    criar um novo array maior, mover todas as mensagens pra ele, adicionar a mensa-
    gem nova e deletar o array antigo. Tudo isso sem deixar vazar memória.
    */
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

void Diary::write()
{
    // gravar as mensagens no disco
    /*
    • Salvar as mensagens no disco utilizando o formato Markdown (0,5 ponto):
    Ao adicionar uma nova mensagem no diário, seu programa deve atualizar o arquivo
    para armazenar a mensagem nova;
    */
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