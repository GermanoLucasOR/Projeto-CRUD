#include <iostream>
#include <string>
#include "Cela.h"
#include "Bloco.h"

using namespace std;

Bloco::Bloco() {}

Cela Bloco::getCela(int i) {
  return cela[i];
}
string Bloco::getGenero() {
  return genero;
}

Funcionario Bloco::getFuncionario(int i){
  return funcionario[i];
}

void Bloco::setCela(Cela c, int i) {
  cela[i] = c;
  cout << "Cela adicionada com sucesso." << endl;
}
void Bloco::setGenero(string g) {
  genero = g;
}

void Bloco::setFuncionario(Funcionario f, int i){
  funcionario[i] = f;
  cout << "Funcionário adicionado ao bloco com sucesso." << endl;
}