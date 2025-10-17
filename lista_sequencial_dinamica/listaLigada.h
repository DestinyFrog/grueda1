#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    float n1, n2, n3;
} ALUNO;

typedef struct elemento* Lista;

void aborta_programa();

Lista* cria_lista();
void apaga_lista(Lista* li);
int tamanho_lista(Lista *li);
int insere_inicio(Lista *li, ALUNO al);
int insere_final(Lista *li, ALUNO al);
int insere_ordenado(Lista *li, ALUNO al);
int remove_inicio(Lista *li);
int remove_final(Lista *li);
int remove_ordenado(Lista *li, int mat);
int consulta_posicao(Lista *li, int posicao, ALUNO *al);
int consulta_matricula(Lista *li, int mat, ALUNO *al);
ALUNO coleta_dados();

void printar_lista(Lista *li);