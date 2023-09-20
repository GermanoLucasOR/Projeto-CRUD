#include <iostream>
#include <string>
#include "Cela.h"
#include "Funcionario.h"
#pragma once

using namespace std;

class Bloco {
  public:
    Bloco();
    Cela getCela(int i);
    string getGenero();
    Funcionario getFuncionario(int i);
    void setCela(Cela c, int i);
    void setGenero(string g);
    void setFuncionario(Funcionario f, int i);

  private:
    Cela cela[10];
    string genero;
    Funcionario funcionario[10];
};