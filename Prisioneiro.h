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
    int getNumC();
    string getGangue();
    int getCela();
    void setCrime(string c);
    void setNumC(int c);
    void setPena(int p);
    void setGangue(string g);
    void exibirPrisioneiro();
  
  private:
    string crime, gangue;
    int pena, numCela;
};
