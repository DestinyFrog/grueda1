#include <stdio.h>
#include <stdlib.h>

#include "contato.h"
#include "lista_contatos.h"

int main() {
    LISTA* lista = criar_lista();

    CONTATO contato = scan_contato();
    insere_lista(lista, contato);

    CONTATO* new_contato;
    consulta_posicao(lista, 1, new_contato);
    
    print_contato(new_contato);

    liberar_lista(lista);
    return 0;
}