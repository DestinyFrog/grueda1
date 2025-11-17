#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void aborta_programa();
void str_lower(char* str);
int confirmar();
void campo_editavel(char* campo, char* valor_inicial, int tamanho);

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
CONTATO edit_contato(CONTATO* contato);

typedef struct no {
    CONTATO data;
    struct no* prox;
} NO;

typedef NO* LISTA;

LISTA* criar_lista();
void liberar_lista(LISTA* li);
int lista_cheia(LISTA* li);
int lista_vazia(LISTA* li);
int tamanho_lista(LISTA* li);
int insere_lista(LISTA* li, CONTATO contato);
int consulta_posicao(LISTA *li, int posicao, CONTATO *contato);
int consulta_identificacao(LISTA* li, int identificacao, CONTATO* contato);
int consulta_nome(LISTA* li_original, LISTA* li_nomes, char* nome);
int remove_lista(LISTA* li, int identificacao);

int recuperar_lista(LISTA *li);
int salvar_lista(LISTA *li);