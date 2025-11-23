#include <stdio.h>
#include <stdlib.h>
#include "abp.h"



int main()
{
    TNodoA* arvore = NULL;

    arvore = insereABP(arvore, 4);
    arvore = insereABP(arvore, 8);
    arvore = insereABP(arvore, 9);
    arvore = insereABP(arvore, 7);
    arvore = insereABP(arvore, 2);
    arvore = insereABP(arvore, 1);

    imprimeABP(arvore);

    return 0;
}
