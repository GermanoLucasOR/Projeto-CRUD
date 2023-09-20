#include "Pessoa.h"
#include <string>
#include "Data.h"

using namespace std;

Pessoa :: Pessoa() {}

Pessoa::Pessoa(string n, string g, string c, Data d){
  nome = n;
  genero = g;
  cpf = c;
}

string Pessoa :: getNome() {
  return nome;
}
string Pessoa :: getGenero() {
  return genero;
}
string Pessoa :: getCPF() {
  return cpf;
}

string Pessoa::getID(){
  return id;
}

Data Pessoa :: getDataNasc() {
  return dataNascimento;
}

void Pessoa :: setNome(string n) {
  nome = n;
}
void Pessoa :: setGenero(string g) {
  genero = g;
}
void Pessoa :: setCPF(string c) {
  cpf = c;
}

void Pessoa::setID(string ID) {
  id = ID;
}

void Pessoa :: setDataNasc(Data d) {
  dataNascimento = d;
}

void Pessoa::exibir(){
  cout << "Nome: " << nome << "\n" << "Gênero: " << genero << "\n" << "CPF: " << cpf 
  << "\n" << "ID: " << id << endl;
  dataNascimento.exibirData();
}