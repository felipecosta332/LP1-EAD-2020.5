/*
Prática
    • Criar um programa que recebe como argumentos de linha
    de comando a seguinte ação:
        • add Esta ação verifica se há outro parâmetro de linha de
        comando:
            • Se houver ele imprime Mensagem adicionada
            • Se não houver, ele solicita ao usuário um parâmetro, e depois
            imprime Mensagem Adicionada
    • Se não receber nenhum parâmetro deve imprimir seu uso
    • Exemplos de Entrada e suas respectivas saídas
        • ./prog
            • Saída: Uso: ./prog add <mensagem>
        • ./prog add
            • Solicita ao usuário uma mensagem
            • Imprime Mensagem Adicionada
        • ./prog add mensagem
            • Imprime Mensagem Adicionada
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