/*
Modifique o programa do Banco para que possa contar a quantidade de contas e clientes criados. 
Modifique o programa do Carro para também contar a quantidade de carros criados. Ambos os programas 
devem fazer uso de métodos construtores com implementação a sua escolha.
*/

#include <string>
#include <iostream>

class Cliente {
  public:
    Cliente() {
      this->nome = "Fulano";
      this->cpf = "000.000.000-00";
      this->totalClientes++;
    }
    std::string nome;
    std::string cpf;
    static int totalClientes;
};
int Cliente::totalClientes;

class Agencia {
  public:
    std::string nome;
    unsigned int numeroDaAgencia;
};

class Conta {
  private:
    static int totalContas;
  public:
    Conta(){
      this->saldo = 0;
      this->totalContas++;
    }
    Cliente cliente;
    Agencia agencia;
    int numero;
    std::string titular;
    float saldo;
    int getTotalContas(){
      return totalContas;
    }
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
int Conta::totalContas;

int main() {
  Conta A;
  Conta B;
  std::cout << "Total de contas de A: " << A.getTotalContas() << std::endl;
  std::cout << "Total de contas de B: " << B.getTotalContas() << std::endl;
  // A.saldo = 0;
  // B.saldo = 0;
  A.deposita(10000);
  A.transfere(10000, &B);
  std::cout << "O saldo de A é: " << A.saldo << std::endl;
  std::cout << "O saldo de B é: " << B.saldo << std::endl;
  B.saca(2999);
  std::cout << "O saldo de B agora é: " << B.saldo << std::endl;
  return 0;
}