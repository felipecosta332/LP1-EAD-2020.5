/*
Presença de hoje: Gravar a mensagem do exercício passado 
em um arquivo
*/

#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char* argv[]) {
    using namespace std;
    ofstream file("../files/aula3.txt", ios::app);
    string message;
    if (argc == 1) {
        file << "Uso: ./prog add <mensagem>\n";
    } else if (argc == 2 && !(strcmp(argv[1], "add"))) {
        getline(cin, message);
        file << message << endl;
    } else if (argc > 2 && !(strcmp(argv[1], "add"))) {
        file << argv[2] << endl;
    }
    file.close();
    return 0;
}