#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/**
Implementações de pilha, usados aqui para
imprimir ABP
**/

void inicializaPilha(Pilha *p)
{
    p->topo = -1;
}

void push(Pilha *p, TNodoA *nodo)
{
    //verifica se nao estorou
    if(p->topo < MAX_STACK-1)
    {
        p->topo++;
        p->dados[p->topo] = nodo;
    }
}

TNodoA* pop(Pilha *p)
{
    if(p->topo >= 0)
    {
        TNodoA *val = p->dados[p->topo];
        p->topo--;
        return val;
    }

    printf("Erro: Pilha vazia!");
    return NULL;
}

int pilhaVazia(Pilha *p)
{
    if(p->topo == -1)
        return 1;
    else
        return 0;
}
