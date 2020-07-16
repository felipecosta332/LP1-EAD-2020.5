#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Agencia.h"

class Conta {
  private:
    Cliente cliente;
    Agencia agencia;
    int numero;
    std::string titular;
    float saldo;
    static int totalContas;
  public:
    Conta();
    Cliente getCliente();
    Agencia getAgencia();
    int getNumero();
    std::string getTitular();
    float getSaldo();
    int getTotalContas();
    void setCliente(Cliente cliente);
    void setAgencia(Agencia agencia);
    void setNumero(int numero);
    void setTitular(std::string titular);
    void setSaldo(float saldo);
    float saca(float valor);
    void deposita(float valor);
    void transfere(float valor, Conta* conta);
};

#endif