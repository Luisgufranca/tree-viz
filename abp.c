#include <stdlib.h>
#include "abp.h"

/**
- consultaABP:
Dada a raiz de uma árvore e uma chave, retorna o nodo
que possui essa chave. Caso não exista, retorna NULL.
**/
TNodoA* consultaABP(TNodoA *a, int chave)
{
    while(a != NULL)
    {
        if(chave == a->chave)
            return a;
        if(chave < a->chave)
            a = a->esq;
        else
            a = a->dir;
    }

    return NULL;
}

/**
- insereArvore:
Dada a raiz de uma arvore e uma chave, cria um
novo nodo devidamente posicionado. retorna a arvore
atualizada.
**/
TNodoA* insereArvore(TNodoA *a, int chave)
{

    //variavel que vai ser o novo nodo
    TNodoA *novo = (TNodoA*) malloc(sizeof(TNodoA));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->chave = chave;

    //caso a arvore esteja vazia
    if(a == NULL)
        return novo;

    TNodoA *pai = NULL; //variavel para apontar para o pai do novo nodo
    TNodoA *atual = a; //variavel para apontar para onde será inserido o novo nodo

    //iteração que percorre a arvore com atual
    while(atual != NULL)
    {
        pai = atual; //manter o pai um passo antes da descida do atual
        if(atual->chave < chave)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    //conectando o pai no novo nodo
    if(pai->chave < chave)
        pai->dir = novo;
    else
        pai->esq = novo;

    return a;

}

/**
- removeABP:
Recebe endereço da raiz e chave procurada
Se encontrar, remove e devolve nó encontrado
caso contrário devolve null
**/
TNodoA* removeABP(TNodoA *a, int chave)
{
    TNodoA *atual = a; //variavel para apontar para o nodo que será removido
    TNodoA *pai = NULL; //variavel para apontar para o pai do nodo buscado

    //iteração que percorre a arvore com atual
    while(atual != NULL && atual->chave != chave )
    {
        pai = atual; //manter o pai um passo antes da descida do atual
        if(atual->chave < chave)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    //caso o nodo não exista, devolve a árvore
    if(atual == NULL)
        return a;

    //caso 1: nó é folha. Apenas remove o nodo
    if(atual->dir == NULL && atual->esq == NULL)
    {
        if(pai->esq == atual)
            pai->esq = NULL;
        else
            pai->dir = NULL;
        free(atual);
    }//caso 2: nó tem 1 subárvore. Substitui subárvore pelo nó
    else if(atual->dir != NULL && atual->esq == NULL)
    {
        if(pai->esq == atual)
            pai->esq = atual->dir;
        else
            pai->dir = atual->dir;
        free(atual);
    }
    else if(atual->dir == NULL && atual->esq != NULL)
    {
        if(pai->esq == atual)
            pai->esq = atual->esq;
        else
            pai->dir = atual->esq;
        free(atual);
    }//caso 3: nó tem 2 subárvores.
    //Substitui a chave do nó pela chave do maior valor da subarvore esquerda e remove o nodo la embaixo duplicado
    else
    {
        TNodoA *atual2 = atual->esq;
        TNodoA *pai2 = atual;
        while(atual2->dir != NULL)
        {
            pai2 = atual2; //manter o pai2 um passo antes da descida do atual
            atual2 = atual2->dir;
        }
        atual->chave = atual2->chave;

        //é preciso verificar à esquerda pois pode ser o nodo imediatamente à esquerda do buscado
        if(pai2->esq == atual2)
            pai2->esq = atual2->esq;
        else
            pai2->dir = atual2->esq;

        free(atual2);
    }

    return a;
}
