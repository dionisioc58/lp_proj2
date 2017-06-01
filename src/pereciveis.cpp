/**
 * @file	pereciveis.cpp
 * @brief	Implementacao dos métodos das classes derivadas de produto e perecivel
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"
#include "subprodutos.h"

/**
* @details Os valores de acucar e alcool são inicializados com vazio
*/
Bebida::Bebida() {
    acucar = 0;
    alcool = 0.0;
}

/**
* @details Destrutor padrão
*/
Bebida::~Bebida() {
    //VAZIO
}

/**
* @return acucar do Produto
*/
int Bebida::getAcucar() {
    return acucar;
}

/**
* @details O método modifica o aucar do Produto
* @param   ac acucar
*/
void Bebida::setAcucar(int ac) {
    acucar = ac;
}
/**
* @return alcool do Produto
*/
float Bebida::getAlcool() {
    return alcool;
}

/**
* @details O método modifica o alcool do Produto
* @param   al alcool
*/
void Bebida::setAlcool(float al) {
    alcool = al;
}

/**
* @details Os valores de numeros e data de producao são inicializados com vazio
*/
Fruta::Fruta() {
    num = 0;
    dp = "";
}

/**
* @details Destrutor padrão
*/
Fruta::~Fruta() {
    //VAZIO
}

/**
* @return num do Produto
*/
int Fruta::getNum() {
    return num;
}

/**
* @details O método modifica o num do Produto
* @param   n num
*/
void Fruta::setNum(int n) {
    num = n;
}
/**
* @return dp do Produto
*/
string Fruta::getDp() {
    return dp;
}

/**
* @details O método modifica o dp do Produto
* @param   d dp
*/
void Fruta::setAlcool(string d) {
    dp = d;
}

/**
* @details Os valores de acucar,gluten e glicose são inicializados com vazio
*/
Doce::Doce() {
    acucar = 0;
    gluten = false;
    glicose = false;
}

/**
* @details Destrutor padrão
*/
Doce::~Doce() {
    //VAZIO
}

/**
* @return acucar do Produto
*/
int Doce::getAcucar() {
    return acucar;
}

/**
* @details O método modifica o aucar do Produto
* @param   a acucar
*/
void Doce::setAcucar(int a) {
    acucar = a;
}

/**
* @return lactose do Produto
*/
bool Doce::getLactose() {
    return lactose;
}

/**
* @details O método modifica a lactose do Produto
* @param   gc lactose
*/
void Doce::setLactose(bool l) {
    lactose = l;
}
/**
* @return gluten do Produto
*/
bool Doce::getGluten() {
    return gluten;
}

/**
* @details O método modifica o gluten do Produto
* @param   gt gluten
*/
void Doce::setGluten(bool g) {
    gluten = g;
}

/**
* @details Os valores de sodio, gluten e lactose são inicializados com vazio
*/
Salgado::Salgado() {
    sodio = 0;
    gluten = false;
    lactose = false;
}

/**
* @details Destrutor padrão
*/
Salgado::~Salgado() {
    //VAZIO
}

/**
* @return sodio do Produto
*/
int Salgado::getSodio() {
    return sodio;
}

/**
* @details O método modifica o aucar do Produto
* @param   s sodio
*/
void Salgado::setSodio(int s) {
    sodio = s;
}

/**
* @return glicose do Produto
*/
bool Salgado::getLactose() {
    return lactose;
}

/**
* @details O método modifica a lactose do Produto
* @param   l lactose
*/
void Salgado::setLactose(bool l) {
    lactose = l;
}
/**
* @return gluten do Produto
*/
bool Salgado::getGluten() {
    return gluten;
}

/**
* @details O método modifica o gluten do Produto
* @param   g gluten
*/
void Salgado::setGluten(bool g) {
    gluten = g;
}


