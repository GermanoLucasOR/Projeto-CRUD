#include <iostream>
#include <string>
#include "Pessoa.h"
#pragma once

using namespace std;

class Funcionario : public Pessoa{
  public:
    Funcionario();
    void setID(string ID);
    void setCargo(string cg);
    string getID();
    string getCargo();
    void exibir();

  private:
    string cargo, id;
};