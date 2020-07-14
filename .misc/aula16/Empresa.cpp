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

Empresa::Empresa() {}

Empresa::Empresa(const std::string& nome, const std::string& cnpj) {
  setNome(nome);
  setCNPJ(cnpj);
}

std::string Empresa::getNome() {
  return this->nome;
}

std::string Empresa::getCNPJ() {
  return this->cnpj;
}

Funcionario Empresa::getFuncionario(int index) {
  return this->funcionarios[index];
}

void Empresa::setNome(std::string nome) {
  this->nome = nome;
}

void Empresa::setCNPJ(std::string cnpj) {
  this->cnpj = cnpj;
}

void Empresa::addFuncionario(Funcionario funcionario) {
  this->funcionarios.push_back(funcionario);
}

void Empresa::darAumentoPorDepartamento(float percentual, std::string departamento) {
  float factor;
  if (percentual > 0) {
    factor = 1 + (percentual / 100);
  } else {
    factor = 1;
  }
  for (int i = 0; i < funcionarios.size(); i++) {
    if (funcionarios[i].getDepartamento() == departamento) {
      funcionarios[i].setSalario(funcionarios[i].getSalario() * factor);
    }
  }
}

void Empresa::listarFuncionarios() {
  for (int i = 0; i < funcionarios.size(); i++) {
    std::cout << "\nNOME: " << funcionarios[i].getNome() << std::endl;
    std::cout << "DEPARTAMENTO: " << funcionarios[i].getDepartamento() << std::endl;
    std::cout << "DATA DE ADMISSÃO: " << funcionarios[i].getDataDeAdmissao() << std::endl;
    std::cout << "SALÁRIO: " << funcionarios[i].getSalario() << std::endl;
  }
}