#include <iostream>
#include <string>
#pragma once

using namespace std;

class Prisao {
  public:
    void inserir();
    void listarTodos();
    void exibir(int id);
    void alterar(int id);
    void remover(int id);
    void exibirRelatorio();
    void sair();
};