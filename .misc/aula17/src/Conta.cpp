#include "Conta.h"

int Conta::totalContas;

Conta::Conta() {
  this->saldo = 0;
  this->totalContas++;
}

Cliente Conta::getCliente() {
  return this->cliente;
}

Agencia Conta::getAgencia() {
  return this->agencia;
}

int Conta::getNumero() {
  return this->numero;
}

std::string Conta::getTitular() {
  return this->titular;
}

float Conta::getSaldo() {
  return this->saldo;
}

int Conta::getTotalContas(){
  return this->totalContas;
}

void Conta::setCliente(Cliente cliente) {
  this->cliente = cliente;
}

void Conta::setAgencia(Agencia agencia) {
  this->agencia = agencia;
}

void Conta::setNumero(int numero) {
  this->numero = numero;
}

void Conta::setTitular(std::string titular) {
  this->titular = titular;
}

void Conta::setSaldo(float saldo) {
  this->saldo = saldo;
}

float Conta::saca(float valor) {
  if (valor > saldo) {
    std::cout << "Saldo insuficiente." << std::endl;
    return 0;
  } else {
    saldo -= valor;
    std::cout << "Saque realizado com sucesso." << std::endl;
    return valor;
  }
}

void Conta::deposita(float valor) {
  if (valor > 0) {
    saldo += valor;
    std::cout << "Depósito realizado com sucesso." << std::endl;
  }
}

void Conta::transfere(float valor, Conta* conta) {
  if (valor > saldo) {
    std::cout << "Saldo insuficiente." << std::endl;
  } else {
    saldo -= valor;
    conta->saldo += valor;
    std::cout << "Transferência realizada com sucesso." << std::endl;
  }
}