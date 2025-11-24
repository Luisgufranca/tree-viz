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
    int status = system("dot -Tpng arvore.dot -o arvore.png");

    if (status != 0) {
        printf("\n[ERRO] O Graphviz (comando 'dot') nao foi encontrado no sistema.\n");
        printf("Certifique-se de que o Graphviz esta instalado e tente novamente.\n");
        return 1;
    }
    
    printf("\nImagem da arvore gerada com sucesso: arvore.png\n");

    //abre a imagem gerada dependendo do sistema operacional
    #ifdef _WIN32
        system("start arvore.png");
    #elif __APPLE__
        system("open arvore.png");
    #else
        system("xdg-open arvore.png");
    #endif

    return 0;
}
