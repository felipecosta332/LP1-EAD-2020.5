#include "Agencia.h"

std::string Agencia::getNome() {
  return this->nome;
}

int Agencia::getNumeroDaAgencia() {
  return this->numeroDaAgencia;
}

void Agencia::setNome(std::string nome) {
  this->nome = nome;
}

void Agencia::setNumeroDaAgencia(int numeroDaAgencia) {
  this->numeroDaAgencia = numeroDaAgencia;
}