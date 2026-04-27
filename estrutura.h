#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "cliente.h"
#include "lista.h"

/*
 * Tamanho da nossa tabela hash para textos (Nomes e Bairros)
 * Um número primo ajuda a diminuir colisões (Ex: 101, 997, 1009)
 */
#define HASH_SIZE 101

/* * TAD Estrutura (A Nossa Tabela Hash Multichave)
 */
typedef struct estrutura Estrutura;

/*
 * Construtor: Inicializa todas as tabelas hash internas
 */
Estrutura* cria_estrutura();

/*
 * Insere um cliente no banco de dados (inserindo seus índices em 5 tabelas diferentes)
 */
void insere_cliente(Estrutura *estrutura, int criterio, Cliente *cliente);

/*
 * Função principal de recuperação, exatamente como exigido no desafio.
 * Retorna uma Lista alocada contendo os resultados da busca.
 * Criterios:
 * 1 - Nome
 * 2 - Bairro
 * 3 - Qtde Pessoas (complemento 1 a 5)
 * 4 - Crianças < 5 anos (complemento 0 ou 1)
 * 5 - Faixa de Renda (complemento 1 a 4)
 */
Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);

/*
 * Libera a memória da estrutura
 */
void libera_estrutura(Estrutura *estrutura);

#endif