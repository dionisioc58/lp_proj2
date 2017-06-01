/**
* @file 	bancodados.h
* @brief	Arquivo de cabeçalho com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     07/05/2017
*/

#ifndef BANCODADOS_H
    #define BANCODADOS_H

    #include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;

    #include <fstream>
    using std::ifstream;
    using std::ofstream;

    #include <string>
    using std::string;

    #include "turma.h"
    #include "aluno.h"
    #include "funcoes.h"

    /**
    * @brief        Função que coleta o nome para o cadastro de uma turma
    * @return       Nome da turma
    */
    string inputTurma();

    /**
    * @brief        Função que coleta os dados para cadastro de um aluno
    * @return       Aluno coletado
    */
    Aluno inputAluno();

    /**
    * @brief        Função que verifica se uma turma já existe no cadastro
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @param[in]    nome Nome da turma a ser verificada
    * @return       Retorna true caso já exista
    */
    bool existeTurma(Turma *e, int n, string nome);

    /**
    * @brief        Função que realiza o cadastro uma turma
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[inout] n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Turma *cadTurma(Turma *e, int &n);

    /**
    * @brief        Função que remove uma turma do cadastro
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[inout] n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após a exclusão
    */
    Turma *delTurma(Turma *e, int &n);

    /**
    * @brief        Função que adiciona um aluno à uma turma (apresenta escolha)
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Turma *addAl(Turma *e, int n);

    /**
    * @brief        Função que adiciona alunos à uma turma (apresenta escolha),
    *               carregando-os apartir de um arquivo CSV
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Turma *addAlArq(Turma *e, int n, bool pausa = true);

    /**
    * @brief        Função que remove um aluno de uma turma (apresenta escolha)
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Turma *delAl(Turma *e, int n);

    /**
    * @brief        Função que imprime as turmas no cadastro
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @param[in]    n Número de turmas no cadastro
    */
    void impTurmas(Turma *e, int n, bool pausa = true);

    /**
    * @brief        Função que imprime a lista de alunos de uma ou todas 
                    as turmas do cadastro
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @param[in]    all "true" imprime todos os alunos de todas as turmas
                    "false" imprime apenas os alunos de uma turma (apresenta escolha)
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número da turma selecionada
    */
    int impAl(Turma *e, int n, bool all = true, bool pausa = true);

    /**
    * @brief        Função que salva o cadastro completo em arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    */
    void salvarBD(string nome, Turma *e, int n);

    /**
    * @brief        Função que recupera o cadastro completo a partir de um arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[inout] n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após a importação
    */
    Turma *abrirBD(string nome, Turma *e, int &n);

#endif