#ifndef CLIENTE_H
#define CLIENTE_H

/* * TAD Cliente
 * A definição da struct é ocultada aqui para garantir o encapsulamento.
 * A struct real será definida em cliente.c.
 */
typedef struct cliente Cliente;

/*
 * Construtor: Aloca memória e inicializa os dados de um cliente.
 */
Cliente* cria_cliente(char *nome, char *bairro, int pessoas, int criancas, double renda);

/*
 * Getters: Exigidos pelo teste2.c para acessar os dados do cliente
 */
char* get_nome(Cliente *cliente);
char* get_bairro(Cliente *cliente);
int get_pessoas(Cliente *cliente);
int get_criancas(Cliente *cliente);
double get_renda(Cliente *cliente);

#endif