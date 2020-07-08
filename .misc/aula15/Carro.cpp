/*
Modifique o programa do Banco para que possa contar a quantidade de contas e clientes criados. 
Modifique o programa do Carro para também contar a quantidade de carros criados. Ambos os programas 
devem fazer uso de métodos construtores com implementação a sua escolha.
*/

#include <iostream>
#include <string>

class carro{
  public:
    carro(){
      this->totalCarros++;
    }
    std::string tipo;
    std::string cor;
    std::string placa;
    int numPortas;
    static int totalCarros;
};
int carro::totalCarros;

int main(){
  carro a;
  std::cout << "Total de carros: " << a.totalCarros << std::endl;
  carro b;
  std::cout << "Total de carros: " << a.totalCarros << std::endl;
  carro c;
  std::cout << "Total de carros: " << a.totalCarros << std::endl;
  carro d;
  std::cout << "Total de carros: " << a.totalCarros << std::endl;
  return 0;
}