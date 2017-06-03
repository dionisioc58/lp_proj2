/**
 * @file	fornecedor.cpp
 * @brief	Implementação da classe Fornecedor
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "fornecedor.h"

/**
* @details O valor de RSocial e CNPJ são inicializados com vazio
*/
Fornecedor::Fornecedor() {
    RSocial = "";
    CNPJ = "";
    produtos = new Lista<Produto>();
}
/**
* @details Destrutor padrão
*/
Fornecedor::~Fornecedor() {
    //if(produtos->getProximo())
//        delete produtos;
}

/**
* @return RSocial do Fornecedor
*/
string Fornecedor::getRSocial() {
    return RSocial;
}

/**
* @details O método modifica o CNPJ do Fornecedor
* @param   n RSocial
*/
void Fornecedor::setRSocial(string n) {
    RSocial = n;
}

/**
* @return CNPJ do Fornecedor
*/
string Fornecedor::getCNPJ() {
    return CNPJ;
}

/**
* @details O método modifica o CNPJ do Fornecedor
* @param   n RSocial
*/
void Fornecedor::setCNPJ(string n) {
    CNPJ = n;
}

/**
* @return Quantidade de alunos
*/
int Fornecedor::getQtde() {
    return produtos->getTamanho();
}

/**
* @return A lista com os produtos da Fornecedor
*/
Lista<Produto> *Fornecedor::getProdutos() {
    return produtos;
}

/**
* @details O método modifica todos os produtos da Fornecedor
* @param   *f Ponteiro para a lista de produtos
*/
void Fornecedor::setProdutos(Lista<Produto> *f) {
    while(produtos->getTamanho() > 0)
        produtos->RemovePos(0);

    int qtde = f->getTamanho();
    for(int i = 0; i < qtde; i++) {
        f = f->getProximo();
        produtos->Insere((Produto)f->getValor());
    }
}

/**
* @details O método modifica adiciona um produto
* @param   f Produto à incluir
* @return  True se adicionou
*/
bool Fornecedor::addProduto(Produto f) {
    if(pertenceFornecedor(f.getcb())) 
        return false;

    produtos->Insere(f);
    
    return true;
}

/**
* @details O método remove um produto
* @param   f Número zero-based do produto na lista de produtos
* @return  True se conseguiu remover
*/
bool Fornecedor::delProduto(int f) {
    if((f < 0) || (f >= produtos->getTamanho()))
        return false;

    produtos->RemovePos(f);
    
    return true;
}

/**
* @details O método verifica se um RSocial pertence à lista de produtos
* @param   n Código do produto à procurar
* @return  True se pertence ao quadro de produtos
*/
bool Fornecedor::pertenceFornecedor(string n) {
    Lista<Produto> *tmp = produtos->getProximo();
    int qtde = produtos->getTamanho();
    for(int i = 0; i < qtde; i++) {
        if(produtos->getValor().getcb() == n)
            return true;
        tmp = tmp->getProximo();
    }
    return false;
}

/**
* @return String com os dados para exportação CSV
*/
string Fornecedor::exportar() {
    return "fornec;" + RSocial + ";" + CNPJ;
}

/** 
* @details O operador é sobrecarregado para representar o Fornecedor
* @param	a Referência para o objeto Fornecedor a ser comparado
* @return	True se > que 'p'
*/
bool Fornecedor::operator>(Fornecedor &p) {
    if(RSocial > p.getRSocial())
        return true;
    return false;
}

/** @brief Sobrecarga do operador de comparação > */
bool Fornecedor::operator!=(Fornecedor &f) {
    if(CNPJ == f.getCNPJ())
        return false;
    return true;
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Fornecedor &e) {
	os << "R. Social: " << e.RSocial << "\t | produtos: " << e.produtos->getTamanho();
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Fornecedor &e) {
	is >> e.RSocial;
	return is;
}