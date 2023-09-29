#include "Pessoa.h"
#include "Prisioneiro.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Cela {
public:
  Cela();
  // void lerPrisioneiro(ifstream& lp);
  Prisioneiro *getPrisioneiro(string id);
  void adicionarPrisioneiro(Pessoa *p);
  int getNumero();
  int contaPrisioneiros();
  bool pExisteC(string id, string cpf);
  bool pExiste(string id);
  bool pConfereCPF(string cpf);
  void setNumero(int n);
  void setVectorP(vector<Pessoa *> p);
  void exibirTodosP();
  void alterarPrisioneiro(string cpf);
  void removerPrisioneiro(string cpf);
  void confirmarRemocaoP(string id);
  void salvarPrisioneiro(ofstream &listadeprisioneiros);
  // void novoPrisioneiro();

private:
  vector<Pessoa *> prisioneiro;
  int numero;
};
