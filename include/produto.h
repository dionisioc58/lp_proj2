/**
 * @file	produto.h
 * @brief	Definição da classe Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::ostream;
using std::istream;
using std::stringstream;
#include "funcoes.h"

    /**
    * @class   Produto produto.h
    * @brief   Classe que representa um Produto
    * @details Os atributos de um funcionário são: nome, matricula, faltas e nota
    */  
    class Produto {
    protected:
        string cb;                                              /**< Código de barras */
        string descricao;                                       /**< Descrição */
        string tipo;                                            /**< Tipo do produto */
        double preco;                                           /**< Preço */
        int qtde;                                               /**< Quantidade */
    public:
        Produto();                                              /**< Construtor padrão */
        virtual ~Produto();                                     /**< Destrutor padrão */
        
        string getCb();                                         /**< Retorna o código de barras */
        void setCb(string r);                                   /**< Modifica o código de barras */
        
        string getDescricao();                                  /**< Retorna a descrição */
        void setDescricao(string c);                            /**< Modifica a descrição */
        
        string getTipo();                                       /**< Retorna o tipo */
        void setTipo(string t);                                 /**< Modifica o tipo */
        
        double getPreco();                                      /**< Retorna o preço */
        void setPreco(double p);                                /**< Modifica o preço */

        int getQtde();                                          /**< Retorna a quantidade */
        void setQtde(int q);                                    /**< Modifica a quantidade */

        string getEstoque();                                    /**< Retorna o código, a descrição e a quantidade */
        void capturar();                                        /**< Coleta os dados a partir da entrada padrão */
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        bool operator>(Produto &p);                             /** @brief Sobrecarga do operador de comparação > */
        bool operator!=(Produto &p);                            /** @brief Sobrecarga do operador de comparação != */
        friend ostream& operator<<(ostream& os, Produto &p);    /** @brief Sobrecarga do operador de extração em stream */
        friend istream& operator>>(istream& is, Produto &p);    /** @brief Sobrecarga do operador de inserção de stream */
    };

#endif