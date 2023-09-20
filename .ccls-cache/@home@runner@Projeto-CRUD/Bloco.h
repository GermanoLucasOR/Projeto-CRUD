#include <iostream>
#include <string>
#include <vector>
#include "Cela.h"
#include "Funcionario.h"
#pragma once

using namespace std;

class Bloco {
  public:
    Bloco();
    Cela getCela(int i);
    string getGenero();
    Funcionario getFuncionario(string id);
    void adicionarCela(Cela c);
    void setGenero(string g);
    void adicionarFuncionario(Pessoa *f);

  private:
    vector<Cela> cela;
    string genero;
    vector<Pessoa*> funcionario;
};