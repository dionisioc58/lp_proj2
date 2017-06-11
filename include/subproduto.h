/**
 * @file	subproduto.h
 * @brief	Definição das classe derivadas de Produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#ifndef SUBPRODUTO_H
#define SUBPRODUTO_H

#include <iostream>
#include <string>
#include "produto.h"
#include "perecivel.h"
using std::string;
using std::cin;
using std::cout;

/**
    * @class   Bebida subproduto.h
    * @brief   Classe derivada que representa uma bebida
    * @details Os atributos de uma bebida são: acucar, alcool
    */  
    class Bebida : public Produto, public Perecivel {
    protected:
        int acucar;
        float alcool;
    public:
        Bebida();
        ~Bebida();
        
        void setAcucar(int ac);
        int getAcucar();
        void setAlcool(float al);
        float getAlcool();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Bebida &p);    /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Bebida &b);     /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   Fruta subproduto.h
    * @brief   Classe derivada que representa uma Fruta
    * @details Os atributos de uma bebida são: numero e data de producao
    */  
    class Fruta : public Produto, public Perecivel {
    protected:
        int num;
        string dp;
    public:
        Fruta();
        ~Fruta();
        
        void setNum(int n);
        int getNum();
        void setDp(string d);
        string getDp();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Fruta &p);    /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Fruta &b);    /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   Doce subproduto.h
    * @brief   Classe derivada que representa um Doce
    * @details Os atributos de uma Doce são: acucar, gluten e glicose
    */  
    class Doce : public Produto, public Perecivel {
    protected:
        int acucar;
        bool gluten;
        bool glicose;
    public:
        Doce();
        ~Doce();
        
        void setAcucar(int a);
        int getAcucar();
        void setGluten(bool g);
        bool getGluten();
        void setGlicose(bool l);
        bool getGlicose();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Doce &p);    /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Doce &b);    /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   Salgado subproduto.h
    * @brief   Classe derivada que representa um Salgado
    * @details Os atributos de um Salgado são: sodio, gluten e lactose
    */  
    class Salgado : public Produto, public Perecivel {
    protected:
        int sodio;
        bool gluten;
        bool lactose;
    public:
        Salgado();
        ~Salgado();
        
        void setSodio(int s);
        int getSodio();
        void setGluten(bool g);
        bool getGluten();
        void setLactose(bool l);
        bool getLactose();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Salgado &p);    /** @brief Sobrecarga do operador de inserção em stream */        
        friend istream& operator>>(istream& is, Salgado &b);    /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   CD subproduto.h
    * @brief   Classe derivada que representa um CD
    * @details Os atributos de um CD são: estilo, arista e album
    */  
    class CD : public Produto {
    protected:
        string estilo;
        string artista;
        string album;
    public:
        CD();
        ~CD();
        
        void setEstilo(string e);
        string getEstilo();
        void setArtista(string a);
        string getArtista();
        void setAlbum(string n);
        string getAlbum();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, CD &p);    /** @brief Sobrecarga do operador de inserção em stream */        
        friend istream& operator>>(istream& is, CD &b);    /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   DVD subproduto.h
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
        
        void setTitulo(string t);
        string getTitulo();
        void setGenero(string g);
        string getGenero();
        void setDuracao(string d);
        string getDuracao();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, DVD &p);    /** @brief Sobrecarga do operador de inserção em stream */        
        friend istream& operator>>(istream& is, DVD &b);    /** @brief Sobrecarga do operador de extração de stream */
    };

    /**
    * @class   Livro subproduto.h
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
        
        void setAutor(string a);
        string getAutor();
        void setTitulo(string t);
        string getTitulo();
        void setEditora(string e);
        string getEditora();
        void setAnopub(string ap);
        string getAnopub();
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Livro &p);    /** @brief Sobrecarga do operador de inserção em stream */        
        friend istream& operator>>(istream& is, Livro &b);    /** @brief Sobrecarga do operador de extração de stream */
    };
#endif