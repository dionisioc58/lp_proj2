/**
 * @file	pereciveis.cpp
 * @brief	Implementacao dos métodos das classes derivadas de produto e perecivel
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"
#include "subproduto.h"

/**
* @details Os valores de acucar e alcool são inicializados com vazio
*/
Bebida::Bebida() {
    tipo = "Bebida";
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

string Bebida::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << validade << ";" << acucar << ";" << alcool;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void Bebida::capturar() {
    validade = recebeString("Digite a data de validade (dd/mm/aaaa): ");
    acucar = recebeInt("Digite a quantidade de açúcar: ", 0);
    alcool = recebeFloat("Digite o teor alcóolico: ", 0);
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Bebida &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Val. : " << p.getValidade() << " - ";
    os << "Açúc.: " << p.getAcucar() << " - ";
    os << "Alco.: " << p.getAlcool();
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Bebida &b) {
    string lido;
    
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.validade, ';');
    
    getline(is, lido, ';');
    if(lido != "")
        b.acucar = stoi(lido);
    getline(is, lido);
    if(lido != "")
        b.alcool = stof(lido);
    return is;
}

/**
* @details Os valores de numeros e data de producao são inicializados com vazio
*/
Fruta::Fruta() {
    tipo = "Fruta";
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
void Fruta::setDp(string d) {
    dp = d;
}

string Fruta::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << validade << ";" << num << ";" << dp;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void Fruta::capturar() {
    validade = recebeString("Digite a data de validade (dd/mm/aaaa): ");
    num = recebeInt("Digite o número de frutas: ", 0);    
    dp = recebeString("Digite a data de produção (dd/mm/aaaa): ");
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Fruta &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Val. : " << p.getValidade() << " - ";
    os << "Num. : " << p.getNum() << " - ";
    os << "DtPr.: " << p.getDp();
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Fruta &b) {
    string lido;
    
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.validade, ';');
    
    getline(is, lido, ';');
    if(lido != "")
        b.num = stoi(lido);
    getline(is, b.dp, ';');
    return is;
}

/**
* @details Os valores de acucar,gluten e glicose são inicializados com vazio
*/
Doce::Doce() {
    tipo = "Doce";
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
* @return glicose do Produto
*/
bool Doce::getGlicose() {
    return glicose;
}

/**
* @details O método modifica a glicose do Produto
* @param   gc glicose
*/
void Doce::setGlicose(bool l) {
    glicose = l;
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

string Doce::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << validade << ";" << acucar << ";" << (gluten ? 1 : 0) << ";" << (glicose ? 1 : 0);
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void Doce::capturar() {
    validade = recebeString("Digite a data de validade (dd/mm/aaaa): ");
    acucar = recebeInt("Digite a quantidade de açúcar: ", 0);
    int ints = recebeInt("Tem glúten (1 = sim, 0 = não): ", 0, 1);
    gluten = false;
    if(ints == 1)
        gluten = true;

    ints = recebeInt("Tem glicose (1 = sim, 0 = não): ", 0, 1);
    glicose = false;
    if(ints == 1)
        glicose = true;
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Doce &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Val. : " << p.getValidade() << " - ";
    os << "Açúc.: " << p.getAcucar() << " - ";
    os << "Glút.: " << (p.getGluten() ? "Sim" : "Não") << " - ";
    os << "Glic.: " << (p.getGlicose() ? "Sim" : "Não");
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Doce &b) {
    string lido;
    
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.validade, ';');
    
    getline(is, lido, ';');
    if(lido != "")
        b.acucar = stoi(lido);
    
    b.gluten = false;
    getline(is, lido, ';');
    if(lido == "1")
        b.gluten = true;

    b.glicose = false;
    getline(is, lido, ';');
    if(lido == "1")
        b.glicose = true;
    return is;
}

/**
* @details Os valores de sodio, gluten e lactose são inicializados com vazio
*/
Salgado::Salgado() {
    tipo = "Salgado";
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

string Salgado::exportar() {
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << validade << ";" << sodio << ";" << (gluten ? 1 : 0) << ";" << (lactose ? 1 : 0);
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void Salgado::capturar() {
    validade = recebeString("Digite a data de validade (dd/mm/aaaa): ");
    sodio = recebeInt("Digite a quantidade de sódio: ", 0);
    int ints = recebeInt("Tem glúten (1 = sim, 0 = não): ", 0, 1);
    gluten = false;
    if(ints == 1)
        gluten = true;

    ints = recebeInt("Tem lactose (1 = sim, 0 = não): ", 0, 1);
    lactose = false;
    if(ints == 1)
        lactose = true;
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Salgado &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Val. : " << p.getValidade() << " - ";
    os << "Sód. : " << p.getSodio() << " - ";
    os << "Glút.: " << (p.getGluten() ? "Sim" : "Não") << " - ";
    os << "Lact.: " << (p.getLactose() ? "Sim" : "Não");
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Salgado &b) {
    string lido;
    
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.validade, ';');
    
    getline(is, lido, ';');
    if(lido != "")
        b.sodio = stoi(lido);
    
    b.gluten = false;
    getline(is, lido, ';');
    if(lido == "1")
        b.gluten = true;

    b.lactose = false;
    getline(is, lido, ';');
    if(lido == "1")
        b.lactose = true;
    return is;
}