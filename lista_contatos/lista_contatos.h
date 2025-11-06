#ifndef LISTA_CONTATOS_H_
#define LISTA_CONTATOS_H_

#include <stdlib.h>

#include "contato.h"

typedef struct elem* LISTA;

LISTA* criar_lista();
void liberar_lista(LISTA* li);
int lista_cheia(LISTA* li);
int lista_vazia(LISTA* li);
int tamanho_lista(LISTA* li);
int insere_lista(LISTA* li, CONTATO contato);
int consulta_posicao(LISTA *li, int posicao, CONTATO *contato);

void aborta_programa();

#endif /* LISTA_CONTATOS_H_ */