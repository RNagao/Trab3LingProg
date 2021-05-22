#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <vector>

#include "filme.h"

using namespace std;

class Catalogo
{
    //operador global
    friend ostream &operator<<(ostream&, const Catalogo &);

    public:
        //construtor
        Catalogo();
        //operador de insercao ordenada
        void operator+=(Filme &);
        //operador de insercao de um vetor de filmes
        void operator+=(vector <Filme> &);
        //operador de remocao de filme
        void operator-=(Filme&);
        //operador de remocao de um vetor de filmes
        void operator-=(vector <Filme> &);
        //operador busca filme
        Filme* operator()(string);
        //operador de atualizacao da produtora
        Filme* operator()(string, string);
        //operador de atualizacao da nota
        Filme* operator()(string, double);
        //busca por filme mais votado
        Filme* melhorAvaliado();
        //escreve o catalogo num arquivo texto
        void salvaCatalogo();

    private:
        //vetor de filmes no catalogo
        vector <Filme> vetorFilmes;
        //maximo tamanho vetoresEmLote
        unsigned maximoFilmes = 30;
        //ordena os filmes em ordem alfabetica
        void ordenaFilmesNome();
};

#endif