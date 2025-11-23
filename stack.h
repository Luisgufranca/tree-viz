#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX_STACK 100

#include "abp.h"

typedef struct Pilha
{
    TNodoA *dados[MAX_STACK]; //array de ponteiros (nodos)
    int topo; //indice do elemento no topo
}Pilha;

void inicializaPilha(Pilha *p);
void push(Pilha *p, TNodoA *nodo);
TNodoA* pop(Pilha*p);
int pilhaVazia(Pilha *p);

#endif // STACK_H_INCLUDED
