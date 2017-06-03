/**
* @file 	menu.cpp
* @brief	Arquivo de corpo com a definição de funções para o menu
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    28/04/2017
* @date     15/05/2017
*/

#include "menu.h"

#define itens 13                 /**< Quantidade de opções no menu */

string opcoes[itens] = {
    "Cadastrar um fornecedor                     ", //1  - ok
    "Remover um fornecedor                       ", //2  - ok
    "Listar os fornecedores                      ", //3  - ok
    "Cadastrar um produto                        ", //4  - ok (faltam os subtipos)
    "Remover um produto                          ", //5  - ok
    "Alterar um produto                          ", //6  - ok
    "Listar todos os produtos por fornecedor     ", //7  - ok
    "Listar todos os produtos de um fornecedor   ", //8  - ok
    "Listar produtos por tipo                    ", //9  - ok
    "Listar produtos por codigo                  ", //10 - ok
    "Vender                                      ", //11
    "Controle de estoque                         ", //12
    "Sair                                        "  //0  - ok
};                /**< Opções do menu */

/**
* @brief        Função que exibe o menu principal
* @return       Retorna a opção escolhida
*/
int showMenu() {
    configura(true);      // Configura a entrada padrão para ativar a seleção do menu
    int realce = 0;
    int a;
    while(true) {
        cout << string(50, '\n'); //Limpa a tela
        cout << "\t\t|**********************************************|" << endl;
        cout << "\t\t|\x1b[43m       Q Leve Tudo - A Sua Conveniência       \x1b[0m|" << endl;
        cout << "\t\t|                                              |" << endl;
        for(int i = 0; i < itens; i++) {        
            if(realce == i)
                cout << "\t\t|\x1b[42m  " << opcoes[i] << "\x1b[0m|" << endl;
            else
                cout << "\t\t|  " << opcoes[i] << "|" << endl;
        }
        cout << "\t\t|______________________________________________|" << endl;
        
        a = movimenta(); //Captura as teclas
        if(a == 65)      //Seta para cima
            realce > 0 ? realce-- : realce = itens - 1;
        if(a == 66)      //Seta para baixo
            realce < (itens - 1) ? realce++ : realce = 0;
        if(a == 10)      //Enter
            break;

    }
    configura(false);      // Desconfigura a entrada padrão para ativar a seleção do menu
    realce++;
    if(realce == itens)    //Última opção = sair
        return 0;
    return realce;
}
    
/**
* @brief     Função que configura a entrada padrão para as funções do menu
* @param[in] liga True para ativar as funções de seleção do menu
*/
void configura(bool liga) {

    termios t;
    tcgetattr(0, &t);           //Copia os atributos de configuração do terminal
        
    if(liga) {    
        t.c_lflag &= ~ECHO;     //Remove a opção de ECHO da entrada
        t.c_lflag &= ~ICANON;   //Desativa o modo canônico (não espera pelo carriage return)
    } else {
        t.c_lflag |= ECHO;      //Repõe a opção de ECHO da entrada
        t.c_lflag |= ICANON;    //Reativa o modo canônico
    }
    tcsetattr(0, TCSANOW, &t);   //Aplica as alterações
}

/**
* @brief  Função que captura a entrada de dados
* @return Retorna o número da tecla pressionada
*/
int movimenta() {
    int c = cin.get();
    if(c == 27) {
        c = cin.get();
        c = cin.get();
    }
    return c; 
}