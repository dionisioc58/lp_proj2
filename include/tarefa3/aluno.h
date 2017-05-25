/**
 * @file	aluno.h
 * @brief	Definição da classe Aluno
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#ifndef ALUNO_H
    #define ALUNO_H

    #include <iostream>
    #include <string>
    #include <sstream>
    using std::string;
    using std::ostream;
    using std::istream;
    using std::stringstream;
    #include <ctime>
    
    /**
    * @class   Aluno aluno.h
    * @brief   Classe que representa um aluno
    * @details Os atributos de um funcionário são: nome, matricula, faltas e nota
    */  
    class Aluno {
    private:
        string nome;                                            /**< Nome */
        string matricula;                                       /**< Matricula */
        int faltas;                                             /**< Faltas */
        float nota;                                             /**< Nota */
    public:
        Aluno();                                                /**< Construtor padrão */
        ~Aluno();                                               /**< Destrutor padrão */
        string getNome();                                       /**< Retorna o nome */
        void setNome(string n);                                 /**< Modifica o nome */
        string getMatricula();                                  /**< Retorna a matricula */
        void setMatricula(string n);                            /**< Modifica a matricula */
        int getFaltas();                                        /**< Retorna o número de faltas */
        void setFaltas(int s);                                  /**< Modifica o número de faltas */
        float getNota();                                        /**< Retorna a nota */
        void setNota(float s);                                  /**< Modifica a nota */
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        bool operator>(Aluno &a);                               /** @brief Sobrecarga do operador de comparação > */
        friend ostream& operator<<(ostream& os, Aluno &f);      /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Aluno &f);      /** @brief Sobrecarga do operador de extração de stream */
    };

#endif