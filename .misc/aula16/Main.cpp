/*
Escreva uma classe que representa um funcionário, registrando seu nome, empresa, departamento, salário 
e data de admissão. Escreva também uma classe que representa uma empresa, contendo nome e CNPJ. Em todas 
as classes defina os atributos como private e os métodos como public, utilizando métodos para modificar 
os atributos. Por fim, crie um programa onde:
a. Crie uma empresa;
b. Adicione a empresa alguns funcionários (solicitar no inicio quantos);
c. Dê aumento de 10% a todos os funcionários de um determinado departamento.
*/

#include "Empresa.h"

int main() {
  int input;
  std::string nome, departamento;
  Empresa empresa("Padaria", "XX.XXX.XXX/YYYY-ZZ");
  std::cout << "Quantos funcionários deseja adicionar?" << std::endl;
  std::cin >> input;
  for (int i = 0; i < input; i++) {
    std::cout << "Digite o nome do funcionário #" << (i + 1) << std::endl;
    std::cin >> nome;
    std::cout << "Digite o departamento do funcionário #" << (i + 1) << std::endl;
    std::cin >> departamento;
    Funcionario funcionario(nome, departamento, 2000, "13/07/2020");
    empresa.addFuncionario(funcionario);
  }
  empresa.listarFuncionarios();
  std::cout << "Qual departamento vai ter aumento de 10%?" << std::endl;
  std::cin >> departamento;
  empresa.darAumentoPorDepartamento(10, departamento);
  empresa.listarFuncionarios();
  return 0;
}