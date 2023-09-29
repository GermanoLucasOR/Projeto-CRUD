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
int Prisioneiro :: getNumC() {
  return numCela;
}
int Prisioneiro :: getPena() {
  return pena;
}
string Prisioneiro :: getGangue(){
  return gangue;
}

void Prisioneiro :: setGangue(string g){
  gangue = g;
}
void Prisioneiro :: setCrime(string cr) {
  crime = cr;
}
void Prisioneiro :: setNumC(int c) {
  numCela = c;
}
void Prisioneiro :: setPena(int p) {
  pena = p;
}

void Prisioneiro :: exibirPrisioneiro(){
  Pessoa::exibir();
  string singular_plural = (pena == 1) ? " ano" : " anos";
  cout << "Gangue afiliada: " << gangue << "\n" << "Crime: " << crime << "\n" << "Pena: " << pena << singular_plural << endl;
}
