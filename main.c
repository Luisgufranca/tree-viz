#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"


/**
- numero:
Dada uma string, verifica se é numero.
Retorna 1 (true) ou 0 (false).
**/
int numero(char *n)
{

    if(n == NULL)
        return 0;

    int i = 0;
    int len = strlen(n);

    //caso numero negativo
    if(n[0] == '-')
        i = 1;

    while(i < len)
    {
        //caso nao seja numero
        if(n[i] < 48 || n[i] > 57)
            return 0;
        i++;
    }

    return 1;
}

void imprimeOpcoes()
{
    printf("-- GERADOR DE ARVORE BINARIA DE PESQUISA --\n");
    printf("-insere: Insere um ou mais nodos na arvore\n");
    printf("-remove: Remove um ou mais nodos na arvore\n");
    printf("-imprime: Imprime os nodos em ordem crescente\n");
    printf("-help: Mostra esse guia\n");
}

int main(int argc, char *argv[]) {
    //argc = ARGUMENT COUNTER
    //argv = ARGUMENT VECTOR

    int i = 1; //cursor
    int menu = 0, desenha = 0;

    TNodoA *arvore = NULL;

    while(i < argc) //enquanto ainda tiver coisas para processar
    {
        if(strcmp(argv[i],"-insere") == 0)
        {
            if(i + 1 < argc)
            {
                i++; //incrementa cursor
                desenha = 1;
                //enquanto prox argumento é numero...
                while(i < argc && numero(argv[i]))
                {
                    arvore = insereABP(arvore, atoi(argv[i]));
                    i++; //incrementa cursor
                }

            }
            else { //tratamento do erros
                fprintf(stderr, "Erro: -insere precisa de um argumento\n");
                return 1;
            }
        }else if(strcmp(argv[i],"-remove") == 0)
        {
            if(i + 1 < argc)
            {
                i++; //incrementa cursor

                //enquanto prox argumento é numero...
                while(i < argc && numero(argv[i]))
                {
                    arvore = removeABP(arvore, atoi(argv[i]));
                    i++; //incrementa cursor
                }
            }
            else
            { //tratamento do erros
                fprintf(stderr, "Erro: -remove precisa de um argumento\n");
                return 1;
            }
        }else if(strcmp(argv[i],"-imprime") == 0)
        {
            i++; //incrementa cursor
            printf("Nodos em ordem crescente:\n");
            imprimeABP(arvore);
        }else if(strcmp(argv[i],"-help") == 0)
        {
            i++; //incrementa cursor
            imprimeOpcoes();
            menu = 1;
        }else
        {
            fprintf(stderr, "Opcao desconhecida: %s\nDigite -help para lista de comandos\n", argv[i]);
            i++; //incrementa cursor
        }
    }

    if(!menu && desenha)
    {
        geraDot(arvore);

        //executa direto o comando que vai mostrar a arvore por meio do graphviz
        int status = system("dot -Tpng treeviz.dot -o treeviz.png");

        if (status != 0)
        {
            printf("\n[ERRO] O comando 'dot' falhou (codigo %d).\n", status);
            printf("1. Verifique se o Graphviz esta instalado.\n");
            printf("2. Verifique se o arquivo 'treeviz.dot' foi criado na pasta.\n");
            printf("3. Tente reiniciar o terminal para atualizar o PATH.\n");
            return 1;
        }

        printf("\nImagem da arvore gerada com sucesso: treeviz.png\n");

        //abre a imagem gerada dependendo do sistema operacional
        #ifdef _WIN32
            system("start treeviz.png");
        #elif __APPLE__
            system("open treeviz.png");
        #else
            system("xdg-open treeviz.png");
        #endif
    }

    return 0;
}
