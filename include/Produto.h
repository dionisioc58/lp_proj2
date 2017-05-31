/**
 * @file	Produto.h
 * @brief	Definição da classe Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef PRODUTO_H
#define PRODUTO_H

/**
    * @class   Produto Produto.h
    * @brief   Classe que representa um Produto
    * @details Os atributos da QLeveTudo são: cb, descricao
    */  
    class Produto {
        private:
            string cb;         /**< Razao social */
            string descricao;            /**< descricao */
            string tipo;            /**< tipo do produto */
            Fornecedor fornecedor;          /**< fornecedor */
            double preco;           /**< preco */
            int qntd;           /**< quantidade em estoque */

        public:
        Produto();                                                /**< Construtor padrão */
        ~Produto();                                               /**< Destrutor padrão */
        
        string getcb();                                       /**< Retorna a razao social */
        void setcb(string r);                                 /**< Modifica a razao social */
        
        string getdescricao();                                  /**< Retorna o descricao */
        void setdescricao(string c);                            /**< Modifica o descricao */
        
        string gettipo();                                       /**< Retorna a razao social */
        void settipo(string t);                                 /**< Modifica a razao social */
        
        Fornecedor getfornecedor();                                  /**< Retorna o descricao */
        void setfornecedor(Fornecedor f);                            /**< Modifica o descricao */
        
        double getpreco();                                       /**< Retorna a razao social */
        void setpreco(double p);                                 /**< Modifica a razao social */
        
        int getqntd();                                  /**< Retorna o descricao */
        void setqntd(int c);                            /**< Modifica o descricao */
    };

    /**
* @details Os valores de cb e descricao são inicializados com vazio
*/
Produto() {
    cb = "";
    descricao = "";
    tipo = "";
    preco = 0.00;
    qntd = 0;
}

/**
* @details Destrutor padrão
*/
~Produto() {
    //VAZIO
}

/**
* @return cb do Produto
*/
string getcb() {
    return cb;
}

/**
* @details O método modifica o cb do Produto
* @param   n cb
*/
void setcb(string r) {
    cb = r;
}

/**
* @return Matrícula do Produto
*/
string getdescricao() {
    return descricao;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void setdescricao(string c) {
    descricao = c;
}

/**
* @return Matrícula do Produto
*/
string gettipo() {
    return tipo;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void settipo(string t) {
    tipo = t;
}

/**
* @return Matrícula do Produto
*/
Fornecedor getfornecedor() {
    return fornecedor;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void setfornecedor(Fornecedor f) {
    Fornecedor = f;
}

/**
* @return Matrícula do Produto
*/
string getdescricao() {
    return descricao;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void setdescricao(string c) {
    descricao = c;
}

/**
* @return Matrícula do Produto
*/
string getdescricao() {
    return descricao;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void setdescricao(string c) {
    descricao = c;
}

#endif