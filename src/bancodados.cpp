/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    30/05/2017
* @date     30/05/2017
*/

#include "bancodados.h"

/**
* @brief        Função que coleta os dados para o cadastro de um fornecedor
* @return       Fornecedor coletado
*/
Fornecedor inputFornecedor() {
    string input;
    Fornecedor novo;

    cout << "Digite a razão social do fornecedor: ";
    getline(cin, input);
    novo.setRSocial(input);

    cout << "Digite o CNPJ do fornecedor: ";
    getline(cin, input);
    novo.setCNPJ(input);

    return novo;
}

/**
* @brief        Função que coleta os dados para cadastro de um produto
* @return       Produto coletado
*/
Produto inputProduto() {
    //Coleta dados do produto
    string input;
    Produto novo;

    cout << "Digite o código do produto: ";
    getline(cin, input);
    novo.setcb(input);

    cout << "Digite a descrição do produto: ";
    getline(cin, input);
    novo.setdescricao(input);

    cout << "Digite o tipo do produto: ";
    getline(cin, input);
    novo.settipo(input);

    float preco = recebeFloat("Digite o preço: ", 0);
    novo.setpreco(preco);
    
    return novo;
}

/**
* @brief        Função que realiza o cadastro de um fornecedor
* @param[in]    *e Vetor de fornecedores do cadastro
*/
void cadFornecedor(Lista<Fornecedor> *e) {
    Fornecedor novo = inputFornecedor();
    if(e->Busca(novo)) {
        cout << "Fornecedor já cadastrado" << endl;
        parar();
    } else
        e->Insere(novo);
    
}

/**
* @brief        Função que remove um fornecedor do cadastro
* @param[in]    *e Vetor de fornecedores do cadastro
*/
void delFornecedor(Lista<Fornecedor> *e) {
    int selecao = selecionaObjeto(e, "Digite o número do fornecedor para a remoção (0 para cancelar): ");
    if(selecao >= 0)
        e->RemovePos(selecao);
}

/**
* @brief        Função que adiciona um produto à um fornecedor (apresenta escolha)
* @param[in]    *e Vetor de fornecedores do cadastro
*/
void addPr(Lista<Fornecedor> *e) {
    int selecao = selecionaObjeto(e, "Digite o número do fornecedor para a adição (0 para cancelar): ");
    if(selecao >= 0) {
        Fornecedor *tmp = e->Posiciona(selecao);
        Produto p;
        p = inputProduto();
        tmp->addProduto(p);
    }
}

/**
* @brief        Função que remove um produto de um Fornecedor (apresenta escolha)
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void delPr(Lista<Fornecedor> *e) {
    int selecao = selecionaObjeto(e, "Digite o número do fornecedor para a remoção do produto (0 para cancelar): ");
    if(selecao >= 0) {
        Fornecedor *f = e->Posiciona(selecao);
        selecao = selecionaObjeto(f->getProdutos(), "Selecione o número do produto para a remoção (0 para cancelar): ");
        f->delProduto(selecao);
    }
}

/**
* @brief        Função que edita um produto de um Fornecedor (apresenta escolha)
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void editPr(Lista<Fornecedor> *e) {
    int selecao = selecionaObjeto(e, "Digite o número do fornecedor para a edição do produto (0 para cancelar): ");
    if(selecao >= 0) {
        Fornecedor *f = e->Posiciona(selecao);
        selecao = selecionaObjeto(f->getProdutos(), "Selecione o número do produto para a edição (0 para cancelar): ");
        Produto *p = f->getProdutos()->Posiciona(selecao);
        
        string input;
        
        cout << "O código é: " << p->getcb() << " (ENTER para continuar)";
        getline(cin, input);
        if(input != "")
            p->setcb(input);

        cout << "A descrição é: " << p->getdescricao() << " (ENTER para continuar)";
        getline(cin, input);
        if(input != "")
            p->setdescricao(input);

        cout << "O tipo é: " << p->gettipo() << " (ENTER para continuar)";
        getline(cin, input);
        if(input != "")
            p->settipo(input);

        stringstream ss;
        ss << "O preço é: " << p->getpreco() << "(0 para continuar)";
        ss >> input;
        float preco = recebeFloat(input, 0);
        if(preco > 0)
            p->setpreco(preco);
    }
}

/**
* @brief        Função que imprime os objetos na lista
* @param[in]    *e Vetor de fornecedores do cadastro
* @param[in]    n Número de fornecedores no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
template<typename T>
void impLista(Lista<T> *e, bool pausa) {
    e->Exibe(true);
    if(pausa)
        parar();
}

/**
* @brief        Função que imprime a lista de produtos de um ou todos 
                os fornecedores do cadastro
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    all "true" imprime todos os produtos de todos os fornecedores
                "false" imprime apenas os produtos de um fornecedor (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPr(Lista<Fornecedor> *e, bool all, bool pausa) {
    if(!all) {      //Imprime todos os produtos de um fornecedor
        int selecao = selecionaObjeto(e, "Digite o número do fornecedor (0 para cancelar): ");
        if(selecao < 0)
            return -1;
        
        Fornecedor *tmp = e->Posiciona(selecao);
        if(tmp->getQtde() > 0) {
            cout << "Produtos do fornecedor " << tmp->getRSocial() << endl;
            Lista<Produto> *f = tmp->getProdutos();
            Produto produt;
            for(int i = 0; i < tmp->getQtde(); i++) {
                f = f->getProximo();
                produt = f->getValor();
                cout << "   (" << (i + 1) << ") " << produt << endl;
            }

        } else
            cout << "Nenhum produto no fornecedor selecionado." << endl;
        
        if(pausa)
            parar();
        return selecao;

    } else {        //Imprime todos os produtos de todos os fornecedores
        Lista<Fornecedor> *tmp = e;
        while(tmp) {
            cout << "Produtos do fornecedor " << tmp->getValor().getRSocial() << endl;
            Lista<Produto> *f = tmp->getValor().getProdutos();
            Produto produt;
            for(int i = 0; i < tmp->getValor().getQtde(); i++) {
                f = f->getProximo();
                produt = f->getValor();
                cout << "   (" << (i + 1) << ") " << produt << endl;
            }
            tmp = tmp->getProximo();
        }
    }
        
    if(pausa)
        parar();
    return -1;

}

/**
* @brief        Função que imprime a lista de produtos
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    filtro Filtro de listagem (0 = sem filtro, 1 = filtrar por tipo, 2 = filtrar por codigo)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPrLista(Lista<Fornecedor> *e, int filtro, bool pausa) {
    string ftipo = "", fcod = "";
    if(filtro == 1) {
        cout << "Digite o tipo que você quer listar: ";
        getline(cin, ftipo);
    }
    if(filtro == 2) {
        cout << "Digite o código que você quer procurar: ";
        getline(cin, fcod);
    }
    
    Lista<Fornecedor> *tmp = e;
    while(tmp) {
        Lista<Produto> *f = tmp->getValor().getProdutos();
        Produto produt;
        for(int i = 0; i < tmp->getValor().getQtde(); i++) {
            f = f->getProximo();
            produt = f->getValor();
            switch(filtro) {
                case 1:
                    if(produt.gettipo() == ftipo)
                        cout << "   (" << (i + 1) << ") " << produt << endl;
                    break;
                case 2:
                    if(produt.getcb() == fcod)
                        cout << "   (" << (i + 1) << ") " << produt << endl;
                    break;
                default:
                    cout << "   (" << (i + 1) << ") " << produt << endl;
            }
        }
        tmp = tmp->getProximo();
    }
        
    if(pausa)
        parar();
    return -1;

}

/**
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void salvarBD(string nome, Lista<Fornecedor> *e) {
    ofstream saida(nome);
    if(!saida) {
        cout << "Não foi possível abrir o arquivo para salvar." << endl;
        return;
    }
    Lista<Fornecedor> *tmp = e->getProximo();
    while(tmp) {
        saida << tmp->getValor().exportar() << endl;
        tmp = tmp->getProximo();
    }

    saida.close();
    cout << "Banco de dados salvo com sucesso!" << endl;
}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void abrirBD(string nome, Lista<Fornecedor> *e) {
    ifstream entrada(nome);
    if(!entrada) {
        cout << "Não foi possível abrir o arquivo de dados." << endl;
        return;
    }
    string texto;
    stringstream info;
    bool tem_forn = false;
    Fornecedor tmp;
    Produto p;
    
    entrada.clear();
    entrada.seekg(0);
    
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto.substr(7);

            if(texto.substr(0, 7) == "fornec;") {
                info >> tmp;
                e->Insere(tmp);
                tem_forn = true;
            }

            if(texto.substr(0, 7) == "produt;") {
                if(tem_forn) {
                    info >> p;
                    tmp.addProduto(p);
                }
            }
        }
    }
    entrada.close();
    cout << "Banco de dados aberto com sucesso!" << endl;
}

/**
* @brief        Função que exibe uma mensagem para manter a tela congelada
*/
void parar() {
    cin.clear();
    fflush(stdin);
    cout << "Pressione ENTER para continuar...";
    string p;
    getline(cin, p);
}

/**
* @brief        Função que exibe uma mensagem e uma lista numerada para a escolha de um objeto
* @param[in]    *e Lista de objeto
* @param[in]    msg Mensagem à exibir
*/
template<typename T>
int selecionaObjeto(Lista<T> *e, string msg) {
    impLista(e, false);
    int selecao = recebeInt(msg, 0);
    if(selecao <= 0)
        return -1;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(selecao > e->getTamanho()) {
        cout << "Seleção inválida!" << endl;
        return -1;
    }
    return selecao;
}