/**
 * @file	fornecedor.h
 * @brief	Definição da classe Fornecedor
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using std::string;
using std::endl;

#include "produto.h"
#include "subproduto.h"
#include "lista.h"

    

/**
    * @class   Fornecedor fornecedor.h
    * @brief   Classe que representa um Fornecedor
    * @details Os atributos da QLeveTudo são: RSocial, CNPJ
    */  
    class Fornecedor {
        private:
            string RSocial;                                     /**< Razao social */
            string CNPJ;                                        /**< CNPJ */
            Lista<Produto*> *produtos;                          /**< Lista de produtos duplamente ligada */
    public:
        Fornecedor();                                           /**< Construtor padrão */
        ~Fornecedor();                                          /**< Destrutor padrão */
        
        string getRSocial();                                    /**< Retorna o RSocial */
        void setRSocial(string n);                              /**< Modifica o RSocial */

        string getCNPJ();                                       /**< Retorna o CNPJ */
        void setCNPJ(string c);                                 /**< Modifica o CNPJ */
        
        int getQtde();                                          /**< Retorna a quantidade de Produtos */
        
        Lista<Produto*> *getProdutos();                          /**< Retorna a lista de Produtos */
        void setProdutos(Lista<Produto*> *p);                    /**< Modifica a lista de Produtos */
        
        bool addProduto(Produto *p);                             /**< Adiciona um Produto */
        bool delProduto(int p);                                 /**< Remove um Produto */
        
        bool pertenceFornecedor(string n);                      /**< Verifica se um codigo de barra pertence à lista de Produto */
        
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        bool operator>(Fornecedor &p);                          /** @brief Sobrecarga do operador de comparação > */
        bool operator!=(Fornecedor &f);                         /** @brief Sobrecarga do operador de comparação != */
		friend ostream& operator<<(ostream& os, Fornecedor &f); /** @brief Sobrecarga do operador de extração em stream */
		friend istream& operator>>(istream& is, Fornecedor &f); /** @brief Sobrecarga do operador de inserção de stream */
    };

#endif