# Compilador a ser usado
CC = gcc

# Flags de compilação: -Wall (todos os warnings), -g (informações de debug)
CFLAGS = -Wall -g

# Nome do executável final
TARGET = programa_teste

# Lista de todos os arquivos-fonte (.c)
SOURCES = cliente.c nodo.c lista.c estrutura.c teste2.c

# Gera a lista de arquivos-objeto (.o) a partir dos fontes
OBJECTS = $(SOURCES:.c=.o)

# A regra principal: o que fazer quando 'make' é chamado sem argumentos
all: $(TARGET)

# Regra para linkar o programa: depende de todos os arquivos .o
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(CFLAGS)

# Regra para limpar os arquivos gerados (executável e objetos)
clean:
	rm -f $(TARGET) $(OBJECTS)