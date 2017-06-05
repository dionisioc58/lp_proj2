/**
* @file 	funcoes.h
* @brief	Arquivo de cabeçalho com a definição de funções auxiliares para a entrada de dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    11/03/2017
* @date     02/04/2017
*/

#ifndef FUNCOES_H
    #define FUNCOES_H

    #include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;

    #include <string>
    using std::string;

    /**
    * @brief        Função que coleta um valor float maior que zero pela entrada validando-o
    * @param[in]	msg String com a mensagem à exibir
    * @param[in]	min Int com o valor mínimo aceitável
    * @return       Float capturado
    */
    float recebeFloat(string msg, int min);

    /**
    * @brief        Função que coleta um valor inteiro maior ou igual à zero pela entrada validando-o
    * @param[in]    msg String com a mensagem à exibir
    * @param[in]	min Int com o valor mínimo aceitável
    * @param[in]	max Int com o valor máximo aceitável
    * @return       Int capturado
    */
    int recebeInt(string msg, int min, int max = 0);

    /**
    * @brief Funcao que converte todos os caracteres para letra minuscula
    * @param s String a ser convertida
    */
    void minusculas(string& s);

#endif