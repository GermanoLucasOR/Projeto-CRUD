#include <iostream>
#include <string>
#include "Pessoa.h"
#pragma once

using namespace std;

class Prisioneiro : public Pessoa{
  public:
    Prisioneiro();
    string getCrime();
    int getPena();
    void setCrime(string c);
    void setPena(int p);
    void exibirPrisioneiro();

  private:
    string crime;
    int pena;
};