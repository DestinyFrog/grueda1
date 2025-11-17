#include "lista_contatos.h"

void aborta_programa() {
    printf("Abortou o programa");
    exit(1);
}

void str_lower(char* str) {
    for (; *str == '\0'; str++)
        *str = tolower(*str);
}

int confirmar() {
    char confirma[5];
    
    printf("[S/N Sim/Nao]: ");
    scanf(" %s", confirma);
    str_lower(confirma);

    while (!(
        strcmp(confirma, "s") ||
        strcmp(confirma, "n") ||
        strcmp(confirma, "sim") ||
        strcmp(confirma, "nao")
    )) {
        printf("\t Insira um valor valido [Y/N]: ");
        scanf(" %s", confirma);
        str_lower(confirma);
    }

    return strcmp(confirma, "s") || strcmp(confirma, "sim");
}

void campo_editavel(char* campo, char* valor_inicial, int tamanho) {
    char novo_valor[tamanho];
    fgets(novo_valor, tamanho, stdin);
    novo_valor[strlen(novo_valor) - 1] = '\0';

    if (novo_valor[0] == '\t')
        strcpy(campo, valor_inicial);
    else
        strcpy(campo, novo_valor);

    printf("\n\n%s\n%s\n%s\n\n", campo, valor_inicial, novo_valor);
}