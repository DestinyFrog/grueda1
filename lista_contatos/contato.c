#include "contato.h"

CONTATO scan_contato() {
    CONTATO contato;

    printf("\tInsira os dados a seguir:\n");
    printf("\tN° de Identificação   : ");
    scanf("%d", &contato.numero);

    printf("\tNome                  : ");
    getchar();
    fgets(contato.nome, 100, stdin);
    contato.nome[strlen(contato.nome) -1] = '\0';

    printf("\tEmpresa               : ");
    fgets(contato.empresa, 100, stdin);
    contato.empresa[strlen(contato.empresa) -1] = '\0';

    printf("\tDepartamento          : ");
    fgets(contato.departamento, 100, stdin);
    contato.departamento[strlen(contato.departamento) -1] = '\0';

    printf("\tTelefone Fixo         : ");
    fgets(contato.telefone_fixo, 20, stdin);
    contato.telefone_fixo[strlen(contato.telefone_fixo) -1] = '\0';

    printf("\tTelefone Celular      : ");
    fgets(contato.telefone_celular, 20, stdin);
    contato.telefone_celular[strlen(contato.telefone_celular) -1] = '\0';

    printf("\tEmail                 : ");
    fgets(contato.email, 100, stdin);
    contato.email[strlen(contato.email) -1] = '\0';

    return contato;
}

void print_contato(CONTATO* contato) {
    printf("\t================================================\n");
    printf("\t N° de Identificação   : %d\n", contato->numero);
    printf("\t Nome                  : %s\n", contato->nome);
    printf("\t Empresa               : %s\n", contato->empresa);
    printf("\t Departamento          : %s\n", contato->departamento);
    printf("\t Telefone Fixo         : %s\n", contato->telefone_fixo);
    printf("\t Telefone Celular      : %s\n", contato->telefone_celular);
    printf("\t Email                 : %s\n", contato->email);
    printf("\t================================================\n");
}