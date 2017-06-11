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
* @param   *p Produto
*/
void Venda::setProduto(Produto *p) {
    produto = p;
}

/**
* @return Quantidade
*/
int Venda::getQtde() {
    return qtde;
}

/**
* @details O método modifica a quantidade
* @param   q Quantidade
*/
void Venda::setQtde(int q) {
    qtde = q;
}

/** 
* @details O operador é sobrecarregado para representar a Venda
* @param	v Referência para o objeto Venda a ser comparado
* @return	True se > que 'v'
*/
bool Venda::operator>(Venda &v) {
    if(produto->getCb() > v.getProduto()->getCb())
        return true;
    return false;
}

/** 
* @details  O operador é sobrecarregado para representar a venda
* @param	v Referência para o objeto venda a ser comparado
* @return	True se != de 'v'
*/
bool Venda::operator!=(Venda &v) {
    if(produto->getCb() == v.getProduto()->getCb())
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar a venda
* @param	os Referência para stream de saída
* @param	v Referência para o objeto venda a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Venda &v) {
	os << v.produto->getCb() << string(10-v.produto->getCb().length(), ' ') << "\t| ";
	os << v.produto->getDescricao() << string(30-v.produto->getDescricao().length(), ' ') << "\t|";
    os << v.qtde << "\t|";
    os << v.produto->getPreco() * v.qtde;
    
    return os;
}