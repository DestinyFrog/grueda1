#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    float n1;
    float n2;
    float n3;
} ALUNO;

typedef struct fila FILA;

void aborta_programa();

FILA* cria_fila();
void libera_fila(FILA *f);
int tamanho_fila(FILA* f);
int fila_vazia(FILA* f);
int fila_cheia(FILA* f);
int insere_fila(FILA *f, ALUNO al);
int remove_fila(FILA *f);
int consulta_fila(FILA *f, ALUNO *al);
void printa_aluno(ALUNO* al);