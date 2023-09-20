#include <iostream>
#include <string>
#include "Cela.h"
#include "Prisioneiro.h"

using namespace std;

Cela::Cela(){
  qPrisioneiros = 0;
}

Prisioneiro Cela::getPrisioneiro(int i) {
  return prisioneiro[i];
}

void Cela::adicionarPrisioneiro(Prisioneiro p) {
  if(qPrisioneiros < 100){
    prisioneiro[qPrisioneiros] = p;
    qPrisioneiros++;
    cout << "Prisioneiro adicionado com sucesso." << endl;
  }else{
    cout << "A cela está cheia. Não é possível adicionar mais prisioneiros." << endl;
  }
}

void Cela::penaPaga(string id) {
  for (int i = 0; i < 100; i++) {
    if (prisioneiro[i].getID() == id) {
  
    }
  }
}
