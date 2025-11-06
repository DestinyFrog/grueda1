#include "lista_contatos.h"

typedef struct elem {
    CONTATO data;
    struct elem* prox;
} NO;

LISTA* criar_lista() {
    LISTA* li = (LISTA*) malloc(sizeof(LISTA));
    if (li != NULL)
        *li = NULL;
    return li;
}

void liberar_lista(LISTA* li) {
    if (li != NULL) {
        NO* prox;
        while ((*li) != NULL) {
            prox = *li;
            *li = (*li)->prox;
            free(prox);
        }
    }
    free(li);
}

int tamanho_lista(LISTA* li) {
    if (li == NULL)
        aborta_programa();

    int count = 0;
    NO* prox = *li;
    while (prox != NULL) {
        count++;
        prox = (*li)->prox;
    }
    return count;
}

int lista_cheia(LISTA* li) {
    if (li == NULL)
        aborta_programa();
    return 0;
}

int lista_vazia(LISTA* li) {
    if (li == NULL)
        aborta_programa();

    if (*li == NULL)
        return 1;

    return 0;
}

int insere_lista(LISTA* li, CONTATO contato) {
    if (li == NULL)
        aborta_programa();

    NO* no = (NO*) malloc(sizeof(NO));
    if (no == NULL)
        return 0;

    no->data = contato;
    if (lista_vazia(li)) {
        no->prox = (*li);
        *li = no;
        return contato.numero;
    }

    NO *ant, *atual = *li;
    while (atual != NULL && atual->data.numero < contato.numero) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == *li) {
        no->prox = (*li);
        *li = no;
    }
    else {
        no->prox = ant->prox;
        ant->prox = no;
    }
    
    return contato.numero;
}

int consulta_posicao(LISTA *li, int posicao, CONTATO *contato) {
    if (li == NULL)
        aborta_programa();

    if (posicao <= 0)
        return 0;

    NO *no = *li;
    int i = 1;
    while(no != NULL && i < posicao) {
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return 0;

    *contato = no->data;    
    return 1;
}

void aborta_programa() {
    printf("Abortou o programa");
    exit(1);
}