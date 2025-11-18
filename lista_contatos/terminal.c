#include "app.h"

int scan_menu() {
    printf("\t                         Menu Principal\n");
    print_line();
    printf("\t 1 - Inserção de novo contato\n");
    printf("\t 2 - Relatório de Contatos\n");
    printf("\t 3 - Relatório Individual (selecionado por identificador)\n");
    printf("\t 4 - Relatório Individual (selecionado por nome)\n");
    printf("\t 5 - Edição de Dados do Contato (selecionado por identificador)\n");
    printf("\t 6 - Remover Contato (selecionado por identificador)\n");
    printf("\t 7 - Salvar e Sair\n");
    print_line();
    printf("\t Escolha uma opção do menu: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void clear() {
    printf("\033[2J\033[H\n");
    print_line();
    printf("\t    /.\\     //¨¨\\\\  |\\   /| ||¨¨¨¨       ||   |\\   ||  //¨¨\\\\\n");
    printf("\t   // \\\\   ||       ||\\ /|| ||____       ||   ||\\  || ||     \n");
    printf("\t  //---\\\\  ||       || V || ||¨¨¨¨       ||   || \\ || ||     \n");
    printf("\t //     \\\\  \\\\__//  ||   || ||____       ||   ||  \\||  \\\\__// O\n");
    print_line();
}

void print_line() {
    printf("\t================================================================\n");
}

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
}