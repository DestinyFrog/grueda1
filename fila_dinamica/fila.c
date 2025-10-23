#include "fila.h"

typedef struct elemento {
    ALUNO dados;
    struct elemento* prox;
} ELEM;

typedef struct fila {
    int qtd;
    ELEM* inicio;
    ELEM* fim;
} FILA;

FILA* cria_fila() {
    FILA* f;
    f = (FILA*) malloc(sizeof(FILA));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}

void libera_fila(FILA *f) {
    if (f == NULL)
        return;

    ELEM* no;
    while(f->inicio != NULL) {
        no = f->inicio;
        f->inicio = f->inicio->prox;
        free(no);
    }
    free(f);
}

int tamanho_fila(FILA* f) {
    return f->qtd;
}

int fila_vazia(FILA* f) {
    return f->qtd == 0;
}

int fila_cheia(FILA* f) {
    return 0;
}

int insere_fila(FILA *f, ALUNO al) {
    if (f == NULL)
        aborta_programa();

    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;
    if (f->fim == NULL)
        f->inicio = no;
    else
        f->fim->prox = no;

    f->fim = no;
    f->qtd++;
    return al.matricula;
}

int remove_fila(FILA *f) {
    if (f == NULL)
        aborta_programa();

    if (fila_vazia(f))
        return 0;

    int matricula = f->inicio->dados.matricula;
    
    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(no);
    f->qtd--;
    return matricula;
}

int consulta_fila(FILA *f, ALUNO *al) {
    if (f == NULL)
        aborta_programa();

    if (fila_vazia(f))
        return 0;

    *al = f->inicio->dados;
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