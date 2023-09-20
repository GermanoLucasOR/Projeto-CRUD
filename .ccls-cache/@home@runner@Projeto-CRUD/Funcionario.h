#include <iostream>
#include <string>
#include "Pessoa.h"
#pragma once

using namespace std;

class Funcionario : public Pessoa{
  public:
    Funcionario();
    void setCargo(string cg);
    string getCargo();
    void exibirFuncionario();

  private:
    string cargo;
};