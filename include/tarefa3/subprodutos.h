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

    /**
    * @class   Fruta subprodutos.h
    * @brief   Classe derivada que representa uma Fruta
    * @details Os atributos de uma bebida são: numero e data de producao
    */  
    class Fruta : public Produto, Perecivel {
    protected:
        string num;
        string dp;
    public:
        Fruta();
        ~Fruta();
        
        void setNum(string n);
        string getNum();
        void setDp(string d);
        string getDp();
    
    };

    /**
    * @class   Doce subprodutos.h
    * @brief   Classe derivada que representa um Doce
    * @details Os atributos de uma Doce são: acucar, gluten e glicose
    */  
    class Doce : public Produto, Perecivel {
    protected:
        string acucar;
        string gluten;
        string glicose;
    public:
        Doce();
        ~Doce();
        
        void setAcucar(string a);
        string getAcucar();
        void setGluten(string gt);
        string getGluten();
        void setGlicose(string gc);
        string getGlicose();
    
    };

    /**
    * @class   Salgado subprodutos.h
    * @brief   Classe derivada que representa um Salgado
    * @details Os atributos de um Salgado são: sodio, gluten e lactose
    */  
    class Salgado : public Produto, Perecivel {
    protected:
        string sodio;
        string gluten;
        string lactose;
    public:
        Salgado();
        ~Salgado();
        
        void setSodio(string s;
        string getSodio();
        void setGluten(string g);
        string getGluten();
        void setLactose(string l);
        string getLactose();
    
    };

    /**
    * @class   CD subprodutos.h
    * @brief   Classe derivada que representa um CD
    * @details Os atributos de um CD são: estilo, arista e nome do album
    */  
    class CD : public Produto {
    protected:
        string estilo;
        string artista;
        string NomeAlbum;
    public:
        CD();
        ~CD();
        
        void setEstilo(string e);
        string getEstilo();
        void setArtista(string a);
        string getArtista();
        void setNomeAlbum(string n);
        string getNomeAlbum();
    
    };

    /**
    * @class   DVD subprodutos.h
    * @brief   Classe derivada que representa um DVD
    * @details Os atributos de um DVD são: titulo, genero e duracao
    */  
    class DVD : public Produto {
    protected:
        string titulo;
        string genero;
        string duracao;
    public:
        DVD();
        ~DVD();
        
        void setTitulo(string t;
        string getTitulo();
        void setGenero(string g);
        string getGenero();
        void setDuracao(string d);
        string getDuracao();
    
    };

    /**
    * @class   Livro subprodutos.h
    * @brief   Classe derivada que representa um Livro
    * @details Os atributos de um Livro são: Ano de publicacao, editora, titulo e autor
    */  
    class Livro : public Produto {
    protected:
        string autor;
        string titulo;
        string editora;
        string anopub;
    public:
        Livro();
        ~Livro();
        
        void setAutor(string a;
        string getAutor();
        void setTitulo(string t);
        string getTitulo();
        void setEditora(string e);
        string getEditora();
        void setAnopub(string ap);
        string getAnopub();
    
    };