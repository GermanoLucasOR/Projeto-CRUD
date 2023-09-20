#include <iostream>
#include <string>
#pragma once

class Data {
public:
    Data();
    Data(int d, int m, int a);
    std::string getDia();
    std::string getMes();
    std::string getAno();
    void setDia(int d);
    void setMes(int m);
    void setAno(int a);
    void exibirData();

private:
    int dia;
    int mes;
    int ano;
};
