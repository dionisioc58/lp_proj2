/**
 * @file	loja.h
 * @brief	Definição da classe Loja
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef LOJA_H
#define LOJA_H

#include <iostream>
#include <ctime>
#include <string>
using std::string;
using std::endl;

#include "produto.h"
#include "subproduto.h"
#include "lista.h"
#include "fornecedor.h"
    

/**
    * @class   Loja Loja.h
    * @brief   Classe que representa um Loja
    * @details Os atributos da QLeveTudo são: estoque, fornecedores
    */  
    class Loja {
        private:
            Lista<Produto> *estoque;         /**< Cria uma lista de produtos duplamente ligada vazia */
            Lista<Fornecedor> *fornecedores;      /**< Cria uma lista de fornecedores duplamente ligada vazia */
        public:
            Loja();                                       /**< Construtor padrão */
            ~Loja();                                      /**< Destrutor padrão */

            bool addProduto(Produto p);                             /**< Adiciona um Produto */
            bool delProduto(int p);                               /**< Remove um Produto */

            bool addFornecedor(Fornecedor f);                             /**< Adiciona um Fornecedor */
            bool delFornecedor(int f);                               /**< Remove um Fornecedor */

            Lista<Produto> *getProdutos();                          /**< Retorna a lista de Produtos */
            void setProdutos(Lista<Produto> *p);                    /**< Modifica a lista de Produtos */

            Lista<Fornecedor> *getFornecedores();                        /**< Retorna a lista de Fornecedores */
            void setFornecedores(Lista<Fornecedor> *f);                 /**< Modifica a lista de Fornecedores */

            bool pertenceFornecedor(string n);                       /**< Verifica se um codigo de barra pertence à lista de Produto */
            int getQtde();                                      /**< Retorna a quantidade de Produtos */
            

            string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
		    friend ostream& operator<<(ostream& os, Fornecedor &f);  /** @brief Sobrecarga do operador de inserção em stream */
		    friend istream& operator>>(istream& is, Fornecedor &f);  /** @brief Sobrecarga do operador de extração de stream */
        
    };

#endif