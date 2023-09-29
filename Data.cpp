#include "Data.h"
#include <string>
#include <iostream>

using namespace std;

Data::Data(){}

Data::Data(int d, int m, int a) {
    dia = d;
    mes = m;
    ano = a;
}

string Data::getDia() {
    if (dia < 10) {
        return "0" + to_string(dia);
    } else {
        return to_string(dia);
    }
}

string Data::getMes() {
    if (mes < 10) {
        return "0" + to_string(mes);
    } else {
        return to_string(mes);
    }
}

string Data::getAno() {
    if (ano < 10) {
        return "0" + to_string(ano);
    } else {
        return to_string(ano);
    }
}

void Data::setDia(int d) {
    dia = d;
}

void Data :: setMes(int m) {
    mes = m;
}

void Data :: setAno(int a) {
    ano = a;
}

void Data :: exibirData() {
  cout << "Data de Nascimento: " << dia << "/" << mes << "/" << ano << endl;
}
string Data :: getData() {
  string data;
  data = getDia() + "/" + getMes() + "/" + getAno();
  return data;
}
void Data :: setData(string d) {
  data = d;
}
