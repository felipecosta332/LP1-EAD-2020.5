#include "ClientePJ.h"

std::string ClientePJ::getRazaoSocial() {
  return this->RazaoSocial;
}

std::string ClientePJ::getCNPJ() {
  return this->CNPJ;
}

void ClientePJ::setRazaoSocial(std::string RazaoSocial) {
  this->RazaoSocial = RazaoSocial;
}

void ClientePJ::setCNPJ(std::string CNPJ) {
  this->CNPJ = CNPJ;
}