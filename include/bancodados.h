/**
* @file 	bancodados.h
* @brief	Arquivo de cabeçalho com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    30/05/2017
* @date     30/05/2017
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

    #include "fornecedor.h"
    #include "produto.h"
    #include "funcoes.h"

    /**
    * @brief        Função que coleta os dados para o cadastro de um fornecedor
    * @return       Fornecedor coletado
    */
    Fornecedor inputFornecedor();

    /**
    * @brief        Função que coleta os dados para cadastro de um aluno
    * @return       Aluno coletado
    */
    Produto inputProduto();

    /**
    * @brief        Função que realiza o cadastro um Fornecedor
    * @param[in]    *e Lista de Fornecedores do cadastro
    */
    void cadFornecedor(Lista<Fornecedor> *e);

    /**
    * @brief        Função que remove uma Fornecedor do cadastro
    * @param[in]    *e Lista de Fornecedores do cadastro
    */
    void delFornecedor(Lista<Fornecedor> *e);

    /**
    * @brief        Função que adiciona um aluno à uma turma (apresenta escolha)
    * @param[in]    *e Vetor de turmas do cadastro
    */
    void addPr(Lista<Fornecedor> *e);

    /**
    * @brief        Função que adiciona alunos à uma turma (apresenta escolha),
    *               carregando-os apartir de um arquivo CSV
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Fornecedor *addPrArq(Fornecedor *e, int n, bool pausa = true);

    /**
    * @brief        Função que remove um aluno de uma turma (apresenta escolha)
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após o cadastro
    */
    Fornecedor *delPr(Fornecedor *e, int n);

    /**
    * @brief        Função que imprime os fornecedores no cadastro
    * @param[in]    *e Lista de fornecedores do cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    */
    void impFornecedores(Lista<Fornecedor> *e, bool pausa = true);

    /**
    * @brief        Função que imprime a lista de alunos de uma ou todas 
                    as turmas do cadastro
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    all "true" imprime todos os alunos de todas as turmas
                    "false" imprime apenas os alunos de uma turma (apresenta escolha)
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número da turma selecionada
    */
    int impPr(Lista<Fornecedor> *e, bool all = true, bool pausa = true);

    /**
    * @brief        Função que salva o cadastro completo em arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[in]    n Número de turmas no cadastro
    */
    void salvarBD(string nome, Fornecedor *e, int n);

    /**
    * @brief        Função que recupera o cadastro completo a partir de um arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de turmas do cadastro
    * @param[inout] n Número de turmas no cadastro
    * @return       Retorna o novo vetor de turmas após a importação
    */
    Fornecedor *abrirBD(string nome, Fornecedor *e, int &n);

    void parar();

    int selecionaFornecedor(Lista<Fornecedor> *e, string msg);

#endif