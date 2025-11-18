#include "app.h"

int main() {
    int repete = 1;
    int identificacao;
    int opcao_menu;

    CONTATO contato;
    LISTA* lista = criar_lista();
    if ( !recuperar_lista(lista) )
        printf("\n\t O arquivo de recuperação será criado ao sair do programa ...\n");

    while (repete) {
        clear();
        opcao_menu = scan_menu();
        clear();

        switch( opcao_menu ) {
            case 1:
                printf("\t                            Novo Contato\n");
                print_line();
                contato = scan_contato();
                if ( insere_lista(lista, contato) )
                    printf("\t Contato Inserido com sucesso!");
                else
                    printf("\t Erro ao inserir contato");
            break;

            case 2:
                printf("\t                       Relatório de Contatos");
                printa_lista(lista);
            break;

            case 3:
                printf("\t                       Relatório Individual\n");
                print_line(); 
                printf("\t Digite o número de identificação do contato: ");
                scanf("%d", &identificacao);
                if ( consulta_identificacao(lista, identificacao, &contato) ) {
                    printf("\n");
                    print_line(); 
                    print_contato(&contato);
                    print_line();
                }
                else
                    printf("\n\t O contato nao foi encontrado\n");
            break;

            case 4:
                printf("\t                        Relatório por Nomes\n");
                print_line(); 
                printf("\tDigite o nome do contato que está procurando: ");

                getchar();
                char nome[FIELD_STR_SIZE];
                fgets(nome, FIELD_STR_SIZE, stdin);
                nome[strlen(nome) - 1] = '\0';

                LISTA* lista_nomes = criar_lista();
                if ( consulta_nome(lista, lista_nomes, nome) )
                    printa_lista(lista_nomes);
                else
                    printf("\t Nenhum registro encontrado");
                liberar_lista(lista_nomes);
            break;

            case 5:
                printf("\t                            Editar Contato\n");
                print_line(); 
                printf("\n\t Digite o número de identificação do contato que será editado: ");
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
                        printf("\n\n\t Contato editado com sucesso!");
                } else
                    printf("\n\t Erro ao ler esse Contato");
            break;

            case 6:
                printf("\t                           Excluir Contato\n");
                print_line(); 
                printf("\tDigite o número de identificação do contato que será deletado: ");
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
                        printf("\n\t Erro ao ler esse Contato\n");
                    else
                        printf("\t Contato deletado com sucesso!\n");
                }
            break;

            case 7:
                repete = 0;
            break;

            default:
                printf("\t Opcao invalida\n");
                getchar();
        }

        if (repete) {
            printf("\n\t Aperte qualquer tecla para voltar ao Menu Principal ...\n");
            getchar();
        }
    }

    printf("\n\t Salvando dados ...\n");
    if ( salvar_lista(lista) )
        printf("\t Lista Salva com sucesso\n");
    else
        printf("\t Erro ao salvar lista\n");

    liberar_lista(lista);
    printf("\t Encerrando aplicação ...\n");
    return 0;
}