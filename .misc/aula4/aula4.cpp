/*
Presença de hoje: Adicionar o comando 'list' ao nosso 
programa. Este comando não recebe nenhum parâmetro 
adicional e ao ser chamado deve listar o conteúdo do 
arquivo de mensagens.
*/

#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char* argv[]) {
    using namespace std;
    fstream file("../files/aula3.txt", ios::app | ios::in);
    string message;
    if (argc == 1) {
        file << "Uso: ./prog add <mensagem>\n";
    }
    if (argc == 2 && !(strcmp(argv[1], "add"))) {
        getline(cin, message);
        file << message << endl;
    }
    if (argc > 2 && !(strcmp(argv[1], "add"))) {
        file << argv[2] << endl;
    }
    if (argc >= 2 && !(strcmp(argv[1], "list"))) {
        while (getline(file, message)) {
            cout << message << endl;
        }
    }
    file.close();
    return 0;
}