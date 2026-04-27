#include <stdlib.h>
#include <string.h>
#include "cliente.h"

/*
 * Ocultamos a struct aqui no ficheiro .c (Encapsulamento do TAD).
 * Nenhuma outra parte do código sabe como o cliente é feito por dentro,
 * apenas acedem através dos "getters".
 */
struct cliente {
    char nome[41];
    char bairro[41];
    int pessoas;
    int criancas;
    double renda;
};

Cliente* cria_cliente(char *nome, char *bairro, int pessoas, int criancas, double renda) {
    Cliente *c = (Cliente*) malloc(sizeof(Cliente));
    if (c != NULL) {
        // strncpy é mais seguro para evitar overflow (limite de 40 carateres)
        strncpy(c->nome, nome, 40);
        c->nome[40] = '\0'; 
        strncpy(c->bairro, bairro, 40);
        c->bairro[40] = '\0';
        
        c->pessoas = pessoas;
        c->criancas = criancas;
        c->renda = renda;
    }
    return c;
}

char* get_nome(Cliente *cliente) {
    return cliente->nome;
}

char* get_bairro(Cliente *cliente) {
    return cliente->bairro;
}

int get_pessoas(Cliente *cliente) {
    return cliente->pessoas;
}

int get_criancas(Cliente *cliente) {
    return cliente->criancas;
}

double get_renda(Cliente *cliente) {
    return cliente->renda;
}