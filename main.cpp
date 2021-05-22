#include <string>
#include <iostream>
#include <vector>

#include "catalogo.h"

using namespace std;

#define SUCESSO             0
#define ERROR_LER_ARQUIVO   1
#define OPCAO_INVALIDA      2

unsigned menu()
{
    unsigned opcao;
    cout << "Menu" << endl;
    cout << "0 - Salvar e sair" << endl;
    cout << "1 - Adicionar filme ao catalogo" << endl;
    cout << "2 - Remover filme do catalogo" << endl;
    cout << "3 - Exibir catalogo completo" << endl;
    cout << "4 - Buscar por filme no catalogo" << endl;
    cout << "5 - Buscar filme melhor avaliado do catalogo" << endl;
    cout << "6 - Atualizar nota de um filme do catalogo" << endl;
    cout << "7 - Atualizar produtora de um filme do catalogo" << endl;
    cout << "Digite o numero da funcionalidade desejada" << endl;
    cin >> opcao;
    return opcao;
}

int main()
{
    unsigned opcao;
    bool umFilme = true;
    bool continuar = true;
    string nome, produtora, nota, esc;
    vector <Filme> vetorFilmes;

    Catalogo catalogo;

    opcao = menu();
    while (opcao != 0)
    {
        switch (opcao)
        {
            case 1:
                cout << "\nADICIONAR FILME" << endl;
                while (continuar == true)
                {
                    Filme filme ;

                    cout << "Diga o nome do filme, produtora e avaliacao separados por linha:" << endl;
                    cout << "Exemplo:" << endl;
                    cout << "Carros 2" << endl;
                    cout << "Disney" << endl;
                    cout << "7.3" << endl;
                    cin >> filme;
                    cout << "Deseja continuar?" << endl;
                    cout << "Nao - Digite 0" << endl;
                    cout << "Sim - Digite qualquer tecla" << endl;
                    cin >> esc;

                    if (esc == "0")
                    {
                        continuar = false;
                        if (umFilme == true)
                        {
                            catalogo+=filme;
                        }
                    }
                    else
                    {
                        umFilme = false;
                        vetorFilmes.push_back(filme);
                    }
                }

                if (umFilme == false)
                {
                    catalogo += vetorFilmes;
                }

                cout << endl;
                break;
            case 2:
                cout << "\nREMOVER FILME" << endl;
                while (continuar == true)
                {
                    cout << "Diga o nome do filme" << endl;
                    cin >> nome;
                    cout << "Deseja continuar?" << endl;
                    cout << "Nao - Digite 0" << endl;
                    cout << "Sim - Digite qualquer tecla" << endl;
                    cin >> esc;

                    if (esc == "0")
                    {
                        continuar = false;
                        if (umFilme == true)
                        {
                            catalogo -= *catalogo(nome);
                        }
                    }
                    else
                    {
                        umFilme = false;
                        vetorFilmes.push_back(*catalogo(nome));
                    }
                }

                if (umFilme == false)
                {
                    catalogo -= vetorFilmes;
                }
                cout << endl;
                break;
            case 3:
                cout << "\nCATALOGO COMPLETO" << endl;
                cout << endl << catalogo << endl;
                cout << endl;
                break;
            case 4:
                cout << "\nBUSCAR FILME" << endl;
                cout << "Diga o nome do filme:" << endl;
                cin >> nome;
                cout << endl << catalogo(nome) << endl;
                cout << endl;
                break;
            case 5:
                cout << "\nMELHOR AVALIADO" << endl;
                cout << endl << catalogo.melhorAvaliado() << endl;
                cout << endl;
                break;
            case 6:
                cout << "\nATUALIZAR NOTA" << endl;
                cout << "Diga o nome do filme:" << endl;
                cin >> nome;
                cout << "Diga a nova avaliacao do filme" << endl;
                cin >> nota;
                cout << catalogo(nome, stod(nota)) << endl;
                cout << endl;
                break;
            case 7:
                cout << "\nATUALIZAR PRODUTORA" << endl;
                cout << "Diga o nome do filme:" << endl;
                cin >> nome;
                cout << "Diga a nova produtora do filme" << endl;
                cin >> produtora;
                cout << catalogo(nome, produtora) << endl;
                cout << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
                cout << endl;
                exit(OPCAO_INVALIDA);
        }

        opcao = menu();
    }

    catalogo.salvaCatalogo();

    return SUCESSO;
}