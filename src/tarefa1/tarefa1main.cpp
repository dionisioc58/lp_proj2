/**
* @file     tarefa1main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    14/05/2017
* @date     14/05/2017
*/

#include <iostream>
#include <string>
using namespace std;

#include "tarefa1/pilha.h"
#include "tarefa1/tratastring.h"

/**
* @brief        Função principal do programa
* @return		Retorno
*/
int main() {
    //Recebe a palavra/frase à ser testada
    string teste;
    cout << "Digite uma palavra para testar: ";
    getline(cin, teste);

    string palavra = teste; //Salva o conteúdo original
    tratar_string(teste);   //Realiza o tratamento para "limpeza" do conteúdo

    Pilha<string> pilha(teste.length());                //Define a pilha com o tamanho da quantidade de caracteres
    for(unsigned int i = 0; i < teste.length(); i++)    
        pilha.Push(teste.substr(i, 1));                 //Insere os caracteres na pilha
    
    string teste2 = "";
    while(!pilha.Vazio())
        teste2 += pilha.Pop();                          //Retira os caracteres da pilha

    if (teste == teste2)
        cout << "'" << palavra << "' é palíndromo!" << endl;
    else
        cout << "'" << palavra << "' NÃO é palíndromo!" << endl;
    return 0;
}