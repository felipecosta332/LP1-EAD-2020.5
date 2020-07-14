/*
Escreva uma classe que representa um funcionário, registrando seu nome, empresa, departamento, salário 
e data de admissão. Escreva também uma classe que representa uma empresa, contendo nome e CNPJ. Em todas 
as classes defina os atributos como private e os métodos como public, utilizando métodos para modificar 
os atributos. Por fim, crie um programa onde:
a. Crie uma empresa;
b. Adicione a empresa alguns funcionários (solicitar no inicio quantos);
c. Dê aumento de 10% a todos os funcionários de um determinado departamento.
*/

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
  private:
    std::string nome;
    std::string departamento;
    float salario;
    std::string datadeadmissao;
  public:
    Funcionario();
    Funcionario(const std::string& nome, const std::string& departamento, float salario, const std::string& datadeadmissao);
    std::string getNome();
    std::string getDepartamento();
    float getSalario();
    std::string getDataDeAdmissao();
    void setNome(const std::string& nome);
    void setDepartamento(const std::string& departamento);
    void setSalario(float salario);
    void setDataDeAdmissao(const std::string& datadeadmissao);
};

#endif