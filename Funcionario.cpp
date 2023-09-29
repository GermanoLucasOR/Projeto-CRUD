#include <iostream>
#include <string>
#include "Funcionario.h"
#include "Pessoa.h"

using namespace std;

Funcionario::Funcionario() : Pessoa(){
  cargo = " ";
}

string Funcionario::getCargo() {
  return cargo;
}

void Funcionario :: setCargo(string cg) {
  cargo = cg;
}

void Funcionario::exibirFuncionario(){
  Pessoa::exibir();
  cout << "Cargo: " << cargo << endl;
}

