#ifndef AGENCIA_H
#define AGENCIA_H

#include <string>

class Agencia {
  private:
    std::string nome;
    unsigned int numeroDaAgencia;
  public:
    std::string getNome();
    int getNumeroDaAgencia();
    void setNome(std::string nome);
    void setNumeroDaAgencia(int numeroDaAgencia);
};

#endif