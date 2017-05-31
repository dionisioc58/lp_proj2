/**
 * @file	Fornecedor.h
 * @brief	Definição da classe Fornecedor
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef FORNECEDOR_H
#define FORNECEDOR_H

/**
    * @class   Fornecedor Fornecedor.h
    * @brief   Classe que representa um Fornecedor
    * @details Os atributos da QLeveTudo são: RSocial, CNPJ
    */  
    class Fornecedor {
        private:
            string RSocial;         /**< Razao social */
            string CNPJ;            /**< CNPJ */
        public:
        Fornecedor();                                                /**< Construtor padrão */
        Fornecedor(string r, string c);                              /**< Construtor parametrizado */
        ~Fornecedor();                                               /**< Destrutor padrão */
        string getRSocial();                                       /**< Retorna a razao social */
        void setRSocial(string r);                                 /**< Modifica a razao social */
        string getCNPJ();                                  /**< Retorna o CNPJ */
        void setCNPJ(string c);                            /**< Modifica o CNPJ */
    };

/**
* @details Os valores de RSocial e CNPJ são inicializados com vazio
*/
Fornecedor() {
    RSocial = "";
    CNPJ = "";
}

/**
* @details Os valores de RSocial e CNPJ são inicializados com vazio
*/
Fornecedor(string r, string c) {
    RSocial = r;
    CNPJ = c;
}

/**
* @details Destrutor padrão
*/
~Fornecedor() {
    //VAZIO
}

/**
* @return RSocial do Fornecedor
*/
string getRSocial() {
    return RSocial;
}

/**
* @details O método modifica o RSocial do Fornecedor
* @param   n RSocial
*/
void setRSocial(string r) {
    RSocial = r;
}

/**
* @return CNPJ do Fornecedor
*/
string getCNPJ() {
    return CNPJ;
}

/**
* @details O método modifica o CNPJ do Fornecedor
* @param   c CNPJ
*/
void setCNPJ(string c) {
    CNPJ = c;
}

#endif