/**
 * @file	loja.cpp
 * @brief	Implementação da classe Loja
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "loja.h"

/**
* @details São alocadas as listas
*/
Loja::Loja() {
    estoque = new Lista<Produto>();
    fornecedores = new Lista<Fornecedor>();
}
/**
* @details Destrutor padrão
*/
Loja::~Loja() {
    //if(produtos->getProximo())
        delete estoque;
        delete fornecedores;
}

/**
* @details O método modifica adiciona um produto
* @param   f Produto à incluir
* @return  True se adicionou
*/
bool Loja::addProduto(Produto f) {
    if(pertenceFornecedor(f.getCb())) 
        return false;

    produtos->Insere(f);
    
    return true;
}

/**
* @details O método remove um produto
* @param   f Número zero-based do produto na lista de produtos
* @return  True se conseguiu remover
*/
bool LOja::delProduto(int f) {
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
bool Loja::pertenceFornecedor(string n) {
    Lista<Produto> *tmp = produtos->getProximo();
    int qtde = produtos->getTamanho();
    for(int i = 0; i < qtde; i++) {
        if(produtos->getValor().getCb() == n)
            return true;
        tmp = tmp->getProximo();
    }
    return false;
}