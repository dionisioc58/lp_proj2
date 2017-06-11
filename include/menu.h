/**
* @file 	menu.h
* @brief	Arquivo de cabeçalho com a definição de funções para o menu
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    28/04/2017
* @date     28/04/2017
*/

#ifndef MENU_H
    #define MENU_H

    #include <iostream>
    using std::cout;
    using std::endl;

    #include <string>
    using std::string;

    #include <termios.h>

    #include "funcoes.h"

    /**
    * @brief        Função que exibe o menu principal
    * @return       Retorna a opção escolhida
    */
    int showMenu(string titulo, string *op, int qtd);

    /**
    * @brief     Função que configura a entrada padrão para as funções do menu
    * @param[in] liga True para ativar as funções de seleção do menu
    */
    void configura(bool liga);

    /**
    * @brief  Função que captura a entrada de dados
    * @return Retorna o número da tecla pressionada
    */
    int movimenta();

#endif