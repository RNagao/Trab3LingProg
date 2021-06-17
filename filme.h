#ifndef FILME_H
#define FILME_H

#include <iomanip>
#include <string>

using namespace std;

struct Filme
{
    //operadores globais
    friend ostream &operator<<(ostream&, const Filme&);
    friend istream &operator>>(istream&, Filme&);

    public:
        //construtor
        Filme(string nome = "", string produtora = "", double nota = 0.0);
        //recebe o nome
        string getNome();
        //recebe a produtora
        string getProdutora();
        //edita o nome da produtora
        void setProdutora(string);
        //recebe a nota do filme
        double getNota();
        //edita a nota do filme
        void setNota(double);
        //operadores
        bool operator<(Filme&);
        bool operator>(Filme&);
        bool operator==(Filme&);

    private:
        string nome;
        string produtora;
        double nota;
};

#endif