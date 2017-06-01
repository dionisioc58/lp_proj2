/**
* @file 	menu.cpp
* @brief	Arquivo de corpo com a definição de funções para o menu
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    28/04/2017
* @date     15/05/2017
*/

#include "menu.h"

#define itens 12                 /**< Quantidade de opções no menu */

string opcoes[itens] = {
    "Cadastrar uma turma                         ",
    "Excluir uma turma                           ",
    "Listar as turmas                            ",
    "Cadastrar um aluno                          ",
    "Cadastrar alunos através de um arquivo      ",
    "Excluir um aluno                            ",
    "Listar alunos                               ",
    "Listar alunos de todas as turmas            ",
    "Listar as médias de todas as turmas         ",
    "Salvar o cadastro em um arquivo             ",
    "Recuperar o cadastro em um arquivo          ",
    "Sair                                        "
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
        cout << "\t\t|             DDA - Turmas e Alunos            |" << endl;
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