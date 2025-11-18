#include "app.h"

CONTATO scan_contato() {
    CONTATO contato;

    printf("\tInsira os dados a seguir:\n");
    printf("\tN° de Identificação   : ");
    scanf("%d", &contato.numero);

    printf("\tNome                  : ");
    getchar();
    fgets(contato.nome, FIELD_STR_SIZE, stdin);
    contato.nome[strlen(contato.nome) -1] = '\0';

    printf("\tEmpresa               : ");
    fgets(contato.empresa, FIELD_STR_SIZE, stdin);
    contato.empresa[strlen(contato.empresa) -1] = '\0';

    printf("\tDepartamento          : ");
    fgets(contato.departamento, FIELD_STR_SIZE, stdin);
    contato.departamento[strlen(contato.departamento) -1] = '\0';

    printf("\tTelefone Fixo         : ");
    fgets(contato.telefone_fixo, 20, stdin);
    contato.telefone_fixo[strlen(contato.telefone_fixo) -1] = '\0';

    printf("\tTelefone Celular      : ");
    fgets(contato.telefone_celular, 20, stdin);
    contato.telefone_celular[strlen(contato.telefone_celular) -1] = '\0';

    printf("\tEmail                 : ");
    fgets(contato.email, FIELD_STR_SIZE, stdin);
    contato.email[strlen(contato.email) -1] = '\0';

    return contato;
}

void print_contato(CONTATO* contato) {
    printf("\t N° de Identificação   | %d\n", contato->numero);
    printf("\t Nome                  | %s\n", contato->nome);
    printf("\t Empresa               | %s\n", contato->empresa);
    printf("\t Departamento          | %s\n", contato->departamento);
    printf("\t Telefone Fixo         | %s\n", contato->telefone_fixo);
    printf("\t Telefone Celular      | %s\n", contato->telefone_celular);
    printf("\t Email                 | %s\n", contato->email);
}

CONTATO edit_contato(CONTATO* contato) {
    CONTATO novo_contato;
    novo_contato.numero = contato->numero;

    printf("\t Digite [backspace] para manter o valor anterior\n\n");

    printf("\t Nome (antigo)           | %s\n", contato->nome);
    printf("\t ╚> Nome                 | ");
    campo_editavel(novo_contato.nome, contato->nome, FIELD_STR_SIZE);

    printf("\n\t Empresa (antigo)        | %s\n", contato->empresa);
    printf("\t ╚> Empresa              | ");
    campo_editavel(novo_contato.empresa, contato->empresa, FIELD_STR_SIZE);

    printf("\n\t Departamento (antigo)   | %s\n", contato->departamento);
    printf("\t ╚> Departamento         | ");
    campo_editavel(novo_contato.departamento, contato->departamento, FIELD_STR_SIZE); 

    printf("\n\t Telefone Fixo (antigo)  | %s\n", contato->telefone_fixo);
    printf("\t ╚> Telefone Fixo        | ");
    campo_editavel(novo_contato.telefone_fixo, contato->telefone_fixo, FIELD_STR_SIZE); 

    printf("\n\t Telefone Celular (antigo)| %s\n", contato->telefone_celular);
    printf("\t ╚> Telefone Celular      | ");
    campo_editavel(novo_contato.telefone_celular, contato->telefone_celular, FIELD_STR_SIZE); 

    printf("\n\t Email (antigo)           | %s\n", contato->email);
    printf("\t ╚> Email                 | ");
    campo_editavel(novo_contato.email, contato->email, FIELD_STR_SIZE); 

    return novo_contato;
}
