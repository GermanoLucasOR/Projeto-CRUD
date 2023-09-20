#include "Pessoa.h"
#include "Prisioneiro.h"
#include "Funcionario.h"
#include "Bloco.h"
#include "Cela.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h> //Biblioteca da função sleep()
#include <vector>
using namespace std;

// funções
void clear() { system("clear"); }

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
  Pessoa pessoa;
  Prisioneiro prisioneiro;
  Funcionario funcionario;
  Cela cela;
  Bloco bloco;

  string nome, genero, estado, cpf, crime, id;
  int opcao, opcaoInserir, idade;
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
        cout << "Nome: ";
        getline(cin, nome);
        prisioneiro.setNome(nome);

        cout << "Gênero: ";
        getline(cin, genero);
        prisioneiro.setGenero(genero);
        
        cout << "CPF: ";
        getline(cin, cpf);
        prisioneiro.setCPF(cpf);

        cout << "Idade: ";
        cin >> idade;
        cin.ignore();
        prisioneiro.setIdade(idade);

        cout << "ID: ";
        getline(cin, id);
        prisioneiro.setID(id);

        cout << "Crime cometido: ";
        getline(cin, crime);
        prisioneiro.setCrime(crime);

        clear();

        cout << "Prisioneiro adicionado!" << endl;
        sleep(2);
        clear();

      } else if (opcaoInserir == 2) {
        clear();
        cout << "Insira os dados do Funcionário:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        funcionario.setNome(nome);

        cout << "Idade: ";
        cin >> idade;
        cin.ignore();
        funcionario.setIdade(idade);
        
        cout << "Gênero: ";
        getline(cin, genero);
        funcionario.setGenero(genero);
        
        cout << "CPF: ";
        getline(cin, cpf);
        funcionario.setCPF(cpf);
        
        cout << "ID: ";
        getline(cin, id);
        funcionario.setID(id);
        
        cout << "Crime cometido: ";
        getline(cin, crime);
        funcionario.setCrime(crime);
        
        clear();
        cout << "Funcionario adicionado!" << endl;
        sleep(2);
        clear();

      } else {
        cout << "Essa opção não existe!" << endl;
      }

      break;
    }
    case 2: {
      break;
    }
    case 3: {  
      string opc;

      cout << "1 - Prisioneiro" << endl;
      cout << "2 - Funcionario" << endl;
      cout << "Você deseja exibir um:" << endl;
      cin >> opcaoInserir;
      break;
      
      cout << "Digite o ID do prisioneiro que será exibido: " << endl;
      getline(cin, id);

      prisioneiro.exibir();
      cout << endl;
      cout << "Deseja voltar pro menu?" << endl;
      getline(cin, opc);
      if(opc == "sim") {
        break;
      }else {
        clear();
        prisioneiro.exibir();
      }
      
    }
    case 4: {
      cout << "1 - Prisioneiro" << endl;
      cout << "2 - Funcionario" << endl;
      cout << "Você deseja alterar um:" << endl;
      cin >> opcaoInserir;
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
