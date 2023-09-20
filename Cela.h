#include <iostream>
#include <string>
#include <vector>
#include "Prisioneiro.h"
#include "Pessoa.h"
#pragma once

using namespace std;

class Cela{
  public: 
    Cela();
    Prisioneiro* getPrisioneiro(string id);
    void adicionarPrisioneiro(Pessoa* p);
    void penaPaga(string i);

  private:
    vector<Pessoa*> prisioneiro;
};

