#include "Pessoa.h"
#include <string>

using namespace std;

Pessoa :: Pessoa() {}

Pessoa::Pessoa(string n, string g, string c, int idad){
  nome = n;
  genero = g;
  cpf = c;
  idade = idad;
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
int Pessoa :: getIdade() {
  return idade;
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
void Pessoa :: setIdade(float i) {
  idade = i;
}

void Pessoa::exibir(){
  cout << "Nome: " << nome << "\n" << "Gênero: " << genero << "\n" << "CPF: " << cpf << "\n" << "Idade: " << idade << " anos" << endl;
}