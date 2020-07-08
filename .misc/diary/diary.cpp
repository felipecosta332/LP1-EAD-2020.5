#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

std::string format_current_date(const std::string& format) {
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date() {
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
    return format_current_date("%H:%M:%S");
}

void showInstructions() {
    cout << "COMANDOS E INSTRUÇÕES DE USO:" << endl;
    cout << "./diary" << endl;
    cout << "\t– Exibe uma mensagem informando como o programa deve ser utilizado." << endl;
    cout << "./diary add" << endl;
    cout << "\t– Solicita através do std::cin uma mensagem ao usuário e adiciona-a em uma linha do arquivo." << endl;
    cout << "./diary add <mensagem>" << endl;
    cout << "\t– Adiciona <mensagem> em uma linha do arquivo." << endl;
    cout << "./diary list" << endl;
    cout << "\t– Lista todas as mensagens salvas no arquivo.";
}

bool checkDate(ifstream &file) {
    string date;
    while (file >> date) {
        if (!date.compare(get_current_date())) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    ofstream diaryWriter("../files/diary.md", ios::app);
    ifstream diaryReader("../files/diary.md", ios::in);
    string message;
    if (argc == 1) {
        showInstructions();
    } else {
        string command = argv[1];
        if (argc == 2 && !command.compare("add")) {
            getline(cin, message);
            if (!checkDate(diaryReader)) {
                diaryWriter << "\n# " << get_current_date() << "\n\n";    
            }
            diaryWriter << "- " << get_current_time() << " " << message << endl;
        }
        if (argc > 2 && !command.compare("add")) {
            if (!checkDate(diaryReader)) {
                diaryWriter << "\n# " << get_current_date() << "\n\n";    
            }
            diaryWriter << "- " << get_current_time() << " " << argv[2] << endl;
        }
        if (argc >= 2 && !command.compare("list")) {
            while (getline(diaryReader, message)) {
                if (message[0] == '-') {
                    cout << message << endl;
                }
            }
        }
    }
    diaryWriter.close();
    diaryReader.close();
    return 0;
}