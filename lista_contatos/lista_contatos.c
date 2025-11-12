#include "lista_contatos.h"

LISTA* criar_lista() {
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    if (lista != NULL)
        *lista = NULL;

    return lista;
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
    NO* atual = *li;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
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
    if (lista_vazia(li) || contato.numero < (*li)->data.numero) {
        no->prox = *li;
        *li = no;
        return contato.numero;
    }

    NO* ant = *li;
    NO* atual = (*li)->prox;
    while (atual != NULL && atual->data.numero < contato.numero) {
        ant = atual;
        atual = atual->prox;
    }

    no->prox = atual;
    ant->prox = no;
    
    return contato.numero;
}

int consulta_posicao(LISTA* li, int posicao, CONTATO* contato) {
    if (li == NULL)
        aborta_programa();

    if (posicao <= 0)
        return 0;

    NO* no = *li;
    for (int i = 1; no != NULL && i < posicao; i++)
        no = no->prox;

    if (no == NULL)
        return 0;

    *contato = no->data;
    return 1;
}

int consulta_identificacao(LISTA* li, int identificacao, CONTATO* contato) {
    if (li == NULL)
        aborta_programa();

    if (identificacao <= 0)
        return 0;

    NO* no = *li;
    for (int i = 1; no != NULL && identificacao != no->data.numero; i++)
        no = no->prox;

    if (no == NULL)
        return 0;

    *contato = no->data;
    return 1;
}

int consulta_nome(LISTA* li_original, LISTA* li_nomes, char* nome) {
    if (li_original == NULL)
        aborta_programa();

    if (li_nomes == NULL)
        aborta_programa();

    NO* no = *li_original;
    for (int i = 1; no != NULL; i++) {
        no = no->prox;

        if (strstr(no->data.nome, nome) != NULL)
            insere_lista(li_nomes, no->data);
    }

    return 1;
}

int recuperar_lista(LISTA *li) {
    FILE* file = fopen("contatos.bin", "rb");
    if (file == NULL)
        return 0;

    CONTATO contato;
    while (fread(&contato, sizeof(CONTATO), 1, file) == 1) {
        if (!insere_lista(li, contato)) {
            fclose(file);
            return 0;
        }
    }

    if (!feof(file)) {
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}

int salvar_lista(LISTA *li) {
    FILE* file = fopen("contatos.bin", "wb");
    if (file == NULL)
        return 0;

    int tamanho = tamanho_lista(li);
    CONTATO* contatos = (CONTATO*) malloc(sizeof(CONTATO) * tamanho);

    int count = 0;
    NO* atual = *li;
    while (atual != NULL) {
        contatos[count] = atual->data;
        atual = atual->prox;
        count++;
    }

    fwrite(contatos, sizeof(CONTATO), tamanho, file);

    fclose(file);
    return 1;
}

void aborta_programa() {
    printf("Abortou o programa");
    exit(1);
}