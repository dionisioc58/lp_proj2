/**
* @file     tarefa2main.cpp
* @brief 	Arquivo fonte para teste da classe lista
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    14/05/2017
* @date     14/05/2017
*/

#include <iostream>
#include <string>
using namespace std;

#include "tarefa2/lista.h"

/**
* @brief        Função principal do programa
* @return		Retorno
*/
int main(void) {
	Lista<int> lista;	//Cria uma lista duplamente ligada vazia
	
	int b;
	do {					//Oferece opção para inserção de valores
		cout << "Digite um valor para inserir (0 para sair): ";
		cin >> b;
		if(b != 0) {
			lista.Insere(b);
			lista.Exibe();
		}
	} while(b != 0);

	do {					//Oferece opção para remoção de valores
		cout << "Digite um valor para remover (0 para sair): ";
		cin >> b;
		if(b != 0) {
			lista.RemoveVal(b);
			lista.Exibe();
		}
	} while(b != 0);

	lista.Exibe();			//Exibe a lista

	cout << "Digite um valor para realizar a busca: ";
	cin >> b;
	Lista<int> *busca = lista.Busca(b);
	if(busca) {
		cout << "Valor encontrado ";
		Lista<int> *a = busca->getAnterior();
		if(!a)
			cout << "no início." << endl;
		else {
			Lista<int> *p = busca->getProximo();
			if(!p)
				cout << "no final." << endl;
			else
				cout << "após '" << a->getValor() << "' e antes de '" << p->getValor() << "'." << endl;
		}
	} else
		cout << "Não encontrado!" << endl;

	return 0;
}