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
    arvore = removeABP(arvore, 9);
    arvore = removeABP(arvore, 4);

    imprimeABP(arvore);

    geraDot(arvore);

    //executa direto o comando que vai mostrar a arvore por meio do graphviz
    system("dot -Tpng arvore.dot -o arvore.png");

    return 0;
}
