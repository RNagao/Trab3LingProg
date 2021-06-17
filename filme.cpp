#include <string>
#include <iomanip>
#include <cctype>
#include <iostream>

#include "filme.h"

using namespace std;

ostream &operator<<(ostream & output, const Filme & filme)
{
    output << "Filme: " << filme.nome << endl
            << "Produtora: " <<  filme.produtora << endl
            << "Nota: " << filme.nota << endl;
    return output;
}

istream &operator>>(istream & input, Filme & filme)
{
    string nomeFilme, produtoraFilme, notaFilme;
    getline(input, nomeFilme);
    getline(input, produtoraFilme);
    getline(input, notaFilme);
    filme = Filme(nomeFilme, produtoraFilme, stod(notaFilme));
    return input;
}

Filme::Filme(string nomeFilme, string produtoraFilme, double notaFilme):
    nome(nomeFilme),
    produtora(produtoraFilme),
    nota(notaFilme){};


string Filme::getNome()
{
    return nome;
}

string Filme::getProdutora()
{
    return produtora;
}

void Filme::setProdutora(string produtoraAtualizada)
{
    produtora = produtoraAtualizada;
}

double Filme::getNota()
{
    return nota;
}

void Filme::setNota(double notaAtualizada)
{
    nota = notaAtualizada;
}

string Filme::toLowerString(string dado)
{
    string dadoLower;
    unsigned indice;

    for (indice = 0; indice < dadoLower.length(); indice++)
    {
        dadoLower += tolower(dado[indice]);
    }
    cout << dadoLower << endl;
    return dadoLower;
}

bool Filme::operator<(Filme & filmeComparado)
{
    if (toLowerString(this->getNome()) < toLowerString(filmeComparado.getNome()))
    {
        return true;
    }

    return false;
}

bool Filme::operator>(Filme & filmeComparado)
{
    if (toLowerString(this->getNome()) > toLowerString(filmeComparado.getNome()))
    {
        return true;
    }

    return false;
}

bool Filme::operator==(Filme & filmeComparado)
{
    if (toLowerString(this->nome) == toLowerString(filmeComparado.nome))
    {
        return true;
    }

    return false;
}