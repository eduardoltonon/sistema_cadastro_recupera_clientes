# Sistema de Cadastro e Recuperação de Clientes

Este projeto é uma implementação em linguagem C de um sistema de banco de dados em memória para gerenciar o cadastro de clientes. Ele foi desenvolvido como parte do Desafio 2 da disciplina de Estrutura de Dados.

O sistema utiliza uma estrutura avançada de **Tabelas Hash** e **Listas Encadeadas** para garantir a recuperação otimizada e eficiente de registros com base em múltiplos critérios de busca (chaves).

## 🚀 Funcionalidades

O sistema permite armazenar e consultar clientes através de 5 critérios diferentes:
1. **Busca por Nome** (Recuperação textual exata)
2. **Busca por Bairro** (Recuperação textual exata)
3. **Busca por Quantidade de Pessoas na Residência** (Índices de 1 a 5+)
4. **Busca por Presença de Crianças menores de 5 anos** (Booleano / Índices 0 e 1)
5. **Busca por Faixa de Renda** (4 faixas distintas de valores)

## 🏗️ Arquitetura e Estrutura de Dados

O projeto foi construído respeitando os princípios de encapsulamento, utilizando Tipos Abstratos de Dados (TADs) separados:

- `cliente.h` / `cliente.c`: Define o TAD Cliente e seus dados (nome, bairro, pessoas, crianças, renda).
- `nodo.h` / `nodo.c`: Define o TAD Nodo, que armazena os ponteiros para os clientes e permite a criação de listas.
- `lista.h` / `lista.c`: Define o TAD Lista Encadeada, utilizado para gerenciar as colisões da tabela hash e organizar os índices de busca.
- `estrutura.h` / `estrutura.c`: Define a Estrutura principal. Contém arrays de Listas que atuam como múltiplas Tabelas Hash (usando a função de espalhamento DJB2 para textos) e índices de acesso direto (para variáveis categóricas como faixa de renda).

Essa abordagem garante uma complexidade algorítmica próxima a **O(1)** para as buscas, otimizando drasticamente o tempo de recuperação em comparação a buscas lineares tradicionais.

## 🛠️ Gerenciamento de Memória

Foi dada atenção especial ao gerenciamento de memória. A função `libera_estrutura` garante que todas as listas, nodos e a tabela hash sejam corretamente desalocados (`free`) da memória ao final do ciclo de vida da aplicação, evitando *memory leaks*.

## 💻 Como Compilar e Executar

O projeto acompanha um `Makefile` para facilitar o processo de compilação.

### Pré-requisitos
- Compilador GCC instalado.
- Ferramenta `make` (opcional, mas recomendada).

### Passo a passo
1. Abra o terminal na raiz do projeto.
2. Para compilar todos os arquivos e gerar o executável, rode o comando:
   ```bash
   make
   ```
3. Para executar o programa de testes automático, rode:
   ```bash
   ./programa_teste
   ```
   *(No Windows utilizando o CMD padrão, basta digitar `programa_teste.exe`)*

4. (Opcional) Para limpar os arquivos `.o` e o executável gerados pela compilação, use:
   ```bash
   make clean
   ```

---
*Desenvolvido para a disciplina de Estrutura de Dados.*