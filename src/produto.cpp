/**
 * @file	produto.cpp
 * @brief	Implementacao dos métodos da classe Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"
#include "fornecedor.h"

/**
* @details Os valores de cb, descricao, tipo, preco e qntd são inicializados com vazio
*/
Produto::Produto() {
    cb = "";
    descricao = "";
    tipo = "";
    preco = 0.00;
    qntd = 0;
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
string Produto::getCb() {
    return cb;
}

/**
* @details O método modifica o cb do Produto
* @param   n cb
*/
void Produto::setCb(string r) {
    cb = r;
}

/**
* @return Matrícula do Produto
*/
string Produto::getDescricao() {
    return descricao;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void Produto::setDescricao(string c) {
    descricao = c;
}

/**
* @return Matrícula do Produto
*/
string Produto::getTipo() {
    return tipo;
}

/**
* @details O método modifica a matrícula do Produto
* @param   n descricao
*/
void Produto::setTipo(string t) {
    tipo = t;
}

/**
* @return Fornecedor do Produto
*/
//Fornecedor Produto::getFornecedor() {
//    return fornecedor;
//}

/**
* @details O método modifica o fornecedor do Produto
* @param   f fornecedor
*/
//void Produto::setFornecedor(Fornecedor f) {
//    fornecedor = f;
//}

/**
* @return Preco do Produto
*/
double Produto::getPreco() {
    return preco;
}

/**
* @details O método modifica o preco do Produto
* @param   p preco
*/
void Produto::setPreco(double p) {
    preco = p;
}

/**
* @return quantidade do Produto
*/
int Produto::getQntd() {
    return qntd;
}

/**
* @details O método modifica a quantidade do Produto
* @param   q quantidade
*/
void Produto::setQntd(int q) {
    qntd = q;
}

/**
* @return String com os dados para exportação CSV
*/
string Produto::exportar() {
    stringstream ss;
    ss << "produto;" << cb << ";" << descricao << ";" << tipo << ";" << preco << ";" << qntd;
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
    if(preco > p.getPreco())
        return true;
    return false;
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
    os << "Prec.: " << p.preco << "\t| ";
    os << "Qntd.: " << p.qntd;
    
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

    getline(is, lido);
    p.qntd = stoi(lido);

    return is;
}