/**
* @file    "main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
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

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    int qtdt = 0;         /**< Quantidade de turmas cadastradas */
    Fornecedor *tur = NULL;    /**< Vetor de turmas que conterá todo o cadastro */
    tur = abrirBD("./data/banco.dat", tur, qtdt); /**< Recuperar o cadastro a partir de um arquivo */
    while(1) {
        switch(showMenu()) { //Exibir o menu
            case 0:             //Sair
                cout << endl;
                delete[] tur;
                return 0;
                break;
                
            case 1:              //Cadastrar uma Turma
                tur = cadFornecedor(tur, qtdt);
                break;
            case 2:              //Excluir uma Turma
                tur = delFornecedor(tur, qtdt);
                break;
            case 3:              //Listar as Turma
                impFornecedores(tur, qtdt);
                break;

            case 4:              //Adicionar um aluno
                tur = addPr(tur, qtdt);
                break;
            case 5:              //Adicionar alunos através de um arquivo
                tur = addPrArq(tur, qtdt);
                break;
            case 6:              //Excluir um aluno
                tur = delPr(tur, qtdt);
                break;
            
            case 7:              //Listar os alunos de uma turma
                impPr(tur, qtdt, false);
                break;
            case 8:             //Listar todos os alunos de todas as turmas
                impPr(tur, qtdt, true);
                break;
            case 9:
                impFornecedores(tur, qtdt, true);
                break;
            
            case 10:            //Salvar o banco de dados
                salvarBD("./data/banco.dat", tur, qtdt); 
                break;
            case 11:            //Recuperar o banco
                tur = abrirBD("./data/banco.dat", tur, qtdt); 
                break;
        }
    }
    cout << endl;
    delete[] tur;
    return 0;
}