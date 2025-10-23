#include "fila.h"

typedef struct fila {
    int qtd, inicio, fim;
    ALUNO dados[MAX];
} FILA;

FILA* cria_fila() {
    FILA* f;
    f = (FILA*) malloc(sizeof(FILA));
    if (f != NULL) {
        f->qtd = 0;
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}

void libera_fila(FILA *f) {
    free(f);
}

int tamanho_fila(FILA* f) {
    return f->qtd;
}

int fila_vazia(FILA* f) {
    return f->qtd == 0;
}

int fila_cheia(FILA* f) {
    return MAX == f->qtd;
}

int insere_fila(FILA *f, ALUNO al) {
    if (f->dados == NULL)
        aborta_programa();

    if (fila_cheia(f))
        return 0;

    f->dados[f->fim] = al;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
    return 1;
}

int remove_fila(FILA *f) {
    int matricula;
    if (f->dados == NULL)
        aborta_programa();

    if (fila_vazia(f))
        return 0;

    matricula = f->dados[f->inicio].matricula;
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return matricula;
}

int consulta_fila(FILA *f, ALUNO *al) {
    if (f->dados == NULL)
        aborta_programa();

    if (fila_vazia(f))
        return 0;

    *al = f->dados[f->inicio];
    return 1;
}

void printa_aluno(ALUNO* al) {
    printf("matricula: %d\n", al->matricula);
    printf("nota 1: %.2f\n", al->n1);
    printf("nota 2: %.2f\n", al->n2);
    printf("nota 3: %.2f\n", al->n3);
}

void aborta_programa() {
    exit(1);
}