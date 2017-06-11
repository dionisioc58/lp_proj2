/**
* @file 	funcoes.cpp
* @brief	Arquivo de corpo com a definição de funções auxiliares para a entrada de dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    11/03/2017
* @date     02/04/2017
*/

#include "funcoes.h"

/**
* @brief        Função que coleta um valor float maior que zero pela entrada validando-o
* @param[in]	msg String com a mensagem à exibir
* @param[in]	min Int com o valor mínimo aceitável
* @return       Float capturado
*/
float recebeFloat(string msg, int min) {
	float valor = -1;
	while(valor < min) {
		cout << msg;
		cin >> valor;
		if (cin.fail() || cin.get() != '\n') {
			cout << "Valor inválido!" << endl;
			cin.clear(); /**< limpar o bit de falha do cin */
			while (cin.get() != '\n') ; /** < receber todos dados digitados até o fim da linha para esvaziar */
			valor = -1;
		} else if(valor < min)
				cout << "Valor inválido!" << endl;
	}
	return valor;
}

/**
* @brief        Função que coleta um valor inteiro maior ou igual à zero pela entrada validando-o
* @param[in]    msg String com a mensagem à exibir
* @param[in]	min Int com o valor mínimo aceitável
* @param[in]	max Int com o valor máximo aceitável
* @return       Int capturado
*/
int recebeInt(string msg, int min, int max) {
	int valor = -1;
	int max2 = max;
	while((valor < min) || (valor > max)) {
		cout << msg;
		cin >> valor;
		if(max2 == 0) max = valor; //Para desconsiderar o max

		if (cin.fail() || cin.get() != '\n') {
			cout << "Valor inválido!" << endl;
			cin.clear(); /**< impar o bit de falha do cin */
			while (cin.get() != '\n') ; /**< receber todos dados digitados até o fim da linha para esvaziar */
			valor = -1;
		} else if((valor < min) || (valor > max))
			cout << "Valor inválido!" << endl;
	}
	return valor;
}

/**
* @brief        Função que coleta um valor string pela entrada validando-o
* @param[in]    msg String com a mensagem à exibir
* @return       String capturada
*/
string recebeString(string msg) {
	int teste = -1;
	string valor = "";
	while(teste < 0) {
		cout << msg;
		cin >> valor;
		if (cin.fail() || cin.get() != '\n') {
			cout << "Valor inválido!" << endl;
			cin.clear(); /**< impar o bit de falha do cin */
			while (cin.get() != '\n') ; /**< receber todos dados digitados até o fim da linha para esvaziar */
			teste = -1;
		} else
			teste = 1;
	}
	return valor;
}

/**
 * @brief Funcao que converte todos os caracteres para letra minuscula
 * @param s String a ser convertida
 */
void minusculas(string& s) {
	for (int i = 0; i < (int)s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

/**
 * @brief Função que remove acentuações de uma string
 * @param s String com acentuações a remover
 */
void remove_acentos (string &s) {
    string com_acento = "âÂàÀáÁãÃêÊèÈéÉẽẼîÎìÌíÍõÕôÔòÒóÓüÜûÛúÚùÙçÇ";
    string sem_acento = "aAaAaAaAeEeEeEeEiIiIiIoOoOoOoOuUuUuUuUcC";
    int temp = com_acento.length();
    for (int i = 0; s[i] != '\0'; i++) {
        int k = 0;
        for (int j = 0; j < temp; j += 2) {
            if ((s[i] == com_acento[j]) && (s[i + 1] == com_acento[j + 1])) {   
                s[i] = sem_acento[k];
                s.erase((i + 1), 1);
                i += 1;
                break;
            }
            k++;
        }
    }
}