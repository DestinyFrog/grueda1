#include <stdio.h>
#include <string.h>

#include "listaLigada.h"

int main() {
    Lista* li = cria_lista();
    if (li == NULL)
        aborta_programa();

    ALUNO res;
    char entrada[20];

    while (1) {
        printf("Escolha uma das acoes a seguir:\n");
        printf(" incluir | buscar | excluir | encerrar\n");
        scanf(" %s", entrada);

        if ( !strcmp(entrada, "incluir") ) {
            res = coleta_dados();
            if ( insere_ordenado(li, res) )
                printf("Registro inserido com sucesso\n");
        }
        else if ( !strcmp(entrada, "buscar") ) {
            int matricula;
            printf("Insira a matrícula: ");
            scanf("%d", &matricula);
            if ( consulta_matricula(li, matricula, &res) )
                printar_aluno(&res);
            else
                printf("Nao foi possivel encontrar o registro\n");
        }
        else if ( !strcmp(entrada, "excluir") ) {
            int matricula;
            printf("Insira a matrícula: ");
            scanf("%d", &matricula);
            if ( remove_ordenado(li, matricula) )
                printf("Registro deLetado com sucesso\n");
        }
        else if ( !strcmp(entrada, "encerrar") ) {
            break;
        }
        else {
            printf("Essa acao nao e valida\n");
        }
    }

    printf("tchau");
    apaga_lista(li);
    return 0;
}
