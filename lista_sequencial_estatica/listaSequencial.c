#include <stdlib.h>

#include "listaSequencial.h"

struct lista {
    int qtd;
    struct lista dados[MAX];
};

Lista* criar_lista() {
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

void liberar_lista(Lista* li) {
    free(li);
}

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1;

    return li->qtd;
}

int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1;

    return (li->qtd == MAX);
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;

    if (lista_cheia(li))
        return 0;

    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;

    if (lista_cheia(li))
        return 0;

    for (int i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];

    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;

    if (lista_cheia(li))
        return 0;

    int k = 0;
    while (k < li->qtd && li->dados[k].matricula != al.matricula)
        k++

    for (int i = li->qtd - 1; i >= k; i--)
        li->dados[i + 1] = li->dados[i];

    li->dados[k] = al;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista *li) {
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista *li) {
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    for (int i = 0; i < li->qtd - 1; i++)
        li->dados[i + 1] = li->dados[i];

    li->qtd--;
    return 1;
}

int remove_lista(Lista *li, int matricula) {
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    for (int i = 0; i < li->qtd - 1; i++)
        if (li->dados[i].matricula >= matricula)
            li->dados[i + 1] = li->dados[i];

    li->qtd--;
    return 1;
}