#include <iostream>
#include <string>
#include "Data.h"
#pragma once

using namespace std;

class Pessoa{
  public:
    Pessoa();
    Pessoa(string n, string g, string c, Data d);
    string getNome();
    string getGenero();
    string getCPF();
    string getID();
    Data getDataNasc();
    void setNome(string n);
    void setGenero(string g);
    void setCPF(string c);
    void setID(string ID);
    void setDataNasc(Data d);
    void exibir();
    
  protected:
    string nome, genero, cpf, id;
    Data dataNascimento;
};