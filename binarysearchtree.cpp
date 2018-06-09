#include "binarysearchtree.h"

// Menores elementos a esquerda
// Maiores elementos a direita
void binarysearchtree::inserir(int conteudo)
{
    No* t = new No;
    No* pai;
    t->conteudo = conteudo;
    t->esquerdo = NULL;
    t->direito = NULL;
    pai = NULL;

    // Arvore nova?
    if(vazio()) raiz = t;
    else
    {
        //Todas as insercoes sao como folhas
        No* aux;
        aux = raiz;
        // Encontre o No pai
        while(aux)
        {
            pai = aux;
            if(t->conteudo > aux->conteudo) aux = aux->direito;
            else aux = aux->esquerdo;
        }

        if(t->conteudo < pai->conteudo)
           pai->esquerdo = t;
        else
           pai->direito = t;
    }
}

bool binarysearchtree::buscar(int conteudo){
    //Localize o elemento
    bool found = false;
    if(vazio())
    {
        cout<<" Arvore Vazia! "<<endl;
        return false;
    }

    No* aux;
    aux = raiz;

    while(aux != NULL)
    {
         if(aux->conteudo == conteudo)
         {
            found = true;
            cout<< "Encontrado!" <<endl;
            return true;
         }
         else
         {
             if(conteudo>aux->conteudo) aux = aux->direito;
             else aux = aux->esquerdo;
         }
    }
    if(!found)
    {
        cout<<"Conteudo nao encontrado! "<<endl;
        return false;
    }
    return false;
}

int binarysearchtree::root()
{
   return raiz->conteudo;
}

void binarysearchtree::remover(int conteudo)
{
    //Localize o elemento
    bool found = false;
    if(vazio())
    {
        cout<<" Arvore Vazia! "<<endl;
        return;
    }

    No* aux;
    No* pai;
    aux = raiz;

    while(aux != NULL)
    {
         if(aux->conteudo == conteudo)
         {
            found = true;
            break;
         }
         else
         {
             pai = aux;
             if(conteudo>aux->conteudo) aux = aux->direito;
             else aux = aux->esquerdo;
         }
    }
    if(!found)
         {
        cout<<"Conteudo nao encontrado! "<<endl;
        return;
    }


         // 3 casos :
    // 1. Removendo uma folha
    // 2. Removendo No com um unico filho
    // 3. Removendo No com 2 filhos

    // No com filho unico
    if((aux->esquerdo == NULL && aux->direito != NULL)|| (aux->esquerdo != NULL && aux->direito == NULL))
    {
       if(aux->esquerdo == NULL && aux->direito != NULL)
       {
           if(pai->esquerdo == aux)
           {
             pai->esquerdo = aux->direito;
             delete aux;
           }
           else
           {
             pai->direito = aux->direito;
             delete aux;
           }
       }
       else // Filho esquerdo presente, sem filho direito
       {
          if(pai->esquerdo == aux)
           {
             pai->esquerdo = aux->esquerdo;
             delete aux;
           }
           else
           {
             pai->direito = aux->esquerdo;
             delete aux;
           }
       }
     return;
    }

         //Procurando por uma folha
         if( aux->esquerdo == NULL && aux->direito == NULL)
    {
        if(pai->esquerdo == aux) pai->esquerdo = NULL;
        else pai->direito = NULL;
                 delete aux;
                 return;
    }


    //No com 2 filhos
    //Substituir No com menor valor na subarvore da direita
    if (aux->esquerdo != NULL && aux->direito != NULL)
    {
        No* checarDir;
        checarDir = aux->direito;
        if((checarDir->esquerdo == NULL) && (checarDir->direito == NULL))
        {
            aux = checarDir;
            delete checarDir;
            aux->direito = NULL;
        }
        else // Filho da direita tem filhos, nao é folha
        {
            //  Se o filho do No da direita tem um filho a esquerda
            //  Vá até o final da esquerda e localize o menor elemento

            if((aux->direito)->esquerdo != NULL)
            {
                No* esqAux;
                No* esqAuxPai;
                esqAuxPai = aux->direito;
                esqAux = (aux->direito)->esquerdo;
                while(esqAux->esquerdo != NULL)
                {
                   esqAuxPai = esqAux;
                   esqAux = esqAux->esquerdo;
                }
        aux->conteudo = esqAux->conteudo;
                delete esqAux;
                esqAuxPai->esquerdo = NULL;
           }
           else
           {
               No* temp;
               temp = aux->direito;
               aux->conteudo = temp->conteudo;
           aux->direito = temp->direito;
               delete temp;
           }

        }
         return;
    }

}

void binarysearchtree::print_inOrdem()
{
  inOrdem(raiz);
}

void binarysearchtree::inOrdem(No* p)
{
    if(p != NULL)
    {
        if(p->esquerdo) inOrdem(p->esquerdo);
        cout<<" "<<p->conteudo<<" ";
        if(p->direito) inOrdem(p->direito);
    }
    else return;
}

void binarysearchtree::print_preOrdem()
{
    preOrdem(raiz);
}

void binarysearchtree::preOrdem(No* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->conteudo<<" ";
        if(p->esquerdo) preOrdem(p->esquerdo);
        if(p->direito) preOrdem(p->direito);
    }
    else return;
}

void binarysearchtree::print_posOrdem()
{
    posOrdem(raiz);
}

void binarysearchtree::posOrdem(No* p)
{
    if(p != NULL)
    {
        if(p->esquerdo) posOrdem(p->esquerdo);
        if(p->direito) posOrdem(p->direito);
        cout<<" "<<p->conteudo<<" ";
    }
    else return;
}

