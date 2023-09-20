#include <iostream>
#include <string>
#include "Funcionario.h"
#include "Pessoa.h"

using namespace std;

Funcionario::Funcionario() : Pessoa(){
  id = " ";
  cargo = " ";
}

string Funcionario::getID(){
  return id;
}

string Funcionario::getCargo() {
  return cargo;
}

void Funcionario ::setID(string ID) {
  id = ID;
}

void Funcionario :: setCargo(string cg) {
  cargo = cg;
}

void Funcionario::exibir(){
  Pessoa::exibir();
  cout << "ID: " << id << " - " << "Cargo: " << cargo << endl;
}
