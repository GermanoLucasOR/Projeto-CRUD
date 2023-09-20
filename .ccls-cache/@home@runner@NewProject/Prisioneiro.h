#include <iostream>
#include <string>
#include "Pessoa.h"
#pragma once

using namespace std;

class Prisioneiro : public Pessoa{
  public:
    Prisioneiro();
    string getID();
    string getCrime();
    void setID(string iD);
    void setCrime(string c);
    void exibir();

  private:
    string id;
    string crime;
};