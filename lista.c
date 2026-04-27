#include <stdlib.h>
#include "lista.h"

/*
 * Estrutura da Lista Encadeada
 */
struct lista {
    Nodo *inicio;
    int quantidade;
};

Lista* cria_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->inicio = NULL;
        l->quantidade = 0;
    }
    return l;
}

/*
 * Inserção sempre no início da lista para garantir complexidade O(1)
 */
void insere_lista(Lista *lista, Cliente *cliente) {
    if (lista == NULL || cliente == NULL) return;
    
    Nodo *novo = cria_nodo(cliente);
    if (novo != NULL) {
        set_next(novo, lista->inicio);
        lista->inicio = novo;
        lista->quantidade++;
    }
}

int get_quantidade(Lista *lista) {
    if (lista == NULL) return 0;
    return lista->quantidade;
}

Nodo* get_inicio(Lista *lista) {
    if (lista == NULL) return NULL;
    return lista->inicio;
}

void libera_lista(Lista *lista) {
    if (lista == NULL) return;

    Nodo *cursor = lista->inicio;
    while (cursor != NULL) {
        Nodo *temp = cursor;
        cursor = get_next(cursor);
        // A função libera_nodo (de nodo.c) deve apenas dar free no nodo.
        libera_nodo(temp);
    }
    free(lista);
}