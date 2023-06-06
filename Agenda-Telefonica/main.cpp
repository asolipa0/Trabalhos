#include <iostream>
using namespace std;
void adicionar_contato(string agenda[][2], int& total_contatos) {
    string nome, telefone;
     cout << "Digite o nome do contato: ";
    cin >> nome;
     cout << "Digite o telefone do contato: ";
    cin >> telefone;
     agenda[total_contatos][0] = nome;
    agenda[total_contatos][1] = telefone;
     total_contatos++;
     cout << "Contato adicionado com sucesso!" << endl;
}
void excluir_contato(string agenda[][2], int& total_contatos) {
    string nome;
     cout << "Digite o nome do contato que deseja excluir: ";
    cin >> nome;
     for (int i = 0; i < total_contatos; i++) {
        if (agenda[i][0] == nome) {
            // Se encontrou o contato, remove da matriz
            for (int j = i; j < total_contatos - 1; j++) {
                agenda[j][0] = agenda[j+1][0];
                agenda[j][1] = agenda[j+1][1];
            }
             total_contatos--;
             cout << "Contato " << nome << " excluido com sucesso!" << endl;
             return;
        }
    }
     cout << "Contato " << nome << " nao encontrado." << endl;
}
void visualizar_contatos(string agenda[][2], int total_contatos) {
    cout << "Lista de contatos:" << endl;
     for (int i = 0; i < total_contatos; i++) {
        cout << agenda[i][0] << " - " << agenda[i][1] << endl;
    }
}
void buscar_contato(string agenda[][2], int total_contatos) {
    string nome;
     cout << "Digite o nome do contato que deseja buscar: ";
    cin >> nome;
     for (int i = 0; i < total_contatos; i++) {
        if (agenda[i][0] == nome) {
            // Se encontrou o contato, exibe o nome e o telefone
            cout << "Nome: " << agenda[i][0] << endl;
            cout << "Telefone: " << agenda[i][1] << endl;
             return;
        }
    }
     cout << "Contato " << nome << " nao encontrado." << endl;
}
 int main() {
    string agenda[100][2];  // matriz para armazenar nome e telefone dos contatos
    int total_contatos = 0; // contador de contatos adicionados
     cout << "Agenda Telefonica" << endl;
     // Menu principal
    int opcao;
     do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Adicionar contato" << endl;
        cout << "2 - Excluir contato" << endl;
        cout << "3 - Visualizar todos os contatos" << endl;
        cout << "4 - Buscar contato pelo nome" << endl;
        cout << "0 - Sair" << endl;
         cin >> opcao;
         switch (opcao) {
            case 1:
                adicionar_contato(agenda, total_contatos);
                break;
            case 2:
                excluir_contato(agenda, total_contatos);
                break;
            case 3:
                visualizar_contatos(agenda, total_contatos);
                break;
            case 4:
                buscar_contato(agenda, total_contatos);
                break;
            case 0:
                cout << "Ate mais!" << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
     } while (opcao != 0);
     return 0;
}