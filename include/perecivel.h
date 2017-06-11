/**
 * @file	perecivel.h
 * @brief	Definição da classe Perecivel
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef PERECIVEL_H
#define PERECIVEL_H

/**
* @class   Perecivel produto.h
* @brief   Classe que representa um produto perecivel
* @details Os atributos de um perecivel são: validade
*/  
class Perecivel {
protected:
    string validade;                                        /**< Data de validade */
public:
    string getValidade() {                                  /**< Retorna a data de validade */
        return validade;
    }
    void setValidade(string v) {                            /**< Modifica a data de validade */
        validade = v;
    }
    friend istream& operator>>(istream& is, Perecivel &p){  /** @brief Sobrecarga do operador de inserção de stream */
        getline(is, p.validade, ';');
        return is;
    }
};

#endif