#include <iostream>
#include <string>
#pragma once

using namespace std;

class Pessoa{
  public:
    Pessoa();
    Pessoa(string n, string g, string c, int idad);
    string getNome();
    string getGenero();
    string getCPF();
    int getIdade();
    void setNome(string n);
    void setGenero(string g);
    void setCPF(string c);
    void setIdade(float i);
    void exibir();
    
  protected:
    string nome, genero, cpf;
    int idade;
};