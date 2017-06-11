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
*          e a lista de produtos é inicializada
*/
Fornecedor::Fornecedor() {
    RSocial = "";
    CNPJ = "";
    produtos = new Lista<Produto*>();
}
/**
* @details Destrutor padrão
*/
Fornecedor::~Fornecedor() {
    while(getQtde() > 0)
        delProduto(0);
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
* @return Quantidade de produtos
*/
int Fornecedor::getQtde() {
    return produtos->getTamanho();
}

/**
* @return A lista com os produtos da Fornecedor
*/
Lista<Produto*> *Fornecedor::getProdutos() {
    return produtos;
}

/**
* @details O método modifica todos os produtos do Fornecedor
* @param   *f Ponteiro para a lista de produtos
*/
void Fornecedor::setProdutos(Lista<Produto*> *f) {
    while(produtos->getTamanho() > 0)
        produtos->RemovePos(0);

    int qtde = f->getTamanho();
    for(int i = 0; i < qtde; i++) {
        f = f->getProximo();
        produtos->Insere(*f->getValor());
    }
}

/**
* @details O método adiciona um produto
* @param   f Produto à incluir
* @return  True se adicionou
*/
bool Fornecedor::addProduto(Produto *f) {
    if(pertenceFornecedor(f->getCb())) 
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
    Lista<Produto*> *tmp = produtos->getProximo();
    int qtde = produtos->getTamanho();
    for(int i = 0; i < qtde; i++) {
        Produto *p = *tmp->getValor();
        if(p->getCb() == n)
            return true;
        tmp = tmp->getProximo();
    }
    return false;
}

/**
* @return String com os dados para exportação CSV
*/
string Fornecedor::exportar() {
    string ret = "fornec;" + RSocial + ";" + CNPJ + "\n";

    Lista<Produto*> *aa = produtos;
    int tam = aa->getTamanho();
    for(int j = 0; j < tam; j++) {            
        Produto *p = dynamic_cast<Produto*>(*aa->Posiciona(j));
        string tipo_m = p->getTipo();
        minusculas(tipo_m);
        if(tipo_m == "bebida")
            ret += dynamic_cast<Bebida*>(p)->exportar() + "\n";
        else if(tipo_m == "fruta")
            ret += dynamic_cast<Fruta*>(p)->exportar() + "\n";
        else if(tipo_m == "doce")
            ret += dynamic_cast<Doce*>(p)->exportar() + "\n";
        else if(tipo_m == "salgado")
            ret += dynamic_cast<Salgado*>(p)->exportar() + "\n";
        else if(tipo_m == "cd")
            ret += dynamic_cast<CD*>(p)->exportar() + "\n";
        else if(tipo_m == "dvd")
            ret += dynamic_cast<DVD*>(p)->exportar() + "\n";
        else if(tipo_m == "livro")
            ret += dynamic_cast<Livro*>(p)->exportar() + "\n";
        else
            ret += p->exportar() + "\n";
    }
    return ret;
}

/** 
* @details O operador é sobrecarregado para representar o Fornecedor
* @param	p Referência para o objeto Fornecedor a ser comparado
* @return	True se > que 'p'
*/
bool Fornecedor::operator>(Fornecedor &p) {
    if(RSocial > p.getRSocial())
        return true;
    return false;
}

/** 
* @details  O operador é sobrecarregado para representar o Fornecedor
* @param	f Referência para o objeto Fornecedor a ser comparado
* @return	True se != que 'f'
*/
bool Fornecedor::operator!=(Fornecedor &f) {
    if(CNPJ == f.getCNPJ())
        return false;
    return true;
}

/** 
* @details  O operador é sobrecarregado para representar o Fornecedor e 
*           a quantidade de seus produtos
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Fornecedor &f) {
	os << "R. Social: " << f.RSocial << "\t | produtos: " << f.produtos->getTamanho();
	return os;
}

/** 
* @details  O operador é sobrecarregado para representar o Fornecedor
* @param[in]	    is Referência para stream de entrada
* @param[in]    f Referência para o objeto Fornecedor a ser criado com base nos 
*			    valores fornecidos
* @return	    Referência para stream de entrada
*/
istream& operator>>(istream& is, Fornecedor &f) {
	string lido;
    getline(is, f.RSocial, ';');
    if(f.RSocial == "\n")
        return is;
    getline(is, f.CNPJ);

    return is;
}