/**
 * @file	fornecedor.cpp
 * @brief	Implementação da classe Fornecedor
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "fornecedor.h"

/**
* @details O valor de nome é inicializados com vazio
*		   e a quantidade com zero
*/
Fornecedor::Fornecedor() {
    nome = "";
    produtos = new Lista<Produto>();
}
/**
* @details Destrutor padrão
*/
Fornecedor::~Fornecedor() {
    //if(produtos->getProximo())
        delete produtos;
}

/**
* @return Nome da Fornecedor
*/
string Fornecedor::getNome() {
    return nome;
}

/**
* @details O método modifica o nome da Fornecedor
* @param   n Nome
*/
void Fornecedor::setNome(string n) {
    nome = n;
}

/**
* @return Quantidade de produtos
*/
int Fornecedor::getQtde() {
    return produtos->getTamanho();
}

/**
* @return Média das notas dos produtos
*/
float Fornecedor::getMedia() {
    float media = 0;
    int qtde = produtos->getTamanho();
    if(qtde == 0)
        return qtde;

    Lista<Produto> *tmp = produtos->getProximo();
    for(int i = 0; i < qtde; i++) {
        media += tmp->getValor().getNota();
        tmp = tmp->getProximo();
    }
    
    return (media / qtde);
}

/**
* @return A lista com os produtos da Fornecedor
*/
Lista<Produto> *Fornecedor::getprodutos() {
    return produtos;
}

/**
* @details O método modifica todos os produtos da Fornecedor
* @param   *f Ponteiro para a lista de produtos
*/
void Fornecedor::setprodutos(Lista<Produto> *f) {
    while(produtos->getTamanho() > 0)
        produtos->RemovePos(0);

    int qtde = f->getTamanho();
    for(int i = 0; i < qtde; i++) {
        f = f->getProximo();
        produtos->Insere((Aluno)f->getValor());
    }
}

/**
* @details O método modifica adiciona um aluno
* @param   f Aluno à incluir
* @return  True se adicionou
*/
bool Fornecedor::addAluno(Aluno f) {
    if(Fornecedor(f.getMatricula())) 
        return false;

    produtos->Insere(f);
    
    return true;
}

/**
* @details O método remove um aluno
* @param   f Número zero-based do aluno na lista de produtos
* @return  True se conseguiu remover
*/
bool Fornecedor::delAluno(int f) {
    if((f < 0) || (f >= produtos->getTamanho()))
        return false;

    produtos->RemovePos(f);
    
    return true;
}

/**
* @details O método verifica se um nome pertence à lista de produtos
* @param   n Matrícula do aluno à procurar
* @return  True se pertence ao quadro de produtos
*/
bool Fornecedor::Fornecedor(string n) {
    Lista<Produto> *tmp = produtos->getProximo();
    int qtde = produtos->getTamanho();
    for(int i = 0; i < qtde; i++) {
        if(produtos->getValor().getMatricula() == n)
            return true;
        tmp = tmp->getProximo();
    }
    return false;
}

/**
* @return String com os dados para exportação CSV
*/
string Fornecedor::exportar() {
    return "Fornecedor;" + nome;
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Fornecedor &e) {
	os << "Nome: " << e.nome << "\t | produtos: " << e.produtos->getTamanho() << "\t | Média: " << e.getMedia();
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Fornecedor &e) {
	is >> e.nome;
	return is;
}