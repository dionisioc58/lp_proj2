/**
 * @file	pilha.h
 * @brief	Definição da classe Pilha
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	14/05/2017
 */

#ifndef PILHA_H
    #define PILHA_H

    /**
    * @class   Pilha pilha.h
    * @brief   Classe que representa uma pilha
    * @details Os atributos de uma lista são: dados, qtde e max
    */
    template<typename T>
    class Pilha {
    private:
        T *dados;                           /**< Dados */
        int qtde;                           /**< Quantidade */
        int max;                            /**< Máximo */
    public:
        Pilha(int tam);                     /**< Construtor padrão */
        ~Pilha();                           /**< Destrutor padrão */
        void Push(T val);                   /**< Inserir um dado na pilha */
        T Pop();                            /**< Retirar um dado da pilha */
        bool Vazio();                       /**< Testa se a pilha está vazia */
        bool Cheio();                       /**< Testa se a pilha está cheia */
    };

    /**
    * @details Os valores de dados e max são inicializados com o tamanho
    *          informado e a qtde com 0
    */
    template<typename T>
    Pilha<T>::Pilha(int tam) {
        dados = new T[tam];
        max = tam;
        qtde = 0;
    }

    /**
    * @details Destrutor padrão
    */
    template<typename T>
    Pilha<T>::~Pilha() {
        delete[] dados;
    }

    /**
    * @details Inserir um dado na pilha
    */
    template<typename T>
    void Pilha<T>::Push(T val) {
        if(!Cheio())
            dados[qtde++] = val;
    }
    
    /**
    * @details Retirar um dado da pilha
    */
    template<typename T>
    T Pilha<T>::Pop() {
        if(!Vazio())
            return dados[--qtde];
        else
            return dados[0];
    }

    /**
    * @details Testa se a pilha está vazia
    */
    template<typename T>
    bool Pilha<T>::Vazio() {
        return (qtde == 0);
    }

    /**
    * @details Testa se a pilha está cheia
    */
    template<typename T>
    bool Pilha<T>::Cheio() {
        return (qtde == max);
    }

#endif