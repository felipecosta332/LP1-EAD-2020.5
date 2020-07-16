#include "Conta.h"

int main() {
  Conta A;
  Conta B;
  std::cout << "Total de contas de A: " << A.getTotalContas() << std::endl;
  std::cout << "Total de contas de B: " << B.getTotalContas() << std::endl;
  // A.saldo = 0;
  // B.saldo = 0;
  A.deposita(10000);
  A.transfere(10000, &B);
  std::cout << "O saldo de A é: " << A.getSaldo() << std::endl;
  std::cout << "O saldo de B é: " << B.getSaldo() << std::endl;
  B.saca(2999);
  std::cout << "O saldo de B agora é: " << B.getSaldo() << std::endl;
  return 0;
}