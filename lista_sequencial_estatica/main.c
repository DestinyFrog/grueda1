#include "listaSequencial.h"

struct aluno ler_aluno();

int main() {
    Lista* li = criar_lista();

    struct aluno al1, al2, al3, res;

    al1.matricula = 30;
    al1.n1 = 7.0;
    al1.n2 = 8.0;
    al1.n3 = 9.0;

    al2.matricula = 31;
    al2.n1 = 7.5;
    al2.n2 = 6.0;
    al2.n3 = 10.0;

    al3.matricula = 32;
    al3.n1 = 4.0;
    al3.n2 = 10.0;
    al3.n3 = 9.5;

    insere_lista_inicio(li, al1);
    insere_lista_final(li, al3);
    insere_lista_ordenada(li, al2);

    printar_lista(li);

    remove_lista_final(li);
    remove_lista_inicio(li);
    remove_lista(li, 31);

    printar_lista(li);

    res = ler_aluno();
    insere_lista_ordenada(li, res);

    printar_lista(li);

    liberar_lista(li);
}

struct aluno ler_aluno() {
    struct aluno al;
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