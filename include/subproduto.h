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
#include "funcoes.h"
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
        int acucar;                                         /**< Açúcar */
        float alcool;                                       /**< Álcool */
    public:
        Bebida();                                           /**< Construtor padrão */
        ~Bebida();                                          /**< Destrutor padrão */
        
        int getAcucar();                                    /**< Retorna o açúcar */
        void setAcucar(int ac);                             /**< Modifica o açúcar */
        float getAlcool();                                  /**< Retorna o álcool */
        void setAlcool(float al);                           /**< Modifica o álcool */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, Bebida &p); /** @brief Sobrecarga do operador de extração em stream */
        friend istream& operator>>(istream& is, Bebida &b); /** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   Fruta subproduto.h
    * @brief   Classe derivada que representa uma Fruta
    * @details Os atributos de uma bebida são: numero e data de producao
    */  
    class Fruta : public Produto, public Perecivel {
    protected:
        int num;                                            /**< Quantidade */
        string dp;                                          /**< Data de produção */
    public:
        Fruta();                                            /**< Construtor padrão */
        ~Fruta();                                           /**< Destrutor padrão */
        
        int getNum();                                       /**< Retorna o num */
        void setNum(int n);                                 /**< Modifica o num */
        string getDp();                                     /**< Retorna a dp */
        void setDp(string d);                               /**< Modifica a dp */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, Fruta &p);  /** @brief Sobrecarga do operador de extração em stream */
        friend istream& operator>>(istream& is, Fruta &b);  /** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   Doce subproduto.h
    * @brief   Classe derivada que representa um Doce
    * @details Os atributos de uma Doce são: acucar, gluten e glicose
    */  
    class Doce : public Produto, public Perecivel {
    protected:
        int acucar;                                         /**< Açúcar */
        bool gluten;                                        /**< Glúten */
        bool glicose;                                       /**< Glicose */
    public:
        Doce();                                             /**< Construtor padrão */
        ~Doce();                                            /**< Destrutor padrão */
        
        void setAcucar(int a);                              /**< Modifica o açúcar */
        int getAcucar();                                    /**< Retorna o açúcar */
        void setGluten(bool g);                             /**< Modifica o glúten */
        bool getGluten();                                   /**< Retorna o glúten */
        void setGlicose(bool l);                            /**< Modifica a glicose */
        bool getGlicose();                                  /**< Retorna a glicose */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, Doce &p);   /** @brief Sobrecarga do operador de extração em stream */
        friend istream& operator>>(istream& is, Doce &b);   /** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   Salgado subproduto.h
    * @brief   Classe derivada que representa um Salgado
    * @details Os atributos de um Salgado são: sodio, gluten e lactose
    */  
    class Salgado : public Produto, public Perecivel {
    protected:
        int sodio;                                          /**< Sódio */
        bool gluten;                                        /**< Glúten */
        bool lactose;                                       /**< Lactose */
    public:
        Salgado();                                          /**< Construtor padrão */
        ~Salgado();                                         /**< Destrutor padrão */
        
        void setSodio(int s);                               /**< Modifica o sódio */
        int getSodio();                                     /**< Retorna o sódio */
        void setGluten(bool g);                             /**< Modifica o glúten */
        bool getGluten();                                   /**< Retorna o glúten */
        void setLactose(bool l);                            /**< Modifica a lactose */
        bool getLactose();                                  /**< Retorna a lactose */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, Salgado &p);/** @brief Sobrecarga do operador de extração em stream */        
        friend istream& operator>>(istream& is, Salgado &b);/** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   CD subproduto.h
    * @brief   Classe derivada que representa um CD
    * @details Os atributos de um CD são: estilo, arista e album
    */  
    class CD : public Produto {
    protected:
        string estilo;                                      /**< Estilo */
        string artista;                                     /**< Artista */
        string album;                                       /**< Álbum */
    public:
        CD();                                               /**< Construtor padrão */
        ~CD();                                              /**< Destrutor padrão */
        
        void setEstilo(string e);                           /**< Modifica o estilo */
        string getEstilo();                                 /**< Retorna o estilo */
        void setArtista(string a);                          /**< Modifica o artista */
        string getArtista();                                /**< Retorna o artista */
        void setAlbum(string n);                            /**< Modifica o álbum */
        string getAlbum();                                  /**< Retorna o álbum */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, CD &p);     /** @brief Sobrecarga do operador de extração em stream */        
        friend istream& operator>>(istream& is, CD &b);     /** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   DVD subproduto.h
    * @brief   Classe derivada que representa um DVD
    * @details Os atributos de um DVD são: titulo, genero e duracao
    */  
    class DVD : public Produto {
    protected:
        string titulo;                                      /**< Título */
        string genero;                                      /**< Gênero */
        string duracao;                                     /**< Duração */
    public:
        DVD();                                              /**< Construtor padrão */
        ~DVD();                                             /**< Destrutor padrão */
        
        void setTitulo(string t);                           /**< Modifica o título */
        string getTitulo();                                 /**< Retorna o título */
        void setGenero(string g);                           /**< Modifica o gênero */
        string getGenero();                                 /**< Retorna o gênero */
        void setDuracao(string d);                          /**< Modifica a duração */
        string getDuracao();                                /**< Retorna a duração */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, DVD &p);    /** @brief Sobrecarga do operador de extração em stream */        
        friend istream& operator>>(istream& is, DVD &b);    /** @brief Sobrecarga do operador de inserção de stream */
    };

    /**
    * @class   Livro subproduto.h
    * @brief   Classe derivada que representa um Livro
    * @details Os atributos de um Livro são: Ano de publicacao, editora, titulo e autor
    */  
    class Livro : public Produto {
    protected:
        string autor;                                       /**< Autor */
        string titulo;                                      /**< Título */
        string editora;                                     /**< Editora */
        string anopub;                                      /**< Ano de publicação */
    public:
        Livro();                                            /**< Construtor padrão */
        ~Livro();                                           /**< Destrutor padrão */
        
        void setAutor(string a);                            /**< Modifica o autor */
        string getAutor();                                  /**< Retorna o autor */
        void setTitulo(string t);                           /**< Modifica o título */
        string getTitulo();                                 /**< Retorna o título */
        void setEditora(string e);                          /**< Modifica a editora */
        string getEditora();                                /**< Retorna a editora */
        void setAnopub(string ap);                          /**< Modifica o ano de publicação */
        string getAnopub();                                 /**< Retorna o ano de publicação */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
        void capturar();                                    /**< Coleta os dados a partir da entrada padrão */
        friend ostream& operator<<(ostream& os, Livro &p);  /** @brief Sobrecarga do operador de inserção em stream */        
        friend istream& operator>>(istream& is, Livro &b);  /** @brief Sobrecarga do operador de extração de stream */
    };
#endif