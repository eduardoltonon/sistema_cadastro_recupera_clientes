#ifndef NODO_H
#define NODO_H

#include "cliente.h"

/* * TAD Nodo
 * Elemento base das nossas listas encadeadas (tratamento de colisão e retornos)
 */
typedef struct nodo Nodo;

/*
 * Construtor: Cria um nodo que guarda a referência para um Cliente
 */
Nodo* cria_nodo(Cliente *cliente);

/*
 * Getters exigidos pelo teste2.c
 */
Cliente* get_data(Nodo *nodo);
Nodo* get_next(Nodo *nodo);

/*
 * Setter usado pelas listas e hash tables
 */
void set_next(Nodo *nodo, Nodo *proximo);

/*
 * Destrutor: Libera a memória alocada para um nodo.
 */
void libera_nodo(Nodo *nodo);

#endif