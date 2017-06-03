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
#include "item.h"

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    //int qtd_est = 0, qtd_forn = 0, qtd_prods = 0;       /**< Quantidades */
    //int qtd_forn = 0;
    //Lista<Item> *estoque = NULL;                        /**< Lista de itens que conterá todo o estoque */
    Lista<Fornecedor> *fornecs = new Lista<Fornecedor>(); /**< Cadastro de fornecedores */
    
    abrirBD("./data/banco.dat", fornecs); /**< Recuperar o cadastro a partir de um arquivo */
    while(1) {
        switch(showMenu()) { //Exibir o menu
            case 0:             //Sair
                cout << endl;
                salvarBD("./data/banco.dat", fornecs); 
      //          delete[] estoque;
                //delete fornecs;
                //delete prods;
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
            
            case 11:            //Salvar o banco de dados
                
                break;
        }
    }
    cout << endl;
    salvarBD("./data/banco.dat", fornecs); 
    return 0;
}