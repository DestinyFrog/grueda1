#ifndef CONTATO_H_
#define CONTATO_H_

#include <stdio.h>
#include <string.h>

typedef struct contato {
    int numero;
    char nome[100];
    char empresa[100];
    char departamento[100];
    char telefone_fixo[20];
    char telefone_celular[20];
    char email[100];
} CONTATO;

CONTATO scan_contato();
void print_contato(CONTATO* contato);

#endif /* CONTATO_H_ */