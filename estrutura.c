#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

/*
 * Esta é a joia da coroa. A nossa estrutura guarda 5 conjuntos 
 * de listas diferentes, operando como índices de um banco de dados real.
 */
struct estrutura {
    Lista* hash_nomes[HASH_SIZE];
    Lista* hash_bairros[HASH_SIZE];
    Lista* idx_pessoas[5];   /* Índices diretos para: 1, 2, 3, 4, 5+ */
    Lista* idx_criancas[2];  /* Índices diretos para: 0 (Não), 1 (Sim) */
    Lista* idx_renda[4];     /* Índices diretos para faixas 1, 2, 3 e 4 */
};

/*
 * Função Clássica DJB2 para calcular o espalhamento (hash) de Strings.
 * É muito eficiente e gera uma distribuição uniforme.
 */
unsigned long hash_string(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

Estrutura* cria_estrutura() {
    Estrutura *e = (Estrutura*) malloc(sizeof(Estrutura));
    if (e != NULL) {
        // Inicializar todas as listas vazias
        for (int i = 0; i < HASH_SIZE; i++) {
            e->hash_nomes[i] = cria_lista();
            e->hash_bairros[i] = cria_lista();
        }
        for (int i = 0; i < 5; i++) e->idx_pessoas[i] = cria_lista();
        for (int i = 0; i < 2; i++) e->idx_criancas[i] = cria_lista();
        for (int i = 0; i < 4; i++) e->idx_renda[i] = cria_lista();
    }
    return e;
}

void insere_cliente(Estrutura *estrutura, int criterio, Cliente *cliente) {
    if (estrutura == NULL || cliente == NULL) return;

    if (criterio == 1) {
        unsigned long h_nome = hash_string(get_nome(cliente));
        insere_lista(estrutura->hash_nomes[h_nome], cliente);
    } else if (criterio == 2) {
        unsigned long h_bairro = hash_string(get_bairro(cliente));
        insere_lista(estrutura->hash_bairros[h_bairro], cliente);
    } else if (criterio == 3) {
        int p = get_pessoas(cliente);
        if (p >= 5) p = 5;
        if (p >= 1) insere_lista(estrutura->idx_pessoas[p - 1], cliente);
    } else if (criterio == 4) {
        int c = get_criancas(cliente) > 0 ? 1 : 0;
        insere_lista(estrutura->idx_criancas[c], cliente);
    } else if (criterio == 5) {
        double r = get_renda(cliente);
        int idx_r = 0;
        if (r <= 2000.00) idx_r = 0;
        else if (r <= 3000.00) idx_r = 1;
        else if (r <= 5000.00) idx_r = 2;
        else idx_r = 3;
        insere_lista(estrutura->idx_renda[idx_r], cliente);
    }
}

void libera_estrutura(Estrutura *estrutura) {
    if (estrutura == NULL) return;

    // 1. Libera todas as listas das tabelas hash
    for (int i = 0; i < HASH_SIZE; i++) {
        libera_lista(estrutura->hash_nomes[i]);
        libera_lista(estrutura->hash_bairros[i]);
    }

    // 2. Libera todas as listas dos índices diretos
    for (int i = 0; i < 5; i++) libera_lista(estrutura->idx_pessoas[i]);
    for (int i = 0; i < 2; i++) libera_lista(estrutura->idx_criancas[i]);
    for (int i = 0; i < 4; i++) libera_lista(estrutura->idx_renda[i]);

    // 3. Finalmente, libera a própria estrutura
    free(estrutura);
}

Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca) {
    /* Criamos uma nova lista para devolver apenas os resultados exatos, 
       limpando eventuais colisões na hash de textos */
    Lista *resultado = cria_lista();
    if (estrutura == NULL || resultado == NULL) return resultado;

    if (criterio == 1 && busca != NULL) { // Busca por Nome
        unsigned long h = hash_string(busca);
        Nodo *cursor = get_inicio(estrutura->hash_nomes[h]);
        while (cursor != NULL) {
            Cliente *c = get_data(cursor);
            if (strcmp(get_nome(c), busca) == 0) {
                insere_lista(resultado, c);
            }
            cursor = get_next(cursor);
        }
    }
    else if (criterio == 2 && busca != NULL) { // Busca por Bairro
        unsigned long h = hash_string(busca);
        Nodo *cursor = get_inicio(estrutura->hash_bairros[h]);
        while (cursor != NULL) {
            Cliente *c = get_data(cursor);
            if (strcmp(get_bairro(c), busca) == 0) {
                insere_lista(resultado, c);
            }
            cursor = get_next(cursor);
        }
    }
    else if (criterio == 3) { // Busca por Pessoas
        int idx = complemento - 1;
        if (idx >= 0 && idx < 5) {
            Nodo *cursor = get_inicio(estrutura->idx_pessoas[idx]);
            while (cursor != NULL) {
                insere_lista(resultado, get_data(cursor));
                cursor = get_next(cursor);
            }
        }
    }
    else if (criterio == 4) { // Busca por Crianças
        int idx = complemento;
        if (idx == 0 || idx == 1) {
            Nodo *cursor = get_inicio(estrutura->idx_criancas[idx]);
            while (cursor != NULL) {
                insere_lista(resultado, get_data(cursor));
                cursor = get_next(cursor);
            }
        }
    }
    else if (criterio == 5) { // Busca por Renda
        int idx = complemento - 1;
        if (idx >= 0 && idx < 4) {
            Nodo *cursor = get_inicio(estrutura->idx_renda[idx]);
            while (cursor != NULL) {
                insere_lista(resultado, get_data(cursor));
                cursor = get_next(cursor);
            }
        }
    }

    return resultado;
}