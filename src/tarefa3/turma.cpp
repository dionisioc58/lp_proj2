/**
 * @file	turma.cpp
 * @brief	Implementação da classe Turma
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "tarefa3/turma.h"

/**
* @details O valor de nome é inicializados com vazio
*		   e a quantidade com zero
*/
Turma::Turma() {
    nome = "";
    alunos = new Lista<Aluno>();
}
/**
* @details Destrutor padrão
*/
Turma::~Turma() {
    //if(alunos->getProximo())
        delete alunos;
}

/**
* @return Nome da Turma
*/
string Turma::getNome() {
    return nome;
}

/**
* @details O método modifica o nome da Turma
* @param   n Nome
*/
void Turma::setNome(string n) {
    nome = n;
}

/**
* @return Quantidade de alunos
*/
int Turma::getQtde() {
    return alunos->getTamanho();
}

/**
* @return Média das notas dos alunos
*/
float Turma::getMedia() {
    float media = 0;
    int qtde = alunos->getTamanho();
    if(qtde == 0)
        return qtde;

    Lista<Aluno> *tmp = alunos->getProximo();
    for(int i = 0; i < qtde; i++) {
        media += tmp->getValor().getNota();
        tmp = tmp->getProximo();
    }
    
    return (media / qtde);
}

/**
* @return A lista com os alunos da Turma
*/
Lista<Aluno> *Turma::getAlunos() {
    return alunos;
}

/**
* @details O método modifica todos os alunos da Turma
* @param   *f Ponteiro para a lista de alunos
*/
void Turma::setAlunos(Lista<Aluno> *f) {
    while(alunos->getTamanho() > 0)
        alunos->RemovePos(0);

    int qtde = f->getTamanho();
    for(int i = 0; i < qtde; i++) {
        f = f->getProximo();
        alunos->Insere((Aluno)f->getValor());
    }
}

/**
* @details O método modifica adiciona um aluno
* @param   f Aluno à incluir
* @return  True se adicionou
*/
bool Turma::addAluno(Aluno f) {
    if(pertenceTurma(f.getMatricula())) 
        return false;

    alunos->Insere(f);
    
    return true;
}

/**
* @details O método remove um aluno
* @param   f Número zero-based do aluno na lista de alunos
* @return  True se conseguiu remover
*/
bool Turma::delAluno(int f) {
    if((f < 0) || (f >= alunos->getTamanho()))
        return false;

    alunos->RemovePos(f);
    
    return true;
}

/**
* @details O método verifica se um nome pertence à lista de alunos
* @param   n Matrícula do aluno à procurar
* @return  True se pertence ao quadro de alunos
*/
bool Turma::pertenceTurma(string n) {
    Lista<Aluno> *tmp = alunos->getProximo();
    int qtde = alunos->getTamanho();
    for(int i = 0; i < qtde; i++) {
        if(alunos->getValor().getMatricula() == n)
            return true;
        tmp = tmp->getProximo();
    }
    return false;
}

/**
* @return String com os dados para exportação CSV
*/
string Turma::exportar() {
    return "turma;" + nome;
}

/** 
* @details O operador é sobrecarregado para representar a Turma e seus alunos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Turma a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Turma &e) {
	os << "Nome: " << e.nome << "\t | Alunos: " << e.alunos->getTamanho() << "\t | Média: " << e.getMedia();
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Turma a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Turma &e) {
	is >> e.nome;
	return is;
}