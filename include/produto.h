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
#include <ctime>
    
    /**
    * @class   Perecivel produto.h
    * @brief   Classe que representa um produto perecivel
    * @details Os atributos de um perecivel são: validade
    */  
    class Perecivel {
    protected:
    public:
    };

    /**
    * @class   Produto Produto.h
    * @brief   Classe que representa um Produto
    * @details Os atributos de um funcionário são: nome, matricula, faltas e nota
    */  
    class Produto {
    protected:
        string cb;         /**< codigo de barras */
        string descricao;            /**< descricao */
        string tipo;            /**< tipo do produto */
        double preco;           /**< preco */
        int qntd;           /**< quantidade em estoque */
    public:
        Produto();                                                /**< Construtor padrão */
        ~Produto();                                               /**< Destrutor padrão */
        
        string getcb();                                       /**< Retorna o codigo de barras */
        void setcb(string r);                                 /**< Modifica o codigo de barras */
        
        string getdescricao();                                  /**< Retorna o descricao */
        void setdescricao(string c);                            /**< Modifica o descricao */
        
        string gettipo();                                       /**< Retorna o tipo */
        void settipo(string t);                                 /**< Modifica o tipo */
        
        double getpreco();                                       /**< Retorna o preco */
        void setpreco(double p);                                 /**< Modifica o preco */
        
        int getqntd();                                  /**< Retorna a quantidade em estoque */
        void setqntd(int c);                            /**< Modifica a quantidade em estoque */
        
        
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        
        bool operator>(Produto &p);                               /** @brief Sobrecarga do operador de comparação > */
        friend ostream& operator<<(ostream& os, Produto &p);      /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Produto &p);      /** @brief Sobrecarga do operador de extração de stream */
    };

#endif