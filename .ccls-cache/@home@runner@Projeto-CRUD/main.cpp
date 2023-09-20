#include "Pessoa.h"
#include "Prisioneiro.h"
#include "Funcionario.h"
#include "Bloco.h"
#include "Cela.h"
#include "Data.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

void clear(){
    system("clear");
}

void carregamento() {
  int i;
  for (i = 0; i < 3; i++) {
    clear();
    printf("Gerando o Relatório.\n");
    sleep(1);
    clear();
    printf("Gerando o Relatório..\n");
    sleep(1);
    clear();
    printf("Gerando o Relatório...\n");
    sleep(1);
    clear();
  }
}

int main() {
  Pessoa* pessoa;
  Prisioneiro* prisioneiro = new Prisioneiro();
  Funcionario* funcionario = new Funcionario();
  Cela cela;
  Bloco blocoM, blocoF;
  Data data;

  string nome, genero, estado, cpf, crime, id, cargo;
  int opcao, opcaoInserir, dia, mes, ano, pena;
  
  do {
    cout << "Menu:\n";
    cout << "1. Inserir\n";
    cout << "2. Listar todos\n";
    cout << "3. Exibir Um\n";
    cout << "4. Alterar\n";
    cout << "5. Remover\n";
    cout << "6. Exibir Relatório\n";
    cout << "Escolha uma opção: ";
    cin >> opcao;
    clear();

    switch (opcao) {
    case 1: {
      cout << "--ADICIONAR UM TITULO AQUI--" << endl;
      cout << "1 - Prisioneiro" << endl;
      cout << "2 - Funcionario" << endl;
      cout << "Voce deseja inserir um: ";
      cin >> opcaoInserir;
      cin.ignore();

      if (opcaoInserir == 1) {
        clear();
        
        cout << "Insira os dados do Prisioneiro:" << endl;
        cout << "Nome:";
        getline(cin, nome);
        prisioneiro->setNome(nome);
        
        cout << "Gênero:";
        getline(cin, genero);
        prisioneiro->setGenero(genero);
        
        cout << "CPF:";
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
        
        cout << "ID:";
        getline(cin, id);
        prisioneiro->setID(id);
        
        cout << "Crime cometido: ";
        getline(cin, crime);
        prisioneiro->setCrime(crime);

        cout << "Pena: ";
        cin >> pena;
        prisioneiro->setPena(pena);
        clear();
        
        cela.adicionarPrisioneiro(((Pessoa*)prisioneiro));
        sleep(2);
        /*clear();*/

      }else if (opcaoInserir == 2) {
        clear();
        fstream arquivoFuncionario("listadefuncionarios.txt", ios::out | ios::app);
        
        cout << "Insira os dados do Funcionário:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        funcionario->setNome(nome);
        arquivoFuncionario << endl << "Nome do Funcionário: " << funcionario->getNome() << endl;
        
        cout << "Gênero: ";
        getline(cin, genero);
        funcionario->setGenero(genero);
        arquivoFuncionario << "Nome do Funcionário: " << funcionario->getGenero() << endl;
        
        cout << "CPF: ";
        getline(cin, cpf);
        funcionario->setCPF(cpf);
        arquivoFuncionario << "CPF do Funcionário: " << funcionario->getCPF() << endl;
        
        cout << "Data de Nascimento: ";
        cin >> dia;
        data.setDia(dia);
        cin >> mes;
        data.setMes(mes);
        cin >> ano;
        data.setAno(ano);
        funcionario->setDataNasc(data);
        cin.ignore();
        arquivoFuncionario << "Data de Nascimento: " << data.getDia() <<
        "/" << data.getMes() << "/" << data.getAno() << endl;
        
        cout << "ID: ";
        getline(cin, id);
        funcionario->setID(id);
        arquivoFuncionario << "ID: " << funcionario->getID() << endl;

        cout << "Cargo: " ;
        getline(cin, cargo);
        funcionario->setCargo(cargo);
        arquivoFuncionario << "Cargo: " << funcionario->getCargo() << endl;

        blocoM.adicionarFuncionario(funcionario);
        
        clear();
        sleep(2);
        arquivoFuncionario.close();
        clear();

      } else {
        cout << "Essa opção não existe!" << endl;
        sleep(2);
        clear();
      }

      break;
    }
      
    case 2: {
      break;
    }
      
    case 3: {  
      string opc;

      do {
        cout << "1 - Prisioneiro" << endl;
        cout << "2 - Funcionario" << endl;
        cout << "Você deseja exibir um:" << endl;
        cin >> opcaoInserir;
        cin.ignore();
        clear();
  
        if(opcaoInserir == 1) {
          cout << "Digite o ID do prisioneiro que será exibido: " << endl;
          getline(cin, id);
          clear();
          
          cela.getPrisioneiro(id)->exibirPrisioneiro();
          cout << endl;
          cout << "Deseja voltar pro menu? (sim ou nao)" << endl;
          getline(cin, opc);
          
          if(opc == "sim") {
            clear();
            break;
          }else {
            clear();
          }
          
        }else if(opcaoInserir == 2) {
          cout << "Digite o ID do funcionario que será exibido: " << endl;
          getline(cin, id);
          clear();
    
          blocoM.getFuncionario(id).exibirFuncionario();
          cout << endl;
          cout << "Deseja voltar pro menu? (sim ou nao)" << endl;
          getline(cin, opc);
          
          if(opc == "sim") {
            clear();
            break;
          }else {
            clear();
          }
          
        }else {
          clear();
          cout << "Opção Inválida" << endl;
          cout << "Deseja retornar ao menu? (sim ou nao)" << endl;
          break;
        }
      }while(opc == "nao");
      clear();
      break;
    }
    case 4: {
      cout << "1 - Prisioneiro" << endl;
      cout << "2 - Funcionario" << endl;
      cout << "Você deseja alterar um:" << endl;
      cin >> opcaoInserir;
      clear();
      break;
      
    
    }
    case 5: {
      carregamento();
      break;
    }
    default:
      cout << "Opção inválida. Tente novamente.\n";
      break;
    }
    
  } while (opcao != 5);


  return 0;
}
    