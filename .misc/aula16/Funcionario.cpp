/*
Escreva uma classe que representa um funcionário, registrando seu nome, empresa, departamento, salário 
e data de admissão. Escreva também uma classe que representa uma empresa, contendo nome e CNPJ. Em todas 
as classes defina os atributos como private e os métodos como public, utilizando métodos para modificar 
os atributos. Por fim, crie um programa onde:
a. Crie uma empresa;
b. Adicione a empresa alguns funcionários (solicitar no inicio quantos);
c. Dê aumento de 10% a todos os funcionários de um determinado departamento.
*/

#include "Funcionario.h"

Funcionario::Funcionario() {}

Funcionario::Funcionario(const std::string& nome, const std::string& departamento, float salario, const std::string& datadeadmissao) {
  setNome(nome);
  setDepartamento(departamento);
  setSalario(salario);
  setDataDeAdmissao(datadeadmissao);
}

std::string Funcionario::getNome() {
  return this->nome;
}

std::string Funcionario::getDepartamento() {
  return this->departamento;
}

float Funcionario::getSalario() {
  return this->salario;
}

std::string Funcionario::getDataDeAdmissao() {
  return this->datadeadmissao;
}

void Funcionario::setNome(const std::string& nome) {
  this->nome = nome;
}

void Funcionario::setDepartamento(const std::string& departamento) {
  this->departamento = departamento;
}

void Funcionario::setSalario(float salario) {
  if (salario > 1000) {
    this->salario = salario;
  } else {
    this->salario = 1000;
  }
}

void Funcionario::setDataDeAdmissao(const std::string& datadeadmissao) {
  this->datadeadmissao = datadeadmissao;
}