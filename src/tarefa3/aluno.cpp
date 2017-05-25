/**
 * @file	aluno.cpp
 * @brief	Implementacao dos métodos da classe Aluno
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "tarefa3/aluno.h"

/**
* @details Os valores de nome e matricula são inicializados com vazio,
*          faltas e nota com zero
*/
Aluno::Aluno() {
    nome = "";
    matricula = "";
    faltas = 0;
    nota = 0;
}

/**
* @details Destrutor padrão
*/
Aluno::~Aluno() {
    //VAZIO
}

/**
* @return Nome do aluno
*/
string Aluno::getNome() {
    return nome;
}

/**
* @details O método modifica o nome do Aluno
* @param   n Nome
*/
void Aluno::setNome(string n) {
    nome = n;
}

/**
* @return Matrícula do aluno
*/
string Aluno::getMatricula() {
    return matricula;
}

/**
* @details O método modifica a matrícula do Aluno
* @param   n Matricula
*/
void Aluno::setMatricula(string n) {
    matricula = n;
}

/**
* @return Faltas do aluno
*/
int Aluno::getFaltas() {
    return faltas;
}

/**
* @details O método modifica a quantidade de faltas do aluno
* @param   a Faltas
*/
void Aluno::setFaltas(int a) {
    faltas = a;
}

/**
* @return Nota do aluno
*/
float Aluno::getNota() {
    return nota;
}

/**
* @details O método modifica a nota do aluno
* @param   s Nota
*/
void Aluno::setNota(float s) {
    nota = s;
}

/**
* @return String com os dados para exportação CSV
*/
string Aluno::exportar() {
    stringstream ss;
    ss << "aluno;" << nome << ";" << matricula << ";" << faltas << ";" << nota;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/** 
* @details O operador é sobrecarregado para representar o aluno
* @param	a Referência para o objeto aluno a ser comparado
* @return	True se > que 'a'
*/
bool Aluno::operator>(Aluno &a) {
    if(matricula > a.getMatricula())
        return true;
    return false;
}

/** 
* @details O operador é sobrecarregado para representar o aluno
* @param	os Referência para stream de saída
* @param	f Referência para o objeto aluno a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Aluno &f) {
	os <<  f.nome << "\t| ";
	os << "Mat.: " << f.matricula << "\t| ";
    os << "Falt.: " << f.faltas << "\t| ";
    os << "Not.: " << f.nota;
    
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	f Referência para o objeto aluno a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Aluno &f) {
    string lido;
    getline(is, f.nome, ';');
    if(f.nome == "\n")
        return is;
    getline(is, f.matricula, ';');

    getline(is, lido, ';');
    f.faltas = stoi(lido);

    getline(is, lido);
    f.nota = stof(lido);

    return is;
}