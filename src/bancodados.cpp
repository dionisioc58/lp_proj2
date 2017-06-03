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
    int selecao = selecionaFornecedor(e, "Digite o número do fornecedor para a remoção (0 para cancelar): ");
    if(selecao >= 0)
        e->RemovePos(selecao);
}

/**
* @brief        Função que adiciona um produto à um fornecedor (apresenta escolha)
* @param[in]    *e Vetor de fornecedores do cadastro
*/
void addPr(Lista<Fornecedor> *e) {
    int selecao = selecionaFornecedor(e, "Digite o número do fornecedor para a adição (0 para cancelar): ");
    if(selecao >= 0) {
        Fornecedor *tmp = e->Posiciona(selecao);
        Produto p;
        p = inputProduto();
        tmp->addProduto(p);
    }
}

/**
* @brief        Função que adiciona produtos à um fornecedor (apresenta escolha),
*               carregando-os apartir de um arquivo CSV
* @param[in]    *e Vetor de fornecedores do cadastro
* @param[in]    n Número de fornecedores no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
* @return       Retorna o novo vetor de fornecedores após o cadastro
*/
Fornecedor *addPrArq(Fornecedor *e, int n, bool pausa) {
   /* if(n == 0)
        return e;

    impFornecedores(e, n, false);
    int selecao = recebeInt("Digite o número do fornecedor para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    string arquivo;
    cout << "Digite o caminho/nome do arquivo à ser lido: ";
    cin >> arquivo;
    ifstream lista(arquivo);
    if(!lista) {
        cout << "Arquivo inválido/não encontrado!" << endl;
        return e;
    }

    int linhas = 0, funcs = 0;
    Produto f;
    while(!lista.eof()) {
        lista >> f;
        linhas++;
        if(f.getdescricao() != "\n") {
            e[selecao].addProduto(f);
            funcs++;
        }
    }
    lista.close();
    cout << "Importação concluída com sucesso! " << endl;
    cout << linhas << " linhas no arquivo." << endl;
    cout << funcs << " produtos cadastrados." << endl;

    if(pausa) {
        cin.ignore();
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }

    return e;*/
    return NULL;
}

/**
* @brief        Função que remove um produto de um Fornecedor (apresenta escolha)
* @param[in]    *e Vetor de Fornecedores do cadastro
* @param[in]    n Número de Fornecedores no cadastro
* @return       Retorna o novo vetor de Fornecedores após o cadastro
*/
Fornecedor *delPr(Fornecedor *e, int n) {
    /*if(n == 0)
        return e;

    int empsel = impPr(e, n, false, false); //Captura o fornecedor selecionado
    int selecao = recebeInt("Digite o número do aluno à remover (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(!e[empsel].delProduto(selecao))
        cout << "Não foi possível remover!" << endl;
    return e;*/
    return NULL;
}

/**
* @brief        Função que imprime os fornecedores no cadastro
* @param[in]    *e Vetor de fornecedores do cadastro
* @param[in]    n Número de fornecedores no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
void impFornecedores(Lista<Fornecedor> *e, bool pausa) {
    e->Exibe(true);
    if(pausa)
        parar();
}

/**
* @brief        Função que imprime a lista de produtos de um ou todos 
                os fornecedores do cadastro
* @param[inout] *e Vetor de Fornecedores do cadastro
* @param[in]    all "true" imprime todos os produtos de todos os fornecedores
                "false" imprime apenas os produtos de um fornecedor (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPr(Lista<Fornecedor> *e, bool all, bool pausa) {
    if(!all) {      //Imprime todos os produtos de um fornecedor
        int selecao = selecionaFornecedor(e, "Digite o número do fornecedor (0 para cancelar): ");
        if(selecao <= 0)
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
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de Fornecedores do cadastro
* @param[in]    n Número de Fornecedores no cadastro
*/
void salvarBD(string nome, Fornecedor *e, int n) {
    /*ofstream saida(nome);
    if(!saida) {
        cout << "Não foi possível abrir o arquivo para salvar." << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        saida << e[i].exportar() << endl;
        Lista<Produto> *aa = e[i].getProdutos();
        for(int j = 0; j < e[i].getQtde(); j++) {            
            aa = aa->getProximo();
            saida << aa->getValor().exportar() << endl;
        }
    }

    saida.close();
    cout << "Banco de dados salvo com sucesso!" << endl;*/
}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de Fornecedores do cadastro
* @param[inout] n Número de Fornecedores no cadastro
* @return       Retorna o novo vetor de Fornecedores após o cadastro
*/
Fornecedor *abrirBD(string nome, Fornecedor *e, int &n) {
    /*ifstream entrada(nome);
    if(!entrada) {
        cout << "Não foi possível abrir o arquivo de dados." << endl;
        return e;
    }
    string texto;
    stringstream info;
    n = 0;
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto.substr(0, 6) == "fornec")
            n++;
    }
    Fornecedor *r = new Fornecedor[n];
    
    int conta = -1;
    entrada.clear();
    entrada.seekg(0);
    
    Produto f;
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto.substr(7);

            if(texto.substr(0, 7) == "fornec;")
                info >> r[++conta];

            if(texto.substr(0, 7) == "produt;") {
                if(conta > -1) {
                    info >> f;
                    r[conta].addProduto(f);
                }
            }
        }   
    }
    entrada.close();
    cout << "Recuperação concluída com sucesso!" << endl;

    return r;*/
    return NULL;
}

void parar() {
    cout << "Pressione ENTER para continuar...";
    string p;
    getline(cin, p);
}

int selecionaFornecedor(Lista<Fornecedor> *e, string msg) {
    impFornecedores(e, false);
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