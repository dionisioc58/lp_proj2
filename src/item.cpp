/**
 * @file	item.cpp
 * @brief	Implementacao dos métodos da classe Item
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "item.h"

/**
* @details Os valores de qtde e preco são inicializados com vazio
*/
Item::Item() {
    qtde = 0;
    preco = 0;
}

/**
* @details Destrutor padrão
*/
Item::~Item() {
    //VAZIO
}

/**
* @return Produto
*/
Produto Item::getProduto() {
    return produto;
}

/**
* @details O método modifica o Produto
* @param   p Produto
*/
void Item::setProduto(Produto p) {
    produto = p;
}

/**
* @return Fornecedor
*/
Fornecedor Item::getFornecedor() {
    return fornecedor;
}

/**
* @details O método modifica o Fornecedor
* @param   f Fornecedor
*/
void Item::setFornecedor(Fornecedor f) {
    fornecedor = f;
}

/**
* @return Quantidade do Produto
*/
int Item::getQtde() {
    return qtde;
}

/**
* @details O método modifica a quantidade do item
* @param   q quantidade
*/
void Item::setQtde(int q) {
    qtde = q;
}

/**
* @return Preco do Produto
*/
double Item::getPreco() {
    return preco;
}

/**
* @details O método modifica o preco do item
* @param   p preco
*/
void Item::setPreco(double p) {
    preco = p;
}

/**
* @return String com os dados para exportação CSV
*/
string Item::exportar() {
    stringstream ss;
    ss << "item;" << produto << ";" << fornecedor << ";" << qtde << ";" << preco;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/** 
* @details O operador é sobrecarregado para representar o Item
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Item a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Item &p) {
	os <<  p.produto << "\t| ";
	os << "Forn.: " << p.fornecedor << "\t| ";
    os << "Qtde.: " << p.qtde << "\t| ";
    os << "Prec.: " << p.preco;
    
    return os;
}