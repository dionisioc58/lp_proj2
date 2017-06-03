/**
 * @file	item.h
 * @brief	Definição da classe Item
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::ostream;
using std::istream;
using std::stringstream;
#include <ctime>
#include "fornecedor.h"
#include "produto.h"
    
    /**
    * @class   Item item.h
    * @brief   Classe que representa um item para o estoque
    * @details Os atributos de um item são: produto, fornecedor, qtde e preco
    */  
    class Item {
    protected:
        Produto produto;        /**< Produto */
        Fornecedor fornecedor;  /**< Fornecedor */
        int qtde;               /**< Quantidade */
        double preco;           /**< Preço */
    public:
        Item();                                              /**< Construtor padrão */
        ~Item();                                             /**< Destrutor padrão */
        
        Produto getProduto();                                /**< Retorna o produto */
        void setProduto(Produto p);                          /**< Modifica o produto */
        
        Fornecedor getFornecedor();                          /**< Retorna o fornecedor */
        void setFornecedor(Fornecedor f);                    /**< Modifica o fornecedor */

        int getQtde();                                       /**< Retorna a quantidade */
        void setQtde(int q);                                 /**< Modifica a quantidade */
        
        double getPreco();                                   /**< Retorna o preco */
        void setPreco(double p);                             /**< Modifica o preco */
                
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        
        friend ostream& operator<<(ostream& os, Item &p);      /** @brief Sobrecarga do operador de inserção em stream */
    };

#endif