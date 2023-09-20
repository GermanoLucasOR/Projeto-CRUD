#include <iostream>
#include <string>
#include "Prisioneiro.h"
#pragma once

using namespace std;

class Cela{
  public: 
    Cela();
    Prisioneiro getPrisioneiro(int i);
    void adicionarPrisioneiro(Prisioneiro p);
    void penaPaga(string i);

  private:
    Prisioneiro prisioneiro[100];
    int qPrisioneiros;
};

