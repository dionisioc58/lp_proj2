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
    qtde = 0;
}

/**
* @details Destrutor padrão
*/
Produto::~Produto() {
    //VAZIO
}

/**
* @return Código do Produto
*/
string Produto::getCb() {
    return cb;
}

/**
* @details O método modifica o código do Produto
* @param   r cb
*/
void Produto::setCb(string r) {
    cb = r;
}

/**
* @return Descrição do Produto
*/
string Produto::getDescricao() {
    return descricao;
}

/**
* @details O método modifica a descrição do Produto
* @param   c Descrição
*/
void Produto::setDescricao(string c) {
    descricao = c;
}

/**
* @return Tipo do Produto
*/
string Produto::getTipo() {
    return tipo;
}

/**
* @details O método modifica o tipo do Produto
* @param   t descricao
*/
void Produto::setTipo(string t) {
    tipo = t;
}

/**
* @return Preço do Produto
*/
double Produto::getPreco() {
    return preco;
}

/**
* @details O método modifica o preço do Produto
* @param   p Preço
*/
void Produto::setPreco(double p) {
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
    ss << cb << string(10-cb.length(), ' ') << "\t|" << descricao << string(30-descricao.length(), ' ') << "\t|" << qtde;
    string ret = ss.str();
    return ret;
}

/**
* @return Produto coletado a partir da entrada padrão
*/
void Produto::capturar() {
    cb = recebeString("Digite o código do produto: ");
    cout << "Digite a descrição do produto: ";
    getline(cin, descricao);
    preco = recebeFloat("Digite o preço: ", 0);
    qtde = recebeInt("Digite a quantidade: ", 0);
}

/**
* @return String com os dados para exportação CSV
*/
string Produto::exportar() {
    stringstream ss;
    ss << "produt;" << tipo << ";" << cb << ";" << descricao << ";" << preco << ";" << qtde;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/** 
* @details  O operador é sobrecarregado para representar o Produto
* @param	p Referência para o objeto Produto a ser comparado
* @return	True se > que 'p'
*/
bool Produto::operator>(Produto &p) {
    if(preco > p.getPreco())
        return true;
    return false;
}

/** 
* @details  O operador é sobrecarregado para representar o Produto
* @param	p Referência para o objeto Produto a ser comparado
* @return	True se != de 'p'
*/
bool Produto::operator!=(Produto &p) {
    if(cb == p.getCb())
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar o Produto
* @param	os Referência para stream de saída
* @param	p Referência para o objeto Produto a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Produto &p) {
	os << "Cód. : " << p.getCb() << " - ";
	os << "Desc.: " << p.getDescricao() << " - ";
    os << "Tipo.: " << p.getTipo() << " - ";
    os << "Prec.: " << p.getPreco() << " - ";
    os << "Qtde.: " << p.getQtde() << " - ";
    
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	p Referência para o objeto Produto a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Produto &p) {
    string lido;

    getline(is, p.cb, ';');
    if(p.cb == "\n")
        return is;
    getline(is, p.descricao, ';');

    getline(is, lido, ';');
    if(lido != "")
        p.preco = stod(lido);

    getline(is, lido, ';');
    if(lido != "")
        p.qtde = stoi(lido);

    return is;
}