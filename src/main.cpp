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
    
    //estoque = abrirBD("./data/banco.dat", estoque, qtd_est); /**< Recuperar o cadastro a partir de um arquivo */
    while(1) {
        switch(showMenu()) { //Exibir o menu
            case 0:             //Sair
                cout << endl;
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
                impFornecedores(fornecs, true);
                break;

            case 4:              //Adicionar um produto
                addPr(fornecs);
                break;
            /*case 5:              //Adicionar produtos através de um arquivo
                estoque = addPrArq(estoque, qtd_est);
                break;
            case 6:              //Excluir um produto
                estoque = delPr(estoque, qtd_est);
                break;*/
            
            case 7:              //Listar os produtos de um fornecedor
                impPr(fornecs);
                break;
            case 8:             //Listar todos os produtos de todas os fornecedores
                impPr(fornecs, false);
                break;
            /*case 9:
                impFornecedores(estoque, qtd_est, true);
                break;
            
            case 10:            //Salvar o banco de dados
                salvarBD("./data/banco.dat", estoque, qtd_est); 
                break;
            case 11:            //Recuperar o banco
                estoque = abrirBD("./data/banco.dat", estoque, qtd_est); 
                break;*/
        }
    }
    cout << endl;
 //   delete[] estoque;
//    delete[] fornecs;
    //delete prods;
    return 0;
}