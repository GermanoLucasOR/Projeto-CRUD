#include <iostream>
#include <string>
#include "Prisioneiro.h"
#include "Pessoa.h"

using namespace std;

Prisioneiro :: Prisioneiro() : Pessoa() {
  id = " ";
  crime = " ";
}

string Prisioneiro :: getID(){
  return id;
}

string Prisioneiro :: getCrime() {
  return crime;
}

void Prisioneiro :: setID(string ID) {
  id = ID;
}
void Prisioneiro :: setCrime(string cr) {
  crime = cr;
}

void Prisioneiro :: exibir(){
  Pessoa::exibir();
  cout << "ID: " << id << "\n" << "Crime: " << crime << endl;
}


