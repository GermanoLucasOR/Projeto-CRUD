#include "Cela.h"
#include "Funcionario.h"
#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Bloco {
public:
  Bloco();
  Cela* getCelaN(int n); 
  void lerFuncionario();
  void lerPrisioneiros();
  void lerCela(); 
  Cela* getCela(string id);
  Funcionario *getFuncionario(string id);
  int contaFuncionarios();
  int contaCelas();
  int contaP();
  int contaTudo();
  bool pExisteB(Pessoa* p);
  bool pExisteID(string id);
  bool fExiste(string id);  
  void exibirTodosF();
  void fConfereCPF(Pessoa *f);
  bool pConfereCpfBloco(Pessoa *p);
  void adicionarCela(Cela *c);
  void adicionarFuncionario(Pessoa *f);
  void alterarFuncionario(string cpf);
  void confirmarRemocaoF(string id);
  void removerFuncionario(string id);
  void salvarFuncionario();
  void salvarPrisioneiro();
  void salvarCela();
  void exibirTodosP();

private:
  vector<Cela*> cela;
  vector<Pessoa*> funcionario;
};
