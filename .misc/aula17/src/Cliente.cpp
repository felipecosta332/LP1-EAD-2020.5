#include "Cliente.h"

int Cliente::totalClientes;

Cliente::Cliente() {
  this->nome = "Fulano";
  this->cpf = "000.000.000-00";
  this->totalClientes++;
}

std::string Cliente::getNome() {
  return this->nome;
}

std::string Cliente::getCPF() {
  return this->cpf;
}

int Cliente::getTotalClientes() {
  return this->totalClientes;
}

void Cliente::setNome(std::string nome) {
  this->nome = nome;
}

void Cliente::setCPF(std::string cpf) {
  this->cpf = cpf;
}