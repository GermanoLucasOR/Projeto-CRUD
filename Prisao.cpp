#include "Prisao.h"
#include "Bloco.h"
#include "Cela.h"
#include "Data.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include "Prisioneiro.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

fstream arquivoPrisioneiro("listadeprisioneiros.txt", ios::in | ios::out | ios::app);
fstream arquivoFuncionario("listadefuncionarios.txt", ios::in | ios::out | ios::app);
fstream arquivoCela("ListaC.txt", ios::in | ios::out | ios::app);

Pessoa *pessoa;
Prisioneiro *prisioneiro = new Prisioneiro();
Funcionario *funcionario = new Funcionario();
Cela *cela;
Bloco bloco;
Data data;
string nome, genero, estado, cpf, crime, id, cargo, opc, gangue;
int opcao, opcaoInserir, dia, mes, ano, pena, numero;

void carregamento() {
  int i;
  for (i = 0; i < 1; i++) {
    system("clear");
    printf("Gerando o Relatório.\n");
    sleep(1);
    system("clear");
    printf("Gerando o Relatório..\n");
    sleep(1);
    system("clear");
    printf("Gerando o Relatório...\n");
    sleep(1);
    system("clear");
  }
}

void Sair() {
  for (int i = 0; i < 1; i++) {
    system("clear");
    printf("Sistema sendo encerrado.\n");
    sleep(1);
    system("clear");
    printf("Sistema sendo encerrado..\n");
    sleep(1);
    system("clear");
    printf("Sistema sendo encerrado...\n");
    sleep(1);
    system("clear");
  }
}

void ProcurandoF() {
  for (int i = 0; i < 1; i++) {
    system("clear");
    printf("Procurando funcionário.\n");
    sleep(1);
    system("clear");
    printf("Procurando funcionário..\n");
    sleep(1);
    system("clear");
    printf("Procurando funcionário...\n");
    sleep(1);
    system("clear");
  }
}

void ProcurandoP() {
  for (int i = 0; i < 1; i++) {
    system("clear");
    printf("Procurando prisioneiro.\n");
    sleep(1);
    system("clear");
    printf("Procurando prisioneiro..\n");
    sleep(1);
    system("clear");
    printf("Procurando prisioneiro...\n");
    sleep(1);
    system("clear");
  }
}

void Titulo() {
  cout << "SISTEMA CRUD - PRISÃO" << endl;
  sleep(5);
  system("clear");
}

Prisao ::Prisao() {}

void Prisao::menu() {
  Titulo();
  do {
    cout << "Menu:" << endl;
    cout << "1. Inserir\n";
    cout << "2. Listar todos\n";
    cout << "3. Exibir Um\n";
    cout << "4. Alterar\n";
    cout << "5. Remover\n";
    cout << "6. Exibir Relatório\n";
    cout << "7. Salvar e Sair\n";
    cout << "Escolha uma opção: ";
    cin >> opcao;
    system("clear");

    switch (opcao) {
    case 1: {
      inserir();
      break;
    }
    case 2: {
      listarTodos();
      break;
    }
    case 3: {
      exibir();
      break;
    }
    case 4: {
      alterar();
      break;
    }
    case 5: {
      remover();
      break;
    }
    case 6: {
      exibirRelatorio();
      break;
    }
    case 7: {
      sair();
      return;
    }
    default:
      cout << "Opção inválida. Tente novamente.\n";
      break;
    }
  } while (1);
}

void Prisao::inserir() {
  cout << "1 - Prisioneiro" << endl;
  cout << "2 - Funcionario" << endl;
  cout << "Você deseja inserir um: ";
  cin >> opcaoInserir;
  cin.ignore();

  if (opcaoInserir == 1) {
    prisioneiro = new Prisioneiro();
    cela = new Cela();

    system("clear");
    cout << "Qual o numero da cela que o prisioneiro será adicionado? ";
    cin >> numero;
    cin.ignore();
    cela->setNumero(numero);
    prisioneiro->setNumC(numero);

    system("clear");
    bloco.adicionarCela(cela);

    sleep(2);
    system("clear");

    cout << "Insira os dados do Prisioneiro:" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    prisioneiro->setNome(nome);

    cout << "ID: ";
    getline(cin, id);
    prisioneiro->setID(id);

    cout << "Gênero: ";
    getline(cin, genero);
    prisioneiro->setGenero(genero);

    cout << "CPF: ";
    getline(cin, cpf);
    prisioneiro->setCPF(cpf);

    cout << "Data de Nascimento: ";
    cin >> dia;
    data.setDia(dia);
    cin >> mes;
    data.setMes(mes);
    cin >> ano;
    data.setAno(ano);
    prisioneiro->setDataNasc(data);
    cin.ignore();

    cout << "Qual a gangue do prisioneiro: ";
    getline(cin, gangue);
    prisioneiro->setGangue(gangue);

    cout << "Crime cometido: ";
    getline(cin, crime);
    prisioneiro->setCrime(crime);

    cout << "Pena: ";
    cin >> pena;
    prisioneiro->setPena(pena);

    system("clear");
    if (bloco.pExisteB((Pessoa *)prisioneiro)) {
      cout << "O prisioneiro ja existe no bloco! " << endl;

      sleep(2);
      system("clear");
    } else {
      bloco.getCelaN(numero)->adicionarPrisioneiro(((Pessoa *)prisioneiro));

      sleep(2);
      system("clear");
    }
  } else if (opcaoInserir == 2) {
    funcionario = new Funcionario();
    system("clear");

    cout << "Insira os dados do Funcionário:" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    funcionario->setNome(nome);

    cout << "ID: ";
    getline(cin, id);
    funcionario->setID(id);

    cout << "Gênero: ";
    getline(cin, genero);
    funcionario->setGenero(genero);

    cout << "CPF: ";
    getline(cin, cpf);
    funcionario->setCPF(cpf);

    cout << "Data de Nascimento: ";
    cin >> dia;
    data.setDia(dia);
    cin >> mes;
    data.setMes(mes);
    cin >> ano;
    data.setAno(ano);
    funcionario->setDataNasc(data);
    cin.ignore();

    cout << "Cargo: ";
    getline(cin, cargo);
    funcionario->setCargo(cargo);

    system("clear");
    bloco.fConfereCPF(((Pessoa *)funcionario));

    sleep(2);
    system("clear");
  }
}

void Prisao::listarTodos() {
  do {
    cout << "1 - Todos os Prisioneiros" << endl;
    cout << "2 - Todos os Funcionarios" << endl;
    cout << "3 - Listar Tudo" << endl;
    cout << "Você deseja listar:" << endl;
    cin >> opcaoInserir;
    cin.ignore();
    system("clear");

    if (opcaoInserir == 1) {
      cout << "Lista de Prisioneiros:" << endl;
      bloco.exibirTodosP();
    } else if (opcaoInserir == 2) {
      cout << "Lista de Funcionários: " << endl;
      bloco.exibirTodosF();
    } else if (opcaoInserir == 3) {
      cout << "Lista de Todos: " << endl;
      cout << endl;
      cout << "Prisioneiro: " << endl;
      bloco.exibirTodosP();

      cout << endl;
      cout << "Funcionarios: " << endl;
      bloco.exibirTodosF();
    } else {
      system("clear");
      cout << "Opção Inválida. Por favor digite 1, 2 ou 3." << endl;
    }

    cout << endl;
    cout << "Deseja voltar pro menu? (sim ou nao)" << endl;
    getline(cin, opc);

    if (opc == "sim") {
      system("clear");
      break;
    } else {
      system("clear");
    }
  } while (opc == "nao");
}

void Prisao::exibir() {
  do {
    cout << "1 - Prisioneiro" << endl;
    cout << "2 - Funcionario" << endl;
    cout << "Você deseja exibir um:" << endl;
    cin >> opcaoInserir;
    cin.ignore();
    system("clear");

    if (opcaoInserir == 1) {
      cout << "Digite o ID do prisioneiro que será exibido: ";
      getline(cin, id);
      system("clear");
      ProcurandoP();

      if (bloco.pExisteID(id)) {
        bloco.getCela(id)->getPrisioneiro(id)->exibirPrisioneiro();
      } else {
        cout << "Esse prisioneiro não existe!" << endl;
      }

    } else if (opcaoInserir == 2) {
      cout << "Digite o ID do funcionario que será exibido: " << endl;
      getline(cin, id);
      system("clear");
      ProcurandoF();

      if (bloco.fExiste(id)) {
        bloco.getFuncionario(id)->exibirFuncionario();
      } else {
        cout << "Esse Funcionario não existe!" << endl;
      }

    } else {
      system("clear");
      cout << "Opção Inválida" << endl;
    }
    cout << endl;
    cout << "Deseja voltar pro menu? (sim ou nao)" << endl;
    getline(cin, opc);

    if (opc == "sim") {
      system("clear");
      break;
    } else {
      system("clear");
    }
  } while (opc == "nao");
  system("clear");
}

void Prisao::alterar() {
  do {
    cout << "1 - Prisioneiro" << endl;
    cout << "2 - Funcionario" << endl;
    cout << "Você deseja alterar um:" << endl;
    cin >> opcaoInserir;
    cin.ignore();
    system("clear");

    if (opcaoInserir == 1) {
      cout << "Digite o ID do prisioneiro a ser alterado: ";
      getline(cin, id);
      system("clear");

      if (bloco.pExisteID(id)) {
        bloco.getCela(id)->alterarPrisioneiro(id);
      } else {
        cout << "Esse prisioneiro não existe! " << endl;
      }

    } else if (opcaoInserir == 2) {
      cout << "Digite o id do funcionario a ser alterado: ";
      getline(cin, id);
      system("clear");

      if (bloco.fExiste(id)) {
        bloco.alterarFuncionario(id);
      } else {
        cout << "Funcionário não existe! " << endl;
      }

    } else {
      cout << "Opção inválida. Por favor, escolha 1 ou 2!" << endl;
    }

    cout << endl;
    cout << "Quer voltar para o menu? (sim ou nao)" << endl;
    getline(cin, opc);

    if (opc == "sim") {
      system("clear");
      break;
    } else {
      system("clear");
    }
  } while (opc == "nao");
  system("clear");
}

void Prisao::remover() {
  do {
    cout << "1 - Prisioneiro" << endl;
    cout << "2 - Funcionario" << endl;
    cout << "Você deseja remover um:" << endl;
    cin >> opcaoInserir;
    cin.ignore();
    system("clear");

    if (opcaoInserir == 1) {
      cout << "Insira o ID do prisioneiro que você deseja remover: ";
      getline(cin, id);
      system("clear");

      if (bloco.pExisteID(id)) {
        bloco.getCela(id)->confirmarRemocaoP(id);
      } else {
        cout << "Esse prisioneiro não existe no Bloco";
        sleep(2);
        system("clear");
      }

    } else if (opcaoInserir == 2) {
      cout << "Insira o ID do funcionario que você deseja remover: ";
      getline(cin, id);
      system("clear");

      if (bloco.fExiste(id)) {
        bloco.confirmarRemocaoF(id);
      } else {
        cout << "Esse funcionario não existe!" << endl;
        sleep(2);
        system("clear");
      }

    } else {
      cout << "Opção inválida. Por favor, escolha 1 ou 2!" << endl;
    }

    cout << "Deseja voltar para o menu? (sim ou nao)";
    cin >> opc;
    if (opc == "sim") {
      system("clear");
      break;
    } else {
      system("clear");
    }
  } while (opc == "nao");
  system("clear");
}

void Prisao::exibirRelatorio() {
  carregamento();
  cout << "RELATÓRIO DA PRISÃO:" << endl;
  cout << "=======================" << endl;
  cout << "Número total de Prisioneiros: " << bloco.contaP() << endl;
  cout << "Número total de Funcionários: " << bloco.contaFuncionarios() << endl;
  cout << "Número total de Celas: " << bloco.contaCelas() << endl;
  cout << "\n" << endl;
  sleep(5);
  system("clear");
}

void Prisao::sair() {
  bloco.salvarFuncionario();
  bloco.salvarCela();
  bloco.salvarPrisioneiro();
  Sair();
}
