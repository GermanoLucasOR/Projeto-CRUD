#include <iostream>
#include <string>
#include <vector>
#include "Funcionario.h"
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

Funcionario Bloco :: getFuncionario(string id){
  int tamanhoV = funcionario.size();
  
  for(int i = 0; i < tamanhoV; i++) {
    if(funcionario[i]->getID() == id) {
      return *((Funcionario*)funcionario[i]);
    }
  }
  
}

void Bloco::adicionarCela(Cela c){
  cela.push_back(c);
  cout << "Cela adicionada com sucesso." << endl;
}

void Bloco::setGenero(string g) {
  genero = g;
}

void Bloco::adicionarFuncionario(Pessoa* f){  
  int tamanhoVec = funcionario.size();
  bool funcionarioExiste = false;
  
  for(int i = 0; i < tamanhoVec; i++){
    if(funcionario[i]->getID() == f->getID() || funcionario[i]->getCPF() == f->getCPF()){
      funcionarioExiste = true;
      break;
    }
  }  

  if(!funcionarioExiste){
      funcionario.push_back(f);
      cout << "Funcionario adicionado ao bloco com sucesso!" << endl;
      funcionario.resize(++tamanhoVec);
    }else{
      cout << "Funcionario já existe." << endl;
    }
}