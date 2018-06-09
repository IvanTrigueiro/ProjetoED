#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cstdlib>
#include "estruturadedados.h"
using namespace std;

class binarysearchtree
{
private:
        struct No
        {
           No* esquerdo;
           No* direito;
           int conteudo;
        };
        No* raiz;

    public:
        binarysearchtree()
        {
           raiz = NULL;
        }
        bool vazio() const { return raiz==NULL; }
        void print_inOrdem();
        void inOrdem(No*);
        void print_preOrdem();
        void preOrdem(No*);
        void print_posOrdem();
        void posOrdem(No*);
        void inserir(int);
        bool buscar(int);
        void remover(int);
        int root();
};

#endif // BINARYSEARCHTREE_H
