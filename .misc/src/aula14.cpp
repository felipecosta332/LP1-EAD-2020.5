/*
Exercício valendo a presença de hoje: Crie a classe Cliente e a classe Agencia e junte com a classe 
Conta através de composição. A classe Cliente deve ter como atributos nome e cpf. A classe Agencia deve 
ter os atributos nome, numeroDaAgencia (esqueçam o CNPJ). Por enquanto essas classes não precisam de 
métodos.
*/

#include <string>
#include <iostream>

class Cliente {
  public:
    std::string nome;
    std::string cpf;
};

class Agencia {
  public:
    std::string nome;
    unsigned int numeroDaAgencia;
};

class Conta {
  public:
    Cliente cliente;
    Agencia agencia;
    int numero;
    std::string titular;
    float saldo;
    float saca(float valor) {
      if (valor > saldo) {
        std::cout << "Saldo insuficiente." << std::endl;
        return 0;
      } else {
        saldo -= valor;
        std::cout << "Saque realizado com sucesso." << std::endl;
        return valor;
      }
    }
    void deposita(float valor) {
      if (valor > 0) {
        saldo += valor;
        std::cout << "Depósito realizado com sucesso." << std::endl;
      }
    }
    void transfere(float valor, Conta* conta) {
      if (valor > saldo) {
        std::cout << "Saldo insuficiente." << std::endl;
      } else {
        saldo -= valor;
        conta->saldo += valor;
        std::cout << "Transferência realizada com sucesso." << std::endl;
      }
    }
};

int main() {
  Conta A;
  Conta B;
  A.saldo = 0;
  B.saldo = 0;
  A.deposita(10000);
  A.transfere(10000, &B);
  std::cout << "O saldo de A é: " << A.saldo << std::endl;
  std::cout << "O saldo de B é: " << B.saldo << std::endl;
  B.saca(2999);
  std::cout << "O saldo de B agora é: " << B.saldo << std::endl;
  return 0;
}