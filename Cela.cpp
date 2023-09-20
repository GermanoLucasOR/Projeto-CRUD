#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cela.h"
#include "Prisioneiro.h"
#include "Pessoa.h"

using namespace std;

Cela::Cela(){}

Prisioneiro* Cela::getPrisioneiro(string id) {
  int tamanhoV = prisioneiro.size();
  
  for(int i = 0; i < tamanhoV; i++) {
    if(prisioneiro[i]->getID() == id) {
      return ((Prisioneiro*)prisioneiro[i]); 
    }
  } 
}

void Cela::adicionarPrisioneiro(Pessoa* p) {  
  int tamanhoV = prisioneiro.size();
  bool prisioneiroExiste = false;

  for (int i = 0; i < tamanhoV; i++) {
  if (prisioneiro[i]->getID() == p->getID() || prisioneiro[i]->getCPF() == p->getCPF()) {
    prisioneiroExiste = true;
    cout << "Prisioneiro já existe." << endl;
    break; // Use 'break' para sair do loop quando um prisioneiro for encontrado.
  }
}

  prisioneiro.push_back(p);
  cout << "Prisioneiro adicionado!" << endl;
  ofstream arquivoPrisioneiro("listadeprisioneiros.txt", ios::out | ios::app);  
  arquivoPrisioneiro << p->getNome() << " " << p->getGenero() << " " << p->getCPF() << " " << p->getDataNasc().getMes() << "/" << p->getDataNasc().getAno() << " "  << p->getID() << " " << ((Prisioneiro*)p)->getCrime() << " " << ((Prisioneiro*)p)->getPena() << " " << endl;
  arquivoPrisioneiro.close();
}


/*void Cela::penaPaga(string id) {
  for (int i = 0; i < 100; i++) {
    if (prisioneiro[i].getID() == id) {
  
    }
  }
}*/
