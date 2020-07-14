/*
Escreva uma classe que representa um funcionário, registrando seu nome, empresa, departamento, salário 
e data de admissão. Escreva também uma classe que representa uma empresa, contendo nome e CNPJ. Em todas 
as classes defina os atributos como private e os métodos como public, utilizando métodos para modificar 
os atributos. Por fim, crie um programa onde:
a. Crie uma empresa;
b. Adicione a empresa alguns funcionários (solicitar no inicio quantos);
c. Dê aumento de 10% a todos os funcionários de um determinado departamento.
*/

#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <string>
#include <vector>
#include "Funcionario.h"

class Empresa {
  private:
    std::string nome;
    std::string cnpj;
    std::vector<Funcionario> funcionarios;
  public:
    Empresa();
    Empresa(const std::string& nome, const std::string& cnpj);
    std::string getNome();
    std::string getCNPJ();
    Funcionario getFuncionario(int index);
    void setNome(std::string nome);
    void setCNPJ(std::string cnpj);
    void addFuncionario(Funcionario funcionario);
    void darAumentoPorDepartamento(float percentual, std::string departamento);
    void listarFuncionarios();
};

#endif