/*
A atividade de presença de hoje consiste em criar uma classe Conta com os atributos numero, titular, 
saldo e o métodos, saca, deposita e transfere. O método transfere além de receber o valor recebe também 
a referência para um objeto do tipo Conta
*/

#include <string>
#include <iostream>

class Conta {
  public:
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