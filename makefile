#Makefile for "Projeto 2 de LP 1" C++ aplication
#Created by Dionísio Carvalho & Luís Eduardo Rique

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean loja doxy
debug: CFLAGS += -g -O0
debug: clean loja

# Alvo (target) para a construcao do executavel main
# Define os arquivos fornecedor.o, produto.o, funcoes.o, menu.o e main.o como dependencias
loja: $(OBJ_DIR)/fornecedor.o $(OBJ_DIR)/produto.o $(OBJ_DIR)/pereciveis.o $(OBJ_DIR)/npereciveis.o $(OBJ_DIR)/venda.o $(OBJ_DIR)/bancodados.o $(OBJ_DIR)/funcoes.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto fornecedor.o
# Define os arquivos fornecedor.cpp e fornecedor.h como dependencias.
$(OBJ_DIR)/fornecedor.o: $(SRC_DIR)/fornecedor.cpp $(INC_DIR)/fornecedor.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto produto.o
# Define os arquivos produto.cpp e produto.h como dependencias.
$(OBJ_DIR)/produto.o: $(SRC_DIR)/produto.cpp $(INC_DIR)/produto.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos pereciveis.cpp e subproduto.h como dependencias.
$(OBJ_DIR)/pereciveis.o: $(SRC_DIR)/pereciveis.cpp $(INC_DIR)/subproduto.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto npereciveis.o
# Define os arquivos npereciveis.cpp e subproduto.h como dependencias.
$(OBJ_DIR)/npereciveis.o: $(SRC_DIR)/npereciveis.cpp $(INC_DIR)/subproduto.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto venda.o
# Define os arquivos venda.cpp e venda.h como dependencias.
$(OBJ_DIR)/venda.o: $(SRC_DIR)/venda.cpp $(INC_DIR)/venda.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto menu.o
# Define os arquivos menu.cpp e menu.h como dependencias.
$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(INC_DIR)/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto bancodados.o
# Define os arquivos bancodados.cpp e bancodados.h como dependencias.
$(OBJ_DIR)/bancodados.o: $(SRC_DIR)/bancodados.cpp $(INC_DIR)/bancodados.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto funcoes.o
# Define os arquivos funcoes.cpp e funcoes.h como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/funcoes.cpp $(INC_DIR)/funcoes.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
