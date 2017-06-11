/**
 * @file	venda.h
 * @brief	Definição da classe Venda
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::ostream;
using std::istream;
using std::stringstream;

#include "produto.h"

    /**
    * @class   Venda venda.h
    * @brief   Classe que representa uma venda
    * @details Os atributos de uma venda são: produto e qtde
    */  
    class Venda {
    protected:
        Produto *produto;                                     /**< Produo */
        int qtde;                                             /**< Quantidade */
    public:
        Venda();                                              /**< Construtor padrão */
        ~Venda();                                             /**< Destrutor padrão */
        
        Produto *getProduto();                                /**< Retorna o produto */
        void setProduto(Produto *p);                          /**< Modifica o produto */

        int getQtde();                                        /**< Retorna a quantidade */
        void setQtde(int q);                                  /**< Modifica a quantidade */
                
        bool operator>(Venda &v);                             /** @brief Sobrecarga do operador de comparação > */
        bool operator!=(Venda &v);                            /** @brief Sobrecarga do operador de comparação != */
        friend ostream& operator<<(ostream& os, Venda &v);    /** @brief Sobrecarga do operador de extração em stream */
    };

#endif