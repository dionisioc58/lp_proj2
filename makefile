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
TST_DIR = ./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean tarefa doxy
debug: CFLAGS += -g -O0
debug: clean tarefa

# Alvo (target) para a construcao do executavel tarefa
# Define os arquivos turma.o, aluno.o, funcoes.o, menu.o e tarefa3main.o como dependencias
tarefa: $(OBJ_DIR)/turma.o $(OBJ_DIR)/aluno.o $(OBJ_DIR)/bancodados.o $(OBJ_DIR)/funcoes.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/tarefa3main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto turma.o
# Define os arquivos turma.cpp e turma.h como dependencias.
$(OBJ_DIR)/turma.o: $(SRC_DIR)/tarefa3/turma.cpp $(INC_DIR)/tarefa3/turma.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto aluno.o
# Define os arquivos aluno.cpp e aluno.h como dependencias.
$(OBJ_DIR)/aluno.o: $(SRC_DIR)/tarefa3/aluno.cpp $(INC_DIR)/tarefa3/aluno.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto menu.o
# Define os arquivos menu.cpp e menu.h como dependencias.
$(OBJ_DIR)/menu.o: $(SRC_DIR)/tarefa3/menu.cpp $(INC_DIR)/tarefa3/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto bancodados.o
# Define os arquivos bancodados.cpp e bancodados.h como dependencias.
$(OBJ_DIR)/bancodados.o: $(SRC_DIR)/tarefa3/bancodados.cpp $(INC_DIR)/tarefa3/bancodados.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto funcoes.o
# Define os arquivos funcoes.cpp e funcoes.h como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/tarefa3/funcoes.cpp $(INC_DIR)/tarefa3/funcoes.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto tarefa3main.o
# Define o arquivo tarefa3main.cpp como dependencia.
$(OBJ_DIR)/tarefa3main.o: $(SRC_DIR)/tarefa3/tarefa3main.cpp $(INC_DIR)/tarefa2/lista.h
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
