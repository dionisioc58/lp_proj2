/**
 * @file	tratastring.h
 * @brief	Declaracao dos prototipos de funcoes para tratamento de strings
 * @details	As funcoes definidas neste cabecalho dizem respeito a conversao
 *			da string para letras minusculas, remocao de espacos em branco e
 *			remocao de caracteres de pontuacao.
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @author	Silvio Sampaio (silviocs@imd.ufrn.br)
 * @since	18/03/2017
 * @date	11/05/2017
 */

#ifndef TRATA_STRING_H
#define TRATA_STRING_H

#include <string>
using std::string;


/**
 * @brief Funcao que converte todos os caracteres para letra minuscula
 * @param s String a ser convertida
 */
void minusculas(string& s);


/**
 * @brief Funcao que remove espacos de uma string
 * @param s String com espacos a remover
 */
void remove_espacos(string& s);


/**
 * @brief Funcao que remove sinais de pontuacao de uma string
 * @param s String com sinais de pontuacao a remover
 */
void remove_pontuacao(string& s);

/**
 * @brief Funcao que trata uma string, removendo espacos em branco
 * @param s String a ser tratada
 */
void tratar_string(string& s);

#endif
