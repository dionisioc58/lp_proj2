/**
 * @file	subprodutos.h
 * @brief	Definição das classe derivadas de Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef SUBPRODUTOS_H
#define SUBPRODUTOS_H

#include <iostream>
#include <string>
#include <sstream>
#include "aluno.h"
using std::string;
using std::ostream;
using std::istream;
using std::stringstream;

/**
    * @class   Bebida subprodutos.h
    * @brief   Classe derivada que representa uma bebida
    * @details Os atributos de uma bebida são: acucar, alcool
    */  
    class Bebida : public Produto, Perecivel {
    protected:
        string acucar;
        string alcool;
    public:
        Bebida();
        ~Bebida();
        
        void setAcucar(string ac);
        string getAcucar();
        void setAlcool(string al);
        string getAlcool();
    
    };