#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
  private:
    std::string nome;
    std::string cpf;
    static int totalClientes;
  public:
    Cliente();
    std::string getNome();
    std::string getCPF();
    int getTotalClientes();
    void setNome(std::string nome);
    void setCPF(std::string cpf);
};

#endif