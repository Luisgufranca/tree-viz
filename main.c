#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"



int main(int argc, char *argv[]) {
    //argc = ARGUMENT COUNTER
    //argv = ARGUMENT VECTOR

    /**
    COMANDOS:
    -insere
    -remove

    por enquanto, vou implementar que cada comando admite um argumento apenas.
    provavelmente implementa-se com loop while a maneira com argumentos ilimitados

    tambem precisa ser implementado o sistema em que a arvore fica salva na nuvem
    e aí da pra ir modificando e vendo em tempo real as mudanças.
    **/

    int val_insere = 0;
    int val_remove = 0;
    int i = 1; //cursor

    TNodoA *arvore = NULL;

    while(i < argc) //enquanto ainda tiver coisas para processar
    {
        if(strcmp(argv[i],"-insere") == 0)
        {
            if(i + 1 < argc)
            {
                val_insere = atoi(argv[i + 1]);
                arvore = insereABP(arvore, val_insere);
                i += 2; //dois argumentos admitidos aqui
            }
            else { //tratamento do erros
                fprintf(stderr, "Erro: -insere precisa de um argumento\n");
                return 1;
            }
        }else if(strcmp(argv[i],"-remove") == 0)
        {
            if(i + 1 < argc)
            {
                val_remove = atoi(argv[i + 1]);
                arvore = removeABP(arvore, val_remove);
                i += 2; //dois argumentos admitidos aqui
            }
            else { //tratamento do erros
                fprintf(stderr, "Erro: -remove precisa de um argumento\n");
                return 1;
            }
        }else {
            fprintf(stderr, "Opcao desconhecida: %s\n", argv[i]);
            i++;
            break;
        }
    }

    geraDot(arvore);



    //executa direto o comando que vai mostrar a arvore por meio do graphviz
    int status = system("dot -Tpng arvore.dot -o arvore.png");

    if (status != 0)
    {
        printf("\n[ERRO] O comando 'dot' falhou (codigo %d).\n", status);
        printf("1. Verifique se o Graphviz esta instalado.\n");
        printf("2. Verifique se o arquivo 'arvore.dot' foi criado na pasta.\n");
        printf("3. Tente reiniciar o terminal para atualizar o PATH.\n");
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
