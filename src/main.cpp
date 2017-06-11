/**
* @file    "main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    25/04/2017
* @date     15/05/2017
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "produto.h"
#include "fornecedor.h"
#include "menu.h"
#include "bancodados.h"
#include "venda.h"

#define qtde 13                 /**< Quantidade de opções no menu */

string opcoes[qtde] = {
    "Cadastrar um fornecedor", //1  - ok
    "Remover um fornecedor", //2  - ok
    "Listar os fornecedores", //3  - ok
    "Cadastrar um produto", //4  - ok
    "Remover um produto", //5  - ok
    "Alterar um produto", //6  - ok
    "Listar todos os produtos por fornecedor", //7  - ok
    "Listar todos os produtos de um fornecedor", //8  - ok
    "Listar produtos por tipo", //9  - ok
    "Listar produtos por codigo", //10 - ok
    "Realizar uma venda", //11
    "Controle de estoque", //12
    "Sair"  //0  - ok
};                /**< Opções do menu */

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    Lista<Fornecedor> *fornecs = new Lista<Fornecedor>(); /**< Cadastro */
    Lista<Venda> *itens = new Lista<Venda>();             /**< Lista de itens da venda */
    
    abrirBD("./data/banco.dat", fornecs); /**< Recuperar o cadastro a partir de um arquivo */
    while(1) {
        switch(showMenu("Q Leve Tudo - A Sua Conveniência", opcoes, qtde)) { //Exibir o menu
            case 0:             //Sair
                cout << endl;
                salvarBD("./data/banco.dat", fornecs); 
                delete fornecs;
                delete itens;
                return 0;

            case 1:              //Cadastrar um fornecedor
                cadFornecedor(fornecs);
                break;
            case 2:              //Excluir um fornecedor
                delFornecedor(fornecs);
                break;
            case 3:              //Listar os fornecedores
                impLista(fornecs, true);
                break;

            case 4:              //Adicionar um produto
                addPr(fornecs);
                break;
            case 5:              //Excluir um produto
                delPr(fornecs);
                break;
            case 6:              //Alterar um produto
                editPr(fornecs);
                break;
            
            case 7:              //Listar todos os produtos de todos os fornecedores
                impPr(fornecs);
                break;
            case 8:             //Listar todos os produtos de um fornecedor
                impPr(fornecs, false);
                break;
            case 9:             //Listar produtos por tipo
                impPrLista(fornecs, 1);
                break;
            case 10:             //Listar produtos por codigo
                impPrLista(fornecs, 2);
                break;
            
            case 11:            //Realizar uma venda
                venda(fornecs, itens);              
                break;
            case 12:            //Controle de estoque
                impPrListaEstoque(fornecs);
                break;
        }
    }
    cout << endl;
    salvarBD("./data/banco.dat", fornecs); 
    delete fornecs;
    delete itens;
    return 0;
}