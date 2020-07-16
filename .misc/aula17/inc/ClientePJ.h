#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

class ClientePJ {
  private:
    std::string RazaoSocial;
    std::string CNPJ;
  public:
    std::string getRazaoSocial();
    std::string getCNPJ();
    void setRazaoSocial(std::string RazaoSocial);
    void setCNPJ(std::string CNPJ);
};

#endif