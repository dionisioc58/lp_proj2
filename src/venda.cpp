/**
 * @file	venda.cpp
 * @brief	Implementacao dos métodos da classe Venda
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "venda.h"

/**
* @details O valor da qtde é inicializado
*/
Venda::Venda() {
    qtde = 0;
}

/**
* @details Destrutor padrão
*/
Venda::~Venda() {
    //VAZIO
}

/**
* @return Produto
*/
Produto *Venda::getProduto() {
    return produto;
}

/**
* @details O método modifica o produto
* @param   q Produto
*/
void Venda::setProduto(Produto *p) {
    produto = p;
}

/**
* @return Quantidade da Venda
*/
int Venda::getQtde() {
    return qtde;
}

/**
* @details O método modifica a quantidade da Venda
* @param   q Quantidade
*/
void Venda::setQtde(int q) {
    qtde = q;
}

/** 
* @details O operador é sobrecarregado para representar a Venda
* @param	a Referência para o objeto Venda a ser comparado
* @return	True se > que 'a'
*/
bool Venda::operator>(Venda &v) {
    if(produto->getCb() > v.getProduto()->getCb())
        return true;
    return false;
}

/** @brief Sobrecarga do operador de comparação > */
bool Venda::operator!=(Venda &v) {
    if(produto->getCb() == v.getProduto()->getCb())
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar o Produto
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Produto a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Venda &v) {
	os << v.produto->getCb() << string(10-v.produto->getCb().length(), ' ') << "\t| ";
	os << v.produto->getDescricao() << string(30-v.produto->getDescricao().length(), ' ') << "\t|";
    os << v.qtde << "\t|";
    os << v.produto->getPreco() * v.qtde;
    
    return os;
}