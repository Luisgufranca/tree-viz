#ifndef ABP_H_INCLUDED
#define ABP_H_INCLUDED

typedef struct TNodoA
{
    struct TNodoA* esq;
    struct TNodoA* dir;
    int chave;
}TNodoA;

TNodoA* removeABP(TNodoA *a, int chave);
TNodoA* insereABP(TNodoA *a, int chave);
TNodoA* consultaABP(TNodoA *a, int chave);
void imprimeABP(TNodoA *a);

#endif // ABP_H_INCLUDED
