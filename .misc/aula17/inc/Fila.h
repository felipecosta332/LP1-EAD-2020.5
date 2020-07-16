#ifndef FILA_H
#define FILA_H

#include <cstddef>
#include <algorithm>
#include <iostream>

template <class T>
class Fila {
 private:
  T* fila;
  std::size_t tamanho_fila;
  std::size_t capacidade_fila;
  void dobra_capacidade();

 public:
  Fila();
  ~Fila();

  void empurra(T e);
  T final();
  T frente();
  bool vazio();
  void retira();
  std::size_t tamanho();
};

#endif