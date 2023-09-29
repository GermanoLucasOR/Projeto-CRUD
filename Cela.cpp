#include "Cela.h"
#include "Data.h"
#include "Pessoa.h"
#include "Prisioneiro.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Cela::Cela() {}

int Cela::getNumero() { // Retorna o numero da cela
  return numero;
}

void Cela::setNumero(int n) { numero = n; }

void Cela::setVectorP(vector<Pessoa *> p) { prisioneiro = p; }

bool Cela ::pExisteC(string id,
                     string cpf) { // Verifica se Existe o prisioneiro na cela
  bool pExiste = false;

  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getID() == id || prisioneiro[i]->getCPF() == cpf) {
      pExiste = true;
    }
  }

  if (pExiste) {
    return true;
  } else {
    return false;
  }
}
bool Cela ::pExiste(string id) {
  bool pExiste = false;

  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getID() == id) {
      pExiste = true;
    }
  }

  if (pExiste) {
    return true;
  } else {
    return false;
  }
}

Prisioneiro *
Cela::getPrisioneiro(string id) { // retorna o prisioneiro com esse ID
  int tamanhoV = prisioneiro.size();

  for (int i = 0; i < tamanhoV; i++) {
    if (prisioneiro[i]->getID() == id) {
      return ((Prisioneiro *)prisioneiro[i]);
    }
  }
  return 0;
}

void Cela::adicionarPrisioneiro(Pessoa *p) { // adiciona um prisioneiro na cela
  int tamanhoV = prisioneiro.size();
  bool prisioneiroExiste = false;

  for (int i = 0; i < tamanhoV; i++) {
    if (prisioneiro[i]->getID() == p->getID() ||
        prisioneiro[i]->getCPF() == p->getCPF()) {
      prisioneiroExiste = true;
      break;
    }
  }

  if (!prisioneiroExiste) {
    prisioneiro.push_back(p);
    cout << "Prisioneiro adicionado com sucesso!" << endl;
  } else {
    cout << "Prisioneiro já existe." << endl;
  }
}
void Cela::exibirTodosP() { // Exibe todos os prisioneiros da cela
  cout << "Numero de prisioneiros na cela: " << prisioneiro.size() << endl;
  for (int i = 0; i < prisioneiro.size(); i++) {
    ((Prisioneiro *)prisioneiro[i])->exibirPrisioneiro();
    cout << endl;
  }
}

void Cela::removerPrisioneiro(string id) {
  string ID;

  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getID() == id) {
      string nome = prisioneiro[i]->getNome();
      delete prisioneiro[i];
      prisioneiro.erase(prisioneiro.begin() + i);
      cout << "Prisioneiro -" << nome << "- removido!" << endl;
      sleep(2);
    }
  }
}

void Cela::confirmarRemocaoP(string id) {
  string opc;

  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getID() == id) {
      cout << "Você tem certeza que deseja remover o prisioneiro -"
           << prisioneiro[i]->getNome() << "-? (sim ou nao)" << endl;

      cin >> opc;
      if (opc == "sim" || opc == "Sim") {
        system("clear");
        removerPrisioneiro(id);
        system("clear");
        break;
      } else {
        system("clear");
        break;
      }
    }
  }
}

void Cela::alterarPrisioneiro(string id) {
  string nome, CPF, escolha, crime, gangue;
  int idade, dia, mes, ano, pena;
  Data data;

  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getID() == id) {
      do {
        cout << "O que deseja mudar no prisioneiro: \n"
                "(Nome, Data(Data de nascimento), CPF, Crime, Pena ou tudo):"
             << endl;
        getline(cin, escolha);

        if (escolha == "Nome" || escolha == "nome") {
          cout << "Digite o novo nome do prisioneiro: ";
          getline(cin, nome);
          prisioneiro[i]->setNome(nome);

          system("clear");
          cout << "Nome do prisioneiro alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Data" || escolha == "data") {
          cout << "Digite a nova data de nascimento do prisioneiro: ";
          cin >> dia;
          data.setDia(dia);
          cin >> mes;
          data.setMes(mes);
          cin >> ano;
          data.setAno(ano);
          cin.ignore();

          prisioneiro[i]->setDataNasc(data);

          system("clear");
          cout << "Data de nascimento do prisioneiro alterado com sucesso!"
               << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "CPF" || escolha == "cpf") {
          cout << "Digite o novo CPF do prisioneiro: ";
          getline(cin, CPF);
          prisioneiro[i]->setCPF(CPF);

          system("clear");
          cout << "CPF do prisioneiro alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Crime" || escolha == "crime") {
          cout << "Digite o novo crime do prisioneiro: ";
          getline(cin, crime);
          ((Prisioneiro *)prisioneiro[i])->setCrime(crime);

          system("clear");
          cout << "Crime do prisioneiro alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Gangue" || escolha == "gangue") {
          cout << "Digite a nova gangue do prisioneiro: ";
          getline(cin, gangue);
          ((Prisioneiro *)prisioneiro[i])->setGangue(gangue);

          system("clear");
          cout << "Gangue do prisioneiro alterada com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Pena" || escolha == "pena") {
          cout << "Digite a nova pena do prisioneiro: ";
          cin >> pena;
          cin.ignore();
          ((Prisioneiro *)prisioneiro[i])->setPena(pena);

          system("clear");
          cout << "Pena do prisioneiro alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Tudo" || escolha == "tudo") {
          cout << "Digite o nome do novo prisioneiro: ";
          getline(cin, nome);
          prisioneiro[i]->setNome(nome);
          cout << "Digite a data do novo prisioneiro: ";
          cin >> dia;
          data.setDia(dia);
          cin >> mes;
          data.setMes(mes);
          cin >> ano;
          data.setAno(ano);
          cin.ignore();
          prisioneiro[i]->setDataNasc(data);
          cout << "Digite o CPF do novo prisioneiro: ";
          getline(cin, CPF);
          prisioneiro[i]->setCPF(CPF);
          cout << "Digite a gangue do novo prisioneiro";
          getline(cin, gangue);
          ((Prisioneiro *)prisioneiro[i])->setGangue(gangue);
          cout << "Digite o crime do novo prisioneiro: ";
          getline(cin, crime);
          ((Prisioneiro *)prisioneiro[i])->setCrime(crime);
          cout << "Digite a pena do novo prisioneiro: ";
          cin >> pena;
          cin.ignore();
          ((Prisioneiro *)prisioneiro[i])->setPena(pena);
          system("clear");
          cout << "Prisioneiro alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        cout << "Quer mudar outro atributo? (sim ou nao)" << endl;
        getline(cin, escolha);

        if (escolha == "sim") {
          system("clear");
        } else {
          system("clear");
          break;
        }
      } while (escolha == "sim");

    } else {
      cout << "Esse prisioneiro não foi adicionado nessa cela!" << endl;
      sleep(2);
      system("clear");
    }
  }
}

void Cela::salvarPrisioneiro(ofstream &listadeprisioneiros) {
  for (int i = 0; i < prisioneiro.size(); i++) {
    Data data = prisioneiro[i]->getDataNasc();

    listadeprisioneiros << ((Prisioneiro *)prisioneiro[i])->getNumC() << endl;
    listadeprisioneiros << prisioneiro[i]->getNome() << endl;
    listadeprisioneiros << prisioneiro[i]->getID() << endl;
    listadeprisioneiros << prisioneiro[i]->getGenero() << endl;
    listadeprisioneiros << prisioneiro[i]->getCPF() << endl;
    listadeprisioneiros << data.getDia() << endl;
    listadeprisioneiros << data.getMes() << endl;
    listadeprisioneiros << data.getAno() << endl;
    listadeprisioneiros << ((Prisioneiro *)prisioneiro[i])->getGangue() << endl;
    listadeprisioneiros << ((Prisioneiro *)prisioneiro[i])->getCrime() << endl;
    listadeprisioneiros << ((Prisioneiro *)prisioneiro[i])->getPena() << endl;
  }
}

bool Cela ::pConfereCPF(string cpf) {
  for (int i = 0; i < prisioneiro.size(); i++) {
    if (prisioneiro[i]->getCPF() == cpf) {
      return true;
    }
  }
  return false;
}

int Cela::contaPrisioneiros() { return prisioneiro.size(); }

// void Cela::lerPrisioneiro(ifstream &listadeprisioneiros) {
//   string nome, cpf, id, genero, crime, gangue;
//   int pena, dia, mes, ano, numC;
//   Data data;
//   if (!listadeprisioneiros.is_open()) {
//     cerr << "Erro ao abrir arquivo para leitura\n";
//     // return vFuncionarios;
//     return;
//   }

//   while (listadeprisioneiros >> numC &&
//          listadeprisioneiros.ignore() &&
//          getline(listadeprisioneiros, nome) &&
//          getline(listadeprisioneiros, id) &&
//          getline(listadeprisioneiros, genero) &&
//          getline(listadeprisioneiros, cpf) &&
//          listadeprisioneiros >> dia &&
//          listadeprisioneiros >> mes &&
//          listadeprisioneiros >> ano &&
//          getline(listadeprisioneiros, gangue) &&
//          getline(listadeprisioneiros, crime) &&
//          listadeprisioneiros >> pena) {

//     cout << "teste se entrou aqui" << endl;

//     data.setDia(dia);
//     data.setMes(mes);
//     data.setAno(ano);

//     if (numC == numero) {
//       Prisioneiro *nPrisioneiro = new Prisioneiro();
//       nPrisioneiro->setNumC(numC);
//       nPrisioneiro->setNome(nome);
//       nPrisioneiro->setID(id);
//       nPrisioneiro->setGenero(genero);
//       nPrisioneiro->setCPF(cpf);
//       nPrisioneiro->setDataNasc(data);
//       nPrisioneiro->setGangue(gangue);
//       nPrisioneiro->setCrime(crime);
//       nPrisioneiro->setPena(pena);

//       prisioneiro.push_back(((Pessoa *)nPrisioneiro));
//     }
//   }
// }
