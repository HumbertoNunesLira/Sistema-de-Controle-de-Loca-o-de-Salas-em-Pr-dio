#include <iostream>
#include <vector>
#include <memory>
#include "sala_privada.h"
#include "sala_compartilhada.h"
#include "idade_invalida.h"
#include "empresa.h"

using namespace std;

// Função para exibir o menu
void exibir_menu() {
    cout << "\nMenu de Opcoes:\n";
    cout << "1. Adicionar Sala Privativa\n";
    cout << "2. Adicionar Sala Compartilhada\n";
    cout << "3. Remover Sala\n";
    cout << "4. Adicionar Empresa a uma Sala\n";
    cout << "5. Remover Empresa de uma Sala\n";
    cout << "6. Listar Salas e Empresas\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

// Função principal
int main() {
    vector<shared_ptr<sala>> lista_de_salas;
    int opcao;

    do {
        exibir_menu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int numero, andar, capacidade;
                cout << "Digite o numero da sala: ";
                cin >> numero;
                cout << "Digite o andar da sala: ";
                cin >> andar;
                cout << "Digite a capacidade maxima de pessoas: ";
                cin >> capacidade;
                lista_de_salas.push_back(make_shared<sala_privativa>(numero, andar, capacidade));
                cout << "Sala Privativa adicionada com sucesso!\n";
                break;
            }
            case 2: {
                int numero, andar, estacoes;
                cout << "Digite o numero da sala: ";
                cin >> numero;
                cout << "Digite o andar da sala: ";
                cin >> andar;
                cout << "Digite o numero de estacoes de trabalho disponiveis: ";
                cin >> estacoes;
                lista_de_salas.push_back(make_shared<sala_compartilhada>(numero, andar, estacoes));
                cout << "Sala Compartilhada adicionada com sucesso!\n";
                break;
            }
            case 3: {
                int numero;
                cout << "Digite o numero da sala a ser removida: ";
                cin >> numero;
                auto it = remove_if(lista_de_salas.begin(), lista_de_salas.end(),
                    [numero](const shared_ptr<sala>& s) { return s->get_numero() == numero; });
                if (it != lista_de_salas.end()) {
                    lista_de_salas.erase(it, lista_de_salas.end());
                    cout << "Sala removida com sucesso!\n";
                } else {
                    cout << "Sala nao encontrada!\n";
                }
                break;
            }
            case 4: {
                int numero;
                string nome_empresa;
                int idade_empresa;
                cout << "Digite o numero da sala: ";
                cin >> numero;
                cout << "Digite o nome da empresa: ";
                cin >> nome_empresa;
                cout << "Digite a idade da empresa: ";
                cin >> idade_empresa;
                
                for (auto& s : lista_de_salas) {
                    if (s->get_numero() == numero) {
                        try {
                            empresa nova_empresa(nome_empresa, idade_empresa);
                            *s + nova_empresa;
                            cout << "Empresa adicionada com sucesso!\n";
                        } catch (const idade_invalida& e) {
                            cout << "Erro: " << e.what() << endl;
                        }
                        break;
                    }
                }
                break;
            }
            case 5: {
                int numero;
                string nome_empresa;
                cout << "Digite o numero da sala: ";
                cin >> numero;
                cout << "Digite o nome da empresa a ser removida: ";
                cin >> nome_empresa;
                
                for (auto& s : lista_de_salas) {
                    if (s->get_numero() == numero) {
                        empresa empresa_remover(nome_empresa, 0); // Idade não importa para remoção
                        *s - empresa_remover;
                        cout << "Empresa removida com sucesso!\n";
                        break;
                    }
                }
                break;
            }
            case 6: {
                cout << "Lista de Salas e Empresas:\n";
                sort(lista_de_salas.begin(), lista_de_salas.end(),
                     [](const shared_ptr<sala>& a, const shared_ptr<sala>& b) { return *a < *b; });

                for (const auto& s : lista_de_salas) {
                    cout << "Sala numero: " << s->get_numero()
                         << ", Andar: " << s->get_andar() << endl;
                    const auto& empresas = s->get_empresas();
                    if (empresas.empty()) {
                        cout << "  Nenhuma empresa cadastrada.\n";
                    } else {
                        for (const auto& emp : empresas) {
                            cout << "  Empresa: " << emp.get_nome()
                                 << ", Idade: " << emp.get_idade() << endl;
                        }
                    }
                }
                break;
            }
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}