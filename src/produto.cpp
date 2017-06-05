/**
 * @file	produto.cpp
 * @brief	Implementacao dos métodos da classe Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"

/**
* @details Os valores de cb, descricao, tipo, preco e qntd são inicializados com vazio
*/
Produto::Produto() {
    cb = "";
    descricao = "";
    tipo = "";
    preco = 0.00;
}

/**
* @details Destrutor padrão
*/
Produto::~Produto() {
    //VAZIO
}

/**
* @return cb do Produto
*/
string Produto::getcb() {
    return cb;
}

/**
* @details O método modifica o cb do Produto
* @param   n cb
*/
void Produto::setcb(string r) {
    cb = r;
}

/**
* @return Matrícula do Produto
*/
string Produto::getdescricao() {
    return descricao;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void Produto::setdescricao(string c) {
    descricao = c;
}

/**
* @return Matrícula do Produto
*/
string Produto::gettipo() {
    return tipo;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void Produto::settipo(string t) {
    tipo = t;
}

/**
* @return Preco do Produto
*/
double Produto::getpreco() {
    return preco;
}

/**
* @details O método modifica o preco do Produto
* @param   p preco
*/
void Produto::setpreco(double p) {
    preco = p;
}

/**
* @return Quantidade do Produto
*/
int Produto::getQtde() {
    return qtde;
}

/**
* @details O método modifica a quantidade do Produto
* @param   q Quantidade
*/
void Produto::setQtde(int q) {
    qtde = q;
}

/**
* @details O método retorna o código, a descrição e a quantidade do Produto
*/
string Produto::getEstoque() {
    stringstream ss;
    ss << cb << "\t" << descricao << "\t" << qtde;
    string ret = ss.str();
    return ret;
}

/**
* @return String com os dados para exportação CSV
*/
string Produto::exportar() {
    stringstream ss;
    ss << "produt;" << cb << ";" << descricao << ";" << tipo << ";" << preco;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/** 
* @details O operador é sobrecarregado para representar o Produto
* @param	a Referência para o objeto Produto a ser comparado
* @return	True se > que 'a'
*/
bool Produto::operator>(Produto &p) {
    if(preco > p.getpreco())
        return true;
    return false;
}

/** @brief Sobrecarga do operador de comparação > */
bool Produto::operator!=(Produto &p) {
    if(cb == p.getcb())
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar o Produto
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Produto a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Produto &p) {
	os <<  p.cb << "\t| ";
	os << "Desc.: " << p.descricao << "\t| ";
    os << "Tipo.: " << p.tipo << "\t| ";
    os << "Prec.: " << p.preco;
    
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	f Referência para o objeto Produto a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Produto &p) {
    string lido;
    getline(is, p.cb, ';');
    if(p.cb == "\n")
        return is;
    getline(is, p.descricao, ';');

    getline(is, p.tipo, ';');

    getline(is, lido, ';');
    p.preco = stod(lido);

    return is;
}