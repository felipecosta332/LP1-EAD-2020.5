#include "Fila.h"

template <class T>
Fila<T>::Fila() : fila(nullptr), tamanho_fila(0), capacidade_fila(2) {
  this->fila = new T[this->capacidade_fila];
}

template <class T>
Fila<T>::~Fila() {
  delete[] this->fila;
}

template <class T>
void Fila<T>::empurra(T e) {
  if (this->tamanho_fila >= this->capacidade_fila) {
    this->dobra_capacidade();
  }

  this->fila[this->tamanho_fila] = e;
  this->tamanho_fila += 1;
}

template <class T>
T Fila<T>::final() {
  return this->fila[this->tamanho_fila - 1];
}

template <class T>
T Fila<T>::frente() {
  return this->fila[0];
}

template <class T>
bool Fila<T>::vazio() {
  return this->tamanho_fila == 0;
}

template <class T>
void Fila<T>::retira() {
  if (this->vazio()) {
    return;
  }

  for (std::size_t i = 0; i < this->tamanho_fila - 1; ++i) {
    this->fila[i] = this->fila[i + 1];
  }

  this->tamanho_fila -= 1;
}

template <class T>
std::size_t Fila<T>::tamanho() {
  return this->tamanho_fila;
}

template <class T>
void Fila<T>::dobra_capacidade() {
  this->capacidade_fila *= 2;

  T* temp_array = new T[this->capacidade_fila];
  std::copy(this->fila, this->fila + this->tamanho_fila, temp_array);

  delete[] this->fila;
  this->fila = temp_array;
}