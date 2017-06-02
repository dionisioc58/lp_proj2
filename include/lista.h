/**
 * @file	lista.h
 * @brief	Definição da classe Lista
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	06/05/2017
 * @date	14/05/2017
 */

#ifndef LISTA_H
    #define LISTA_H

    #include <iostream>
    #include <string>
    using std::cout;
    using std::string;
    using std::endl;

    /**
    * @class   Lista lista.h
    * @brief   Classe que representa uma lista duplamente encadeada
    * @details Os atributos de uma lista são: dado, ant e prox
    */  
    template<typename T>
    class Lista {
    private:
        T dado;                                             /**< Dado */
        Lista *ant;                                         /**< Anterior */
        Lista *prox;                                        /**< Próximo */
    public:
        Lista();                                            /**< Construtor padrão */
        ~Lista();                                           /**< Destrutor padrão */
        T getValor();                                       /**< Retorna o valor */
        int getTamanho();                                   /**< Retorna a quantidade de itens na lista */
        void Insere(T valor);                               /**< Insere um valor na lista */
        void RemovePos(int pos);                            /**< Remove um valor na posição informada */
        void RemoveVal(T valor);                            /**< Remove um valor específico */
        Lista *Busca(T valor);                              /**< Procura um valor e retorna o nó */
        Lista *getAnterior();                               /**< Retorna o nó anterior */
        Lista *getProximo();                                /**< Retorna o próximo nó */
        void Exibe();                                       /**< Imprime a lista */
    };

    /**
    * @details Os valores de ant e prox são inicializados com NULL
    */
    template<typename T>
    Lista<T>::Lista() {
        ant = NULL;
        prox = NULL;
    }

    /**
    * @details Destrutor padrão
    */
    template<typename T>
    Lista<T>::~Lista() {
        if(prox)
            delete prox;    //Deleta todos os próximos recursivamente
    }

    /**
    * @details Retorna o valor
    */
    template<typename T>
    T Lista<T>::getValor() {
        return dado;
    }

    /**
    * @details Retorna a quantidade de itens na lista
    */
    template<typename T>
    int Lista<T>::getTamanho() {
        int retorno = 0;
        Lista *tmp = this->prox;
        while(tmp) {
            retorno++;
            tmp = tmp->prox;
        }
        return retorno;
    }

    /**
    * @details Insere um valor na lista
    */
    template<typename T>
    void Lista<T>::Insere(T valor) {
        Lista *novo = new Lista();
        if(!novo) {
            cout << "Sem memoria disponivel!\n";
            exit(1);
        }

        novo->dado = valor;
        //BUSCAR A POSIÇÃO PARA INSERIR
        Lista *tmp = this;
        while(tmp->prox) {
            if(novo->dado > tmp->prox->dado)
                tmp = tmp->prox;
            else
                break;
        }

        novo->ant = tmp;
        novo->prox = tmp->prox ? tmp->prox : NULL;
        tmp->prox = novo;
    }

    /**
    * @details Remove um valor na posição informada
    */
    template<typename T>
    void Lista<T>::RemovePos(int pos) {
        if(pos < 0)
            return;
        Lista *atual = this;
        Lista *remove = prox;
        for(int i = 0; i < pos; i++) {
            if(remove) {
                atual = remove;
                remove = remove->prox;
            }
        }
        if(remove) {
            atual->prox = remove->prox; //Relinka o anterior ao próximo
            remove->prox = NULL;        //Para não remover todos os próximos através do destrutor padrão
            delete remove;
        }
    }

    /**
    * @details Remove um valor específico
    */
    template<typename T>
    void Lista<T>::RemoveVal(T valor) {
        Lista *atual = this;
        Lista *remove = prox;
        while(remove && remove->dado != valor) {
            atual = remove;
            remove = remove->prox;
        }
        if(remove) {
            atual->prox = remove->prox;     //Relink o anterior ao próximo
            if(remove->prox)                //Se houve próximo, relink o anterior dele com o anterior
                remove->prox->ant = atual;  
            remove->prox = NULL;            //Para não remover todos os próximos através do destrutor padrão
            delete remove;				
        }
    }

    /**
    * @details Procura um valor e retorna o nó
    */
    template<typename T>
    Lista<T> *Lista<T>::Busca(T valor) {
        Lista *retorna = prox;
        while(retorna && retorna->dado != valor)
            retorna = retorna->prox;

        return retorna;
    }

    /**
    * @details Retorna o nó anterior
    */
    template<typename T>
    Lista<T> *Lista<T>::getAnterior() {
        if(!ant->ant)   //Se o anterior do anterior for null, é o primeiro
            return NULL;
        return ant;
    }

    /**
    * @details Retorna o próximo nó
    */
    template<typename T>
    Lista<T> *Lista<T>::getProximo() {
        return prox;
    }

    /**
    * @details Imprime a lista completa
    */
    template<typename T>
    void Lista<T>::Exibe() {
        if(!prox){
            cout << "Lista vazia!\n\n";
        }
        
        Lista *tmp;
        tmp = prox;
        
        while( tmp != NULL){
            cout << tmp->dado << "  ";
            tmp = tmp->prox;
        }
        cout << ("\n\n");
    }

#endif