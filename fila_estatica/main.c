#include <stdio.h>

#include "fila.h"

int main() {
    int tamanho;
    ALUNO al1, al2, al3, res;

    al1.matricula = 1;
    al1.n1 = 10.0;
    al1.n2 = 9.0;
    al1.n3 = 9.2;

    al2.matricula = 2;
    al2.n1 = 7.0;
    al2.n2 = 4.0;
    al2.n3 = 6.2;

    al3.matricula = 3;
    al3.n1 = 8.0;
    al3.n2 = 8.0;
    al3.n3 = 9.5;

    FILA* f = cria_fila();
    
    insere_fila(f, al1);
    insere_fila(f, al2);
    insere_fila(f, al3);

    tamanho = tamanho_fila(f);
    printf("---\ntamanho da fila: %d\n---\n", tamanho);
    consulta_fila(f, &res);
    printa_aluno(&res);

    remove_fila(f);
    tamanho = tamanho_fila(f);
    printf("---\ntamanho da fila: %d\n---\n", tamanho);
    consulta_fila(f, &res);
    printa_aluno(&res);

    remove_fila(f);
    tamanho = tamanho_fila(f);
    printf("---\ntamanho da fila: %d\n---\n", tamanho);
    consulta_fila(f, &res);
    printa_aluno(&res);

    remove_fila(f);
    tamanho = tamanho_fila(f);
    printf("---\ntamanho da fila: %d\n---\n", tamanho);

    libera_fila(f);
    return 0;
}