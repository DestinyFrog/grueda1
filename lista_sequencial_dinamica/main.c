#include "listaLigada.h"

int main() {
    Lista* li = cria_lista();
    if (li == NULL)
        aborta_programa();

    ALUNO res;

    while (1) {
        
        res = coleta_dados();
        insere_ordenado(li, res);
    }

    apaga_lista(li);
}
