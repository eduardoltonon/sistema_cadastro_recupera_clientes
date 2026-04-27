#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

/* * TAD Lista
 * Lista encadeada simples com controle de quantidade.
 */
typedef struct lista Lista;

/*
 * Construtor: Inicializa uma lista vazia
 */
Lista* cria_lista();

/*
 * Insere um cliente no inicio da lista (O(1) - baixa complexidade)
 */
void insere_lista(Lista *lista, Cliente *cliente);

/*
 * Getters exigidos pelo teste2.c
 */
int get_quantidade(Lista *lista);
Nodo* get_inicio(Lista *lista);

/*
 * Destrutor: Libera a memória de uma lista e de todos os seus nodos.
 * IMPORTANTE: Não libera a memória dos clientes apontados pelos nodos,
 * pois eles são compartilhados entre múltiplas listas.
 */
void libera_lista(Lista *lista);

#endif