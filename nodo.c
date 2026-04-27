#include <stdlib.h>
#include "nodo.h"

/*
 * A estrutura do nodo contém um ponteiro para o Cliente e 
 * um ponteiro para o próximo Nodo da lista.
 */
struct nodo {
    Cliente *cliente;
    Nodo *next;
};

Nodo* cria_nodo(Cliente *cliente) {
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    if (n != NULL) {
        n->cliente = cliente;
        n->next = NULL;
    }
    return n;
}

Cliente* get_data(Nodo *nodo) {
    return nodo->cliente;
}

Nodo* get_next(Nodo *nodo) {
    return nodo->next;
}

void set_next(Nodo *nodo, Nodo *proximo) {
    nodo->next = proximo;
}

void libera_nodo(Nodo *nodo) {
    free(nodo);
}