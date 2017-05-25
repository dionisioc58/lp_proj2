/**
 * @file	turma.h
 * @brief	Definição da classe Turma
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	15/05/2017
 */

#ifndef TURMA_H
    #define TURMA_H

    #include <iostream>
    #include <ctime>
    #include <string>
    using std::string;
    using std::endl;

    #include "aluno.h"
    #include "tarefa2/lista.h"

    /**
    * @class   Turma turma.h
    * @brief   Classe que representa uma turma
    * @details Os atributos de um funcionário são: nome, alunos e a qtde deles
    */  
    class Turma {
    private:
        string nome;                                        /**< Nome */
        Lista<Aluno> *alunos;	                            /**< Cria uma lista de alunos duplamente ligada vazia */
    public:
        Turma();                                            /**< Construtor padrão */
        ~Turma();                                           /**< Destrutor padrão */
        string getNome();                                   /**< Retorna o nome */
        void setNome(string n);                             /**< Modifica o nome */
        int getQtde();                                      /**< Retorna a quantidade de alunos */
        float getMedia();                                   /**< Retorna a média das notas dos alunos */
        Lista<Aluno> *getAlunos();                          /**< Retorna a lista de alunos */
        void setAlunos(Lista<Aluno> *f);                    /**< Modifica a lista de alunos */
        bool addAluno(Aluno f);                             /**< Adiciona um aluno */
        bool delAluno(int f);                               /**< Remove um aluno */
        bool pertenceTurma(string n);                       /**< Verifica se uma matrícula pertence à lista de aluno */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
		friend ostream& operator<<(ostream& os, Turma &e);  /** @brief Sobrecarga do operador de inserção em stream */
		friend istream& operator>>(istream& is, Turma &e);  /** @brief Sobrecarga do operador de extração de stream */
    };

#endif