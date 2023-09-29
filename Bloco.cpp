#include "Bloco.h"
#include "Cela.h"
#include "Funcionario.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Bloco::Bloco() {
  lerFuncionario();
  // lerCela();
  // cela = lerCela();
  // lerPrisioneiros();
}

Cela *Bloco::getCelaN(int n) {
  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->getNumero() == n) {
      return cela[i];
    }
  }
  return 0;
}

Cela *Bloco ::getCela(string id) {
  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->pExiste(id)) {
      return cela[i];
    }
  }
  return 0;
}

Funcionario *
Bloco ::getFuncionario(string id) { // Retorna o funcionario do id indicado
  int tamanhoV = funcionario.size();

  for (int i = 0; i < tamanhoV; i++) {
    if (funcionario[i]->getID() == id) {
      return ((Funcionario *)funcionario[i]);
    }
  }
  return 0;
}

void Bloco ::adicionarCela(Cela *c) { // Adiciona a cela ao bloco
  bool celaExiste = false;

  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->getNumero() == c->getNumero()) {
      celaExiste = true;
      break;
    }
  }

  if (!celaExiste) {
    cela.push_back(c);
    cout << "Cela adicionada com sucesso." << endl;
  } else {
    cout << "Cela já existe." << endl;
  }
}

void Bloco ::fConfereCPF(Pessoa *f) {
  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->pConfereCPF(f->getCPF())) {
      cout << "Funcionario já existe." << endl;
    } else {
      adicionarFuncionario(f);
    }
  }
}

bool Bloco ::pConfereCpfBloco(Pessoa *p) {
  for (int i = 0; i < funcionario.size(); i++) {
    if (funcionario[i]->getCPF() == p->getCPF()) {
      cout << "Prisioneiro já existe." << endl;
      return true;
    }
  }
  return false;
}

void Bloco ::adicionarFuncionario(
    Pessoa *f) { // Adiciona o funcionario ao bloco
  int tamanhoVec = funcionario.size();
  bool funcionarioExiste = false;

  for (int i = 0; i < tamanhoVec; i++) {
    if (funcionario[i]->getID() == f->getID() ||
        funcionario[i]->getCPF() == f->getCPF()) {
      funcionarioExiste = true;
      break;
    }
  }

  if (!funcionarioExiste) {
    funcionario.push_back(f);
    cout << "Funcionario adicionado ao bloco com sucesso!" << endl;
  } else {
    cout << "Funcionario já existe." << endl;
  }
}

void Bloco ::alterarFuncionario(string id) { // altera o funcionario do ID indicado
  string nome, CPF, ID, escolha, cargo;
  int idade, dia, mes, ano;
  Data data;

  for (int i = 0; i < funcionario.size(); i++) {
    if (funcionario[i]->getID() == id) {
      do {
        cout << "O que deseja mudar no funcionario: \n"
                "(Nome, Data(Data de nascimento), CPF, ID, Cargo) ou Tudo:"
             << endl;
        getline(cin, escolha);

        if (escolha == "Nome" || escolha == "nome") {
          cout << "Digite o novo nome do funcionario: ";
          getline(cin, nome);
          funcionario[i]->setNome(nome);

          system("clear");
          cout << "Nome do funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Data" || escolha == "data") {
          cout << "Digite a nova data do funcionario: ";
          cin >> dia;
          data.setDia(dia);
          cin >> mes;
          data.setMes(mes);
          cin >> ano;
          data.setAno(ano);
          cin.ignore();

          funcionario[i]->setDataNasc(data);

          system("clear");
          cout << "Data do funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "CPF" || escolha == "cpf") {
          cout << "Digite o novo CPF do funcionario: ";
          getline(cin, CPF);
          funcionario[i]->setCPF(CPF);

          system("clear");
          cout << "CPF do funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "ID" || escolha == "id") {
          cout << "Digite o novo ID do funcionario: ";
          getline(cin, id);
          funcionario[i]->setID(id);

          system("clear");

          cout << "ID do funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }
        if (escolha == "Cargo" || escolha == "cargo") {
          cout << "Digite o novo cargo do funcionario: ";
          getline(cin, cargo);
          ((Funcionario *)funcionario[i])->setCargo(cargo);

          system("clear");
          cout << "Cargo do funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }

        if (escolha == "Tudo" || escolha == "tudo") {
          cout << "Digite o nome do novo funcionario: ";
          getline(cin, nome);
          funcionario[i]->setNome(nome);

          cout << "Digite a data do novo funcionario: ";
          cin >> dia;
          data.setDia(dia);
          cin >> mes;
          data.setMes(mes);
          cin >> ano;
          data.setAno(ano);
          cin.ignore();
          funcionario[i]->setDataNasc(data);

          cout << "Digite o CPF do novo funcionario: ";
          getline(cin, CPF);
          funcionario[i]->setCPF(CPF);

          cout << "Digite o ID do novo funcionario: ";
          getline(cin, id);
          funcionario[i]->setID(id);

          cout << "Digite o cargo do novo funcionario: ";
          getline(cin, cargo);
          ((Funcionario *)funcionario[i])->setCargo(cargo);

          system("clear");
          cout << "Funcionario alterado com sucesso!" << endl;
          sleep(2);
          system("clear");
        }

        cout << "Quer mudar outro atributo?" << endl;
        getline(cin, escolha);

        if (escolha == "sim") {
          system("clear");
        } else {
          system("clear");
          break;
        }
      } while (escolha == "sim");

    } else {
      cout << "Esse funcionario não foi adicionado nesse bloco!" << endl;
      sleep(2);
      system("clear");
    }
  }
}

void Bloco ::removerFuncionario(string id) {
  for (int i = 0; i < funcionario.size(); i++) {
    if (funcionario[i]->getID() == id) {
      string nome = funcionario[i]->getNome();
      funcionario.erase(funcionario.begin() + i);

      cout << "Funcionario " << nome << " removido!";
      sleep(2);
      system("clear");
    }
  }
}

void Bloco ::confirmarRemocaoF(string id) {
  string opc;

  for (int i = 0; i < funcionario.size(); i++) {
    if (funcionario[i]->getID() == id) {
      cout << "Você tem certeza que deseja remover o funcionario "
           << funcionario[i]->getNome() << "?(sim ou nao)" << endl;

      cin >> opc;
      if (opc == "sim" || opc == "Sim") {
        system("clear");
        removerFuncionario(id);
        break;
      } else {
        system("clear");
        break;
      }
    }
  }
}

bool Bloco ::pExisteB(Pessoa *p) { // Verifica se Existe o prisioneiro no bloco
  bool pExiste = false;

  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->pExisteC(p->getID(), p->getCPF()) || pConfereCpfBloco(p)) {
      pExiste = true;
    }
  }

  if (pExiste) {
    return true;
  } else {
    return false;
  }
}

bool Bloco ::pExisteID(string id) {
  for (int i = 0; i < cela.size(); i++) {
    if (cela[i]->pExiste(id)) {
      return true;
    }
  }

  return false;
}

bool Bloco ::fExiste(string id) {
  bool fExiste = false;

  for (int i = 0; i < funcionario.size(); i++) {
    if (funcionario[i]->getID() == id) {
      fExiste = true;
    }
  }

  if (fExiste) {
    return true;
  } else {
    return false;
  }
}

void Bloco ::salvarPrisioneiro() { // Salva todos os prisioneiros das celas
  ofstream listadeprisioneiros;
  listadeprisioneiros.open("listadeprisioneiros.txt", ios::out | ios::app);
  if (!listadeprisioneiros.is_open()) {
    cout << "Erro ao abrir aquivo para escrita\n";
    sleep(2);
    system("clear");
    return;
  }
  for (int i = 0; i < cela.size(); i++) {
    cela[i]->salvarPrisioneiro(listadeprisioneiros);
  }
  listadeprisioneiros.close();
}

void Bloco ::salvarFuncionario() {
  ofstream listadefuncionarios;
  listadefuncionarios.open("listadefuncionarios.txt", ios::out);
  if (!listadefuncionarios.is_open()) {
    cout << "Erro ao abrir aquivo para escrita\n";
    sleep(2);
    system("clear");
    return;
  }
  for (int i = 0; i < funcionario.size(); i++) {
    Data data = funcionario[i]->getDataNasc();
    listadefuncionarios << funcionario[i]->getNome() << endl;
    listadefuncionarios << funcionario[i]->getID() << endl;
    listadefuncionarios << funcionario[i]->getGenero() << endl;
    listadefuncionarios << funcionario[i]->getCPF() << endl;
    listadefuncionarios << data.getDia() << endl;
    listadefuncionarios << data.getMes() << endl;
    listadefuncionarios << data.getAno() << endl;

    listadefuncionarios << ((Funcionario *)funcionario[i])->getCargo() << endl;
  }
  listadefuncionarios.close();
}
void Bloco :: salvarCela() {
  ofstream listaC("ListaC.txt");
  listaC.open("ListaC.txt", ios::out);
  if(!listaC.is_open()) {
    cout << "Erro ao abrir aquivo para escrita (Salvar Cela)\n";
    sleep(2);
    system("clear");
    return;
  }
  listaC << cela.size() << endl;
  for(int i = 0; i < cela.size(); i++) {
    listaC << cela[i]->getNumero() << endl;
  }
  listaC.close();
}

int Bloco::contaCelas() { return cela.size(); }
int Bloco::contaFuncionarios() { return funcionario.size(); }
int Bloco ::contaP() {
  int pTotal = 0;
  for (int i = 0; i < cela.size(); i++) {
    pTotal += cela[i]->contaPrisioneiros();
  }

  return pTotal;
}
int Bloco ::contaTudo() {
  int totalT = 0;
  totalT = contaCelas() + contaP() + contaFuncionarios();
  return totalT;
}

void Bloco::exibirTodosF() {
  for (int i = 0; i < funcionario.size(); i++) {
    ((Funcionario *)funcionario[i])->exibirFuncionario();
    cout << endl;
  }
}
void Bloco ::exibirTodosP() {
  for (int i = 0; i < cela.size(); i++) {
    cout << "Cela " << cela[i]->getNumero() << ":" << endl;
    cout << endl;
    cela[i]->exibirTodosP();
    cout << endl;
  }
}

void Bloco::lerFuncionario() {
  string nome, cpf, id, genero, cargo, datadenascimento;
  int dia, mes, ano, numC;
  Data data;

  ifstream listadefuncionarios("listadefuncionarios.txt");
  if (!listadefuncionarios.is_open()) {
    cerr << "Erro ao abrir arquivo para leitura(Ler Funcionario)\n";
    return;
  }

  while (getline(listadefuncionarios, nome) &&
      getline(listadefuncionarios, id) &&
      getline(listadefuncionarios, genero) &&
      getline(listadefuncionarios, cpf) && 
      listadefuncionarios >> dia &&
      listadefuncionarios >> mes &&
      listadefuncionarios >> ano &&
      listadefuncionarios.ignore() &&
      getline(listadefuncionarios, cargo)) {    
    data.setDia(dia);
    data.setMes(mes);
    data.setAno(ano);

    Funcionario *nFuncionario = new Funcionario();

    nFuncionario->setNome(nome);
    nFuncionario->setID(id);
    nFuncionario->setGenero(genero);
    nFuncionario->setCPF(cpf);
    nFuncionario->setDataNasc(data);
    nFuncionario->setCargo(cargo);

    funcionario.push_back(((Pessoa*)nFuncionario));
  }

  listadefuncionarios.close();
}
// void Bloco :: lerPrisioneiros(){
//   int dia, mes, ano, pena, numC;
//   string nome, id, genero, cpf, crime, gang;
//   Data d;
//   ifstream listaP("listadeprisioneiros.txt");
//   if(!listaP.is_open()) {
//     cerr << "Erro ao abrir arquivo para leitura(Ler Prisioneiro)\n";
//     sleep(2);
//     system("clear");
//     return;
//   }
//   while(listaP.eof()) {
//     listaP >> numC;
//     listaP.ignore();
//     if(listaP.eof()) {
//       break;
//     }
//     getline(listaP, nome);
//     getline(listaP, id);
//     getline(listaP, genero);
//     getline(listaP, cpf);
//     d.setDia(dia);
//     d.setMes(mes);
//     d.setAno(ano);
//     getline(listaP, gang);
//     getline(listaP, crime);
//     listaP >> pena;

//     Pessoa* p = new Pessoa();

//     cout << numC << endl;
//     cout << nome << endl;
//     cout << id << endl;
//     cout << genero << endl;
//     cout << cpf << endl;
//     cout << d.getData() << endl;
//     cout << gang << endl;
//     cout << crime << endl; 
//     cout << pena << endl;
//   }
//   listaP.close();
// }

void Bloco::lerCela() {
  int numC;

  ifstream listaC("ListaC.txt");
  if (!listaC.is_open()) {
    cerr << "Erro ao abrir arquivo para leitura(LerCela)\n";
    sleep(2);
    system("clear");
    return;
  }

  while (listaC.eof()) {
    listaC >> numC;
    if(listaC.eof()) {
      break;
    }
    Cela *nCela = new Cela();

    nCela->setNumero(numC);

    cela.push_back(nCela);      
  }
  listaC.close();
}
