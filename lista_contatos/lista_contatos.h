#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    int numero;
    char nome[100];
    char empresa[100];
    char departamento[100];
    char telefone_fixo[20];
    char telefone_celular[20];
    char email[100];
} CONTATO;

CONTATO scan_contato();
void print_contato(CONTATO* contato);
CONTATO create_fake_contato();

typedef struct NO {
    CONTATO data;
    struct NO* prox;
} NO;

typedef NO* LISTA;

LISTA* criar_lista();
void liberar_lista(LISTA* li);
int lista_cheia(LISTA* li);
int lista_vazia(LISTA* li);
int tamanho_lista(LISTA* li);
int insere_lista(LISTA* li, CONTATO contato);
int consulta_posicao(LISTA *li, int posicao, CONTATO *contato);

int recuperar_lista(LISTA *li);
int salvar_lista(LISTA *li);

void aborta_programa();