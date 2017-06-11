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
    #include "menu.h"

/**
* @brief        Função que coleta os dados para o cadastro de um fornecedor
* @return       Fornecedor coletado
*/
Fornecedor *inputFornecedor();

/**
* @brief        Função que coleta os dados para cadastro de um produto
* @param[in]    *f Fornecedor que vai receber o produto
* @return       Produto coletado
*/
void inputProduto(Fornecedor *f);

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
* @brief        Função que adiciona um produto à um fornecedor (apresenta escolha)
* @param[in]    *e Lista de fornecedores do cadastro
*/
void addPr(Lista<Fornecedor> *e);

/**
* @brief        Função que remove um produto de um fornecedor (apresenta escolha)
* @param[in]    *e Lista de fornecedores do cadastro
*/
void delPr(Lista<Fornecedor> *e);

/**
* @brief        Função que edita um produto de um Fornecedor (apresenta escolha)
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void editPr(Lista<Fornecedor> *e);

/**
* @brief        Função que imprime os objetos na lista
* @param[in]    *e Lista de objetos
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
template<typename T>
void impLista(Lista<T> *e, bool pausa = true);

/**
* @brief        Função que imprime a lista de produtos de um ou todos
                os fornecedores do cadastro
* @param[in]    *e Lista de fornecedores do cadastro
* @param[in]    all "true" imprime todos os produtos de todos os fornecedores
                "false" imprime apenas os produtos de um fornecedor (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionado
*/
int impPr(Lista<Fornecedor> *e, bool all = true, bool pausa = true);

/**
* @brief        Função que imprime um produto
* @param[in]    *p Produto
* @param[in]    detalhes True para apresentar os detalhes do produto
*/
void imprimir(Produto *p, bool detalhes = true);

/**
* @brief        Função que imprime a lista de produtos
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    filtro Filtro de listagem (0 = sem filtro, 1 = filtrar por tipo, 
*               2 = filtrar por codigo, 3 = exibir menos detalhes)
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
* @brief        Função que retorna um produto, dada uma determinada posicao na lista numerada
* @param[in]    *e Lista de fornecedores e seus produtos
* @param[in]    pos Posição do produto na lista numerada
* @return       Produto selecionado
*/
Produto *capturaProduto(Lista<Fornecedor> *e, int pos);

/**
* @brief        Função que exibe opções para realizar uma venda
* @param[in]    *e Lista de fornecedores com seus produtos
* @param[in]    *v Lista de venda com seus itens
*/
void venda(Lista<Fornecedor> *e, Lista<Venda> *v);

/**
* @brief        Função que adiciona um produto à venda
* @param[in]    *e Lista de fornecedores com seus produtos
* @param[in]    *v Lista de venda com seus itens
*/
void venda_add(Lista<Fornecedor> *e, Lista<Venda> *v);

/**
* @brief        Função que exibe os produtos adicionados à venda
* @param[in]    pausa True para manter a tela congelada após a impressão
* @param[in]    *v Lista de venda com seus itens
*/
void venda_lis(Lista<Venda> *v, bool pausa = true);

/**
* @brief        Função que remove um produto da venda
* @param[in]    *v Lista de venda com seus itens
*/
void venda_del(Lista<Venda> *v);

/**
* @brief        Função para encerrar a venda
* @param[in]    *v Lista de venda com seus itens
*/
void venda_enc(Lista<Venda> *v);

/**
* @brief        Função que imprime a lista de estoque
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPrListaEstoque(Lista<Fornecedor> *e, bool pausa = true);

#endif