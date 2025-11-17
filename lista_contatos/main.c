#include "lista_contatos.h"

int confirmar();
int scan_menu();
void print_line();
void clear();

int main() {
    int repeat = 1;
    int identificacao;

    CONTATO contato;
    LISTA* lista = criar_lista();
    if (!recuperar_lista(lista))
        printf("O arquivo de recuperação será criado ao sair do programa");

    while(repeat) {
        clear();

        switch( scan_menu() ) {
            case 1:
                clear();
                printf("\t                           Novo Contato\n");
                print_line();
                contato = scan_contato();
                if ( insere_lista(lista, contato) )
                    printf("\t Contato Inserido com sucesso!");
                else
                    printf("\t Erro ao inserir contato");
                break;

            case 2:
                clear();
                printf("\t                       Relatório de Contatos\n");
                print_line();
                contato;
                int tamanho = tamanho_lista(lista);
                for (int i = 1; i < tamanho; i++) {
                    if ( consulta_posicao(lista, i, &contato) )
                        print_contato(&contato);
                    else
                        printf("\t Erro ao ler esse Contato");
                    print_line();
                }
                printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...");
                getchar();
                getchar();
                break;

            case 3:
                printf("\t                         Relatório Individual\n");
                clear();
                printf("\tDigite o número de identificação do contato que está procurando: ");
                scanf("%d", &identificacao);
                if ( consulta_identificacao(lista, identificacao, &contato) ) {
                    printf("\n");
                    print_line();   
                    print_contato(&contato);
                    print_line();
                }
                else
                    printf("\t Erro ao ler esse Contato");
                printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...");
                getchar();
                break;

            case 4:
                printf("\t                          Relatório por Nomes\n");
                clear();

                printf("\n\tDigite o nome do contato que está procurando: ");
                char nome[100];
                getchar();
                fgets(nome, 100, stdin);
                nome[strlen(nome) -1] = '\0';

                LISTA* lista_nomes = criar_lista();
                if ( consulta_nome(lista, lista_nomes, nome) ) {
                    printf("\n");
                    print_line();
                    int tamanho = tamanho_lista(lista_nomes);
                    for (int i = 1; i < tamanho; i++) {
                        if ( consulta_posicao(lista_nomes, i, &contato) )
                            print_contato(&contato);
                        else
                            printf("\t Erro ao ler esse Contato");
                        print_line();
                    }
                }
                else
                    printf("\t Nenhum registro encontrado");

                printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...");
                getchar();
                liberar_lista(lista_nomes);
                break;

            case 5:
                printf("\t                            Editar Contato\n");
                clear();
                printf("\n\tDigite o número de identificação do contato que será editado: ");
                scanf("%d", &identificacao);

                if ( !consulta_identificacao(lista, identificacao, &contato) ) {
                    printf("\t Erro ao ler esse Contato");
                    break;
                }

                printf("\n");
                getchar();
                contato = edit_contato(&contato);

                if ( remove_lista(lista, identificacao) ) {
                    if ( insere_lista(lista, contato) )
                        printf("\t Contato editado com sucesso!");
                } else
                    printf("\n\t Erro ao ler esse Contato");

                printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...");
                getchar();
                break;

            case 6:
                printf("\t                           Excluir Contato\n");
                clear();
                printf("\n\tDigite o número de identificação do contato que será deletado: ");
                scanf("%d", &identificacao);

                if ( consulta_identificacao(lista, identificacao, &contato) ) {
                    printf("\n");
                    print_line();   
                    print_contato(&contato);
                    print_line();
                }
                else {
                    printf("\t Erro ao ler esse Contato");
                    break;
                }

                printf("\n\t Deseja mesmo deletar esse contato? ");
                if ( confirmar() ) {
                    if ( !remove_lista(lista, identificacao) )
                        printf("\n\t Erro ao ler esse Contato");
                    else
                        printf("\t Contato deletado com sucesso");
                }

                printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...");
                getchar();
                getchar();
                break;

            case 7:
                repeat = 0;
                break;
        }

    }

    clear();
    printf("\n\t Salvando dados ...\n");
    if ( salvar_lista(lista) )
        printf("\t Lista Salva com sucesso\n");
    else
        printf("\t Erro ao salvar lista\n");

    liberar_lista(lista);
    printf("\t Encerrando aplicação ...\n");
    return 0;
}

void clear() {
    printf("\033[2J\033[H");
    printf("\n");
    print_line();
    printf("\n\t    /.\\     //¨¨\\\\  |\\   /| ||¨¨¨¨       ||   |\\   ||  //¨¨\\\\\n");
    printf("\t   // \\\\   ||       ||\\ /|| ||____       ||   ||\\  || ||     \n");
    printf("\t  //---\\\\  ||       || V || ||¨¨¨¨       ||   || \\ || ||     \n");
    printf("\t //     \\\\  \\\\__//  ||   || ||____       ||   ||  \\||  \\\\__// O\n\n");
    print_line();
}

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
    printf("\n\t  Escolha uma opção do menu: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void print_line() {
    printf("\t================================================================\n");
}
