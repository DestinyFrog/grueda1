#include "listaLigada.h"

typedef struct elemento {
    ALUNO dados;
    struct elemento* prox;
} ELEM;

Lista* cria_lista() {
    Lista* li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void aborta_programa() {
    printf("ERRO! Lista nao foi alocada");
    printf("programa sera encontrada ... \n\n\n");
    system("pause");
    exit(1);
}

void apaga_lista(Lista* li) {
    if (li != NULL) {
        ELEM* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
    }
    free(li);
}

int tamanho_lista(Lista *li) {
    if (li == NULL)
        aborta_programa();

    int ac = 0;
    ELEM* no = *li;
    while (no != NULL) {
        ac++;
        no = no->prox;
    }
    return ac;
}

int lista_cheia(Lista* li) {
    if (li == NULL)
        aborta_programa();
    return 0;
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        aborta_programa();

    if (*li == NULL)
        return 1;

    return 0;
}

int insere_inicio(Lista *li, ALUNO al) {
    if (li == NULL)
        aborta_programa();

    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = (*li);
    *li = no;
    return al.matricula;
}

int insere_final(Lista *li, ALUNO al) {
    if (li == NULL)
        aborta_programa();

    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;

    if ((*li) == NULL)
        *li = no;
    else {
        ELEM *aux = (*li);
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }

    return al.matricula;
}

int insere_ordenado(Lista *li, ALUNO al) {
    if (li == NULL)
        aborta_programa();

    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL)
        return 0;

    no->dados = al;
    if (lista_vazia(li)) {
        no->prox = (*li);
        *li = no;
        return al.matricula;
    }

    ELEM *ant, *atual = *li;
    while (atual != NULL && atual->dados.matricula < al.matricula) {
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
    
    return al.matricula;
}

int remove_inicio(Lista *li) {
    int matricula;
    if (li == NULL)
        aborta_programa();

    if (*li == NULL) {
        return 0;
    }

    ELEM *no = *li;
    matricula = no->dados.matricula;
    *li = no->prox;
    free(no);
    return matricula;
}

int remove_final(Lista *li) {
    int matricula;
    if (li == NULL)
        aborta_programa();

    if (*li == NULL) {
        return 0;
    }

    ELEM *ant, *no = *li;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }

    if (no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;

    matricula - no->dados.matricula;
    free(no);
    return matricula;
}

int remove_ordenado(Lista *li, int mat) {
    int matricula;
    if (li == NULL)
        aborta_programa();

    ELEM *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL)
        return 0;

    if (no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;

    matricula - no->dados.matricula;
    free(no);
    return matricula;
}

int consulta_posicao(Lista *li, int posicao, ALUNO *al) {
    if (li == NULL)
        aborta_programa();

    if (posicao <= 0)
        return 0;

    ELEM *no = *li;
    int i = 1;
    while(no != NULL && i < posicao) {
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return 0;

    *al = no->dados;    
    return 1;
}

int consulta_matricula(Lista *li, int mat, ALUNO *al) {
    if (li == NULL)
        aborta_programa();

    ELEM *no = *li;
    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;

    if (no == NULL)
        return 0;

    *al = no->dados;
    return 1;
}

void printar_aluno(ALUNO* al) {
    printf("matricula: %d\n", al->matricula);
    printf("nota 1: %.2f\n", al->n1);
    printf("nota 2: %.2f\n", al->n2);
    printf("nota 3: %.2f\n", al->n3);
}

void printar_lista(Lista *li) {
    if (li == NULL) {
        printf("---\nA lista está vazia\n---\n");
        return;
    }

    printf("---\n");
    
    ELEM* no = (*li);
    while (no != NULL) {
        printar_aluno(&no->dados);
        printf("---\n");
        no = no->prox;
    }
}

ALUNO coleta_dados() {
    ALUNO al;
    printf("Insira os seguintes dados do aluno:\n");
    printf("matricula: ");
    scanf("%d", &al.matricula);
    printf("nota 1: ");
    scanf("%f", &al.n1);
    printf("nota 2: ");
    scanf("%f", &al.n2);
    printf("nota 3: ");
    scanf("%f", &al.n3);
    return al;
}