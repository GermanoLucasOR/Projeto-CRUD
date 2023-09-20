#include <iostream>
#include <string>
#include "Prisioneiro.h"
#include "Pessoa.h"

using namespace std;

Prisioneiro :: Prisioneiro() : Pessoa() {
  id = " ";
  crime = " ";
}
string Prisioneiro :: getCrime() {
  return crime;
}
int Prisioneiro :: getPena() {
  return pena;
}

void Prisioneiro :: setCrime(string cr) {
  crime = cr;
}
void Prisioneiro :: setPena(int p) {
  pena = p;
}

void Prisioneiro :: exibirPrisioneiro(){
  Pessoa::exibir();
  cout << "Crime: " << crime << "\n" << "Pena: " << pena << " anos" << endl;
}


