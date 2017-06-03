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

    #include <sstream>
    
    #include "fornecedor.h"
    #include "produto.h"
    #include "subproduto.h"
    #include "venda.h"
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
    Produto *inputProduto();

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
    * @brief        Função que remove um aluno de uma turma (apresenta escolha)
    * @param[in]    *e Vetor de turmas do cadastro
    */
    void delPr(Lista<Fornecedor> *e);

    /**
    * @brief        Função que edita um produto de um Fornecedor (apresenta escolha)
    * @param[in]    *e Lista de Fornecedores do cadastro
    */
    void editPr(Lista<Fornecedor> *e);

    /**
    * @brief        Função que imprime os objetos na lista
    * @param[in]    *e Lista de fornecedores do cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    */
    template<typename T>
    void impLista(Lista<T> *e, bool pausa = true);

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
    * @brief        Função que imprime a lista de produtos
    * @param[inout] *e Lista de Fornecedores do cadastro
    * @param[in]    filtro Filtro de listagem (0 = sem filtro, 1 = filtrar por tipo, 2 = filtrar por codigo)
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número do fornecedor selecionada
    */
    int impPrLista(Lista<Fornecedor> *e, int filtro = 0, bool pausa = true);

    /**
    * @brief        Função que salva o cadastro completo em arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Lista de fornecedores do cadastro
    */
    void salvarBD(string nome, Lista<Fornecedor> *e);

    /**
    * @brief        Função que recupera o cadastro completo a partir de um arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Lista de Fornecedores do cadastro
    */
    void abrirBD(string nome, Lista<Fornecedor> *e);

    /**
    * @brief        Função que exibe uma mensagem para manter a tela congelada
    */
    void parar();

    /**
    * @brief        Função que exibe uma mensagem e uma lista numerada para a escolha de um objeto
    * @param[in]    *e Lista de objeto
    * @param[in]    msg Mensagem à exibir
    */
    template<typename T>
    int selecionaObjeto(Lista<T> *e, string msg);

    /**
    * @brief        Função que realiza uma venda
    * @param[in]    *e Lista de fornecedores com seus produtos
    * @param[in]    *v Lista de venda com seus itens
    */
    void venda(Lista<Fornecedor> *e, Lista<Venda> *v);

    /**
    * @brief        Função que imprime a lista de estoque
    * @param[inout] *e Lista de Fornecedores do cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número do fornecedor selecionada
    */
    int impPrListaEstoque(Lista<Fornecedor> *e, bool pausa = true);

#endif