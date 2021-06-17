#include <iomanip>
#include <fstream>
#include <iostream>

#include "catalogo.h"

using namespace std;

Catalogo::Catalogo()
{
    string linha;
    unsigned indice;
    vector <string> dados;

    ifstream file("salvo.txt");

    while (getline(file, linha))
    {
        string palavra = "";

        for (indice = 0; indice < linha.length(); indice++)
        {
            if (linha[indice] == '/')
            {
                dados.push_back(palavra);
                palavra = "";
            }
            else
            {
                palavra += linha[indice];
            }
        }
        dados.push_back(palavra);
        cout << dados.size() << endl;
        cout << dados[0] << endl;
        cout << dados[1] << endl;
        cout << dados[2] << endl;
        Filme filme(dados[0], dados[1], stod(dados[2]));
        vetorFilmes.push_back(filme);
        dados.clear();
    }
}

ostream &operator<<(ostream & output, const Catalogo & catalogo)
{
    unsigned indice;

    for (indice = 0; indice < catalogo.vetorFilmes.size(); indice++)
    {
        output << catalogo.vetorFilmes[indice] << endl;
    }

    return output;
}

void Catalogo::operator+=(Filme& filmeAdicionado)
{
    unsigned indice = 0;

    if (vetorFilmes.size() >= maximoFilmes)
    {
        cout << "Limite de filmes atingido" << endl;
        return ;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNome() == filmeAdicionado.getNome())
        {
            cout << "O filme ja foi registrado" << endl;
            return ;
        }
    }
    
    vetorFilmes.push_back(filmeAdicionado);
    ordenaFilmesNome();

}

void Catalogo::operator+=(vector <Filme>& vetorLote)
{
    unsigned indice, indiceAux;
    vector<Filme>::iterator it;
    bool filmeExiste = false;

    for (indice = 0; indice < vetorLote.size(); indice++)
    {
        if (vetorFilmes.size() >= maximoFilmes)
        {
            cout << "Limite de filmes atingido" << endl;
            return ;
        }

        for (indiceAux = 0; indiceAux < vetorFilmes.size(); indiceAux++)
        {
            if (vetorFilmes[indiceAux].getNome() == vetorLote[indice].getNome())
            {
                cout << "O filme ja foi registrado" << endl;
                filmeExiste = true;
            }
        }

        if (filmeExiste == false)
        {
            cout << indice << endl;
            it = vetorFilmes.end();
            vetorFilmes.insert(it, vetorLote[indice]);
        }
    }

    ordenaFilmesNome();
}

void Catalogo::operator-=(Filme& filmeRemovido)
{
    unsigned indice;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNome() == filmeRemovido.getNome())
        {
            vetorFilmes.erase(vetorFilmes.begin() + indice);
            return ;
        }
    }
}

void Catalogo::operator-=(vector <Filme>& vetorLote)
{
    unsigned indice, indiceAux;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return;
    }

    for (indice = 0; indice < vetorLote.size(); indice++)
    {
        for (indiceAux = 0; indiceAux < vetorFilmes.size(); indice++)
        {
            if (vetorLote[indice].getNome() == vetorFilmes[indiceAux].getNome())
            {
                vetorFilmes.erase(vetorFilmes.begin() + indice);
            }
        }
    }
}

Filme* Catalogo::melhorAvaliado()
{
    double maiorNota = 0;
    unsigned melhorAvaliado, indice;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return NULL;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNota() > maiorNota)
        {
            maiorNota = vetorFilmes[indice].getNota();
            melhorAvaliado = indice;
        }
    }

    return &vetorFilmes[melhorAvaliado];
}

void Catalogo::salvaCatalogo()
{
    unsigned indice;

    ofstream arquivo("salvo.txt");

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        arquivo << vetorFilmes[indice].getNome() << '/'
            << vetorFilmes[indice].getProdutora() << '/'
            << vetorFilmes[indice].getNota() << endl;
    }

    arquivo.close();
}

Filme* Catalogo::operator()(string nome)
{
    unsigned indice;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return NULL;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNome() == nome)
        {
            return &vetorFilmes[indice];
        }
    }

    cout << "Filme nao existe no catalogo" << endl;
    return NULL;
}

Filme* Catalogo::operator()(string nome, string produtoraAtualizada)
{
    unsigned indice;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return NULL;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNome() == nome)
        {
            vetorFilmes[indice].setProdutora(produtoraAtualizada);
            return &vetorFilmes[indice];
        }
    }

    cout << "Filme nao existe no catalogo" << endl;
    return NULL;
}

Filme* Catalogo::operator()(string nome, double notaAtualizada)
{
    unsigned indice;

    if (vetorFilmes.size() == 0)
    {
        cout << "Catalogo vazio" << endl;
        return NULL;
    }

    for (indice = 0; indice < vetorFilmes.size(); indice++)
    {
        if (vetorFilmes[indice].getNome() == nome)
        {
            vetorFilmes[indice].setNota(notaAtualizada);
            return &vetorFilmes[indice];
        }
    }

    cout << "Filme nao existe no catalogo" << endl;
    return NULL;
}

void Catalogo::ordenaFilmesNome()
{
    unsigned indice, indiceAux;
    Filme aux;

    for (indice = 0; indice < (vetorFilmes.size() - 1); indice++)
    {
        for (indiceAux = (indice + 1); indiceAux < vetorFilmes.size(); indiceAux++)
        {
            if (vetorFilmes[indice].getNome() < vetorFilmes[indiceAux].getNome())
            {
                aux = vetorFilmes[indice];
                vetorFilmes[indice] = vetorFilmes[indiceAux];
                vetorFilmes[indiceAux] = aux;
            }
        }
    }
}

