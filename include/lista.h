/**
 * @file	lista.h
 * @brief	Definição da classe Lista
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	11/06/2017
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
    * @details Os atributos de uma lista são: dado e prox
    */  
    template<typename T>
    class Lista {
    private:
        T *dado;                                            /**< Dado */
        Lista *prox;                                        /**< Próximo */
    public:
        Lista();                                            /**< Construtor padrão */
        Lista(T valor);                                     /**< Construtor especifico */
        ~Lista();                                           /**< Destrutor padrão */
        T *getValor();                                      /**< Retorna o valor */
        int getTamanho();                                   /**< Retorna a quantidade de itens na lista */
        void Insere(T valor);                               /**< Insere um valor na lista */
        void RemovePos(int pos);                            /**< Remove um valor na posição informada */
        void RemoveVal(T *valor);                           /**< Remove um valor específico */
        Lista *Busca(T *valor);                             /**< Procura um valor e retorna o nó */
        T *Posiciona(int pos);                              /**< Retorna o elemento na posição dada */
        Lista *getProximo();                                /**< Retorna o próximo nó */
        void Exibe(bool comNumeros = false);                /**< Imprime a lista */
    };

    /**
    * @details Os valores prox são inicializados com NULL
    */
    template<typename T>
    Lista<T>::Lista() {
        prox = NULL;
    }

    /**
    * @details O valor prox é inicializado com NULL e dado é criado
    */
    template<typename T>
    Lista<T>::Lista(T valor) {
        dado = new T(valor);
        prox = NULL;
    }

    /**
    * @details Destrutor padrão
    */
    template<typename T>
    Lista<T>::~Lista() {
        if(prox)
            delete prox;
    }

    /**
    * @details Retorna o valor
    */
    template<typename T>
    T *Lista<T>::getValor() {
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
        Lista<T> *novo = new Lista<T>(valor);
        if(!novo) {
            cout << "Sem memoria disponivel!\n";
            exit(1);
        }

        //novo->dado = valor;
        //BUSCAR A POSIÇÃO PARA INSERIR
        Lista *tmp = this;
        while(tmp->prox) {
            if(novo->dado > tmp->prox->dado)
                tmp = tmp->prox;
            else
                break;
        }

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
    void Lista<T>::RemoveVal(T *valor) {
        Lista *atual = this;
        Lista *remove = prox;
        while(remove && remove->dado != valor) {
            atual = remove;
            remove = remove->prox;
        }
        if(remove) {
            atual->prox = remove->prox;     //Relink o anterior ao próximo
            remove->prox = NULL;            //Para não remover todos os próximos através do destrutor padrão
            delete remove;				
        }
    }

    /**
    * @details Procura um valor e retorna o nó
    */
    template<typename T>
    Lista<T> *Lista<T>::Busca(T *valor) {
        Lista *retorna = prox;
        while(retorna && retorna->dado != valor)
            retorna = retorna->prox;

        return retorna;
    }

    /**
    * @details Retorna o elemento da posição desejada
    */
    template<typename T>
    T *Lista<T>::Posiciona(int pos) {
        Lista *retorna = prox;
        for(int i = 0; i < pos && retorna; i++) {
            if(retorna)
                retorna = retorna->prox;
            else
                return NULL;
        }
        if(retorna)
            return retorna->dado;
        else
            return NULL;
    }

    /**
    * @details Retorna o próximo nó
    */
    template<typename T>
    Lista<T> *Lista<T>::getProximo() {
        return prox;
    }

    /**
    * @details      Imprime a lista completa
    * @param[in]    comNumeros True para exibir uma lista numerada
    */
    template<typename T>
    void Lista<T>::Exibe(bool comNumeros) {
        if(!prox){
            cout << "Lista vazia!\n\n";
        }
        
        Lista *tmp;
        tmp = prox;
        
        if(!comNumeros) {
            while( tmp != NULL){
                cout << *tmp->dado << endl;
                tmp = tmp->prox;
            }
            cout << ("\n\n");
        } else {
            int i = 1;
            while( tmp != NULL){
                cout << "(" << i << ") " << *tmp->dado << endl;
                tmp = tmp->prox;
                i++;
            }
            cout << endl;
        }
    }

#endif