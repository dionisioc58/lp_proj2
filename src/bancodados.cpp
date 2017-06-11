/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author	Eduardo Rique (luiseduardorique@gmail.com)
* @since    30/05/2017
* @date     30/05/2017
*/

#include "bancodados.h"

#define qtde_tipos 8                 /**< Quantidade de opções de tipos no menu */

string tipos_prods[qtde_tipos] = {
    "Bebida",   //1  - ok
    "Fruta",    //2  - ok
    "Doce",     //3  - ok
    "Salgado",  //4  - ok
    "CD",       //5  - ok
    "DVD",      //6  - ok
    "Livro",    //7  - ok
    "(Cancelar)"
};                /**< Opções de tipos de produtos */

/**
* @brief        Função que coleta os dados para o cadastro de um fornecedor
* @return       Fornecedor coletado
*/
Fornecedor *inputFornecedor() {
    string input;
    Fornecedor *novo = new Fornecedor();

    cout << "Digite a razão social do fornecedor: ";
    getline(cin, input);
    novo->setRSocial(input);

    cout << "Digite o CNPJ do fornecedor: ";
    getline(cin, input);
    novo->setCNPJ(input);

    return novo;
}

/**
* @brief        Função que coleta os dados para cadastro de um produto
* @return       Produto coletado
*/
void inputProduto(Fornecedor *f) {
    //Coleta dados do produto
    //cout << "Digite o tipo do produto: ";
    //getline(cin, input);
    int selecao = showMenu("Selecione um tipo de produto", tipos_prods, qtde_tipos);
    if(selecao <= 0)
        return;
    string tipo = tipos_prods[--selecao];
    minusculas(tipo);
    Produto *novo;

    if(tipo == "bebida") {
        novo = new Bebida();
        novo->capturar();
        dynamic_cast<Bebida*>(novo)->capturar();
    }
    if(tipo == "fruta") {
        novo = new Fruta();
        novo->capturar();
        dynamic_cast<Fruta*>(novo)->capturar();
    }
    if(tipo == "doce") {
        novo = new Doce();
        novo->capturar();
        dynamic_cast<Doce*>(novo)->capturar();
    }
    if(tipo == "salgado") {
        novo = new Salgado();
        novo->capturar();
        dynamic_cast<Salgado*>(novo)->capturar();
    }
    if(tipo == "cd") {
        novo = new CD();
        novo->capturar();
        dynamic_cast<CD*>(novo)->capturar();
    }
    if(tipo == "dvd") {
        novo = new DVD();
        novo->capturar();
        dynamic_cast<DVD*>(novo)->capturar();
    }
    if(tipo == "livro") {
        novo = new Livro();
        novo->capturar();
        dynamic_cast<Livro*>(novo)->capturar();
    }
    if(!f->addProduto(novo))
        cout << "Produto já cadastrado" << endl;
    else
        cout << "Cadastro realizado com sucesso!" << endl;
    parar();        
}

/**
* @brief        Função que realiza o cadastro de um fornecedor
* @param[in]    *e Vetor de fornecedores do cadastro
*/
void cadFornecedor(Lista<Fornecedor> *e) {
    Fornecedor *novo = inputFornecedor();
    if(e->Busca(novo)) {
        cout << "Fornecedor já cadastrado" << endl;
        parar();
    } else
        e->Insere(*novo);
    
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
        inputProduto(tmp);
        cout << "Produto adicionado com sucesso!" << endl;
    }
}

/**
* @brief        Função que remove um produto de um Fornecedor (apresenta escolha)
* @param[in]    *e Lista de Fornecedores do cadastro
*/
void delPr(Lista<Fornecedor> *e) {
    int selecao = selecionaObjeto(e, "Digite o número do fornecedor para a remoção do produto (0 para cancelar): ");
    if(selecao >= 0) {
        Fornecedor *tmp = e->Posiciona(selecao);
        //selecao = selecionaObjeto(f->getProdutos(), "Selecione o número do produto para a remoção (0 para cancelar): ");
        Lista<Produto*> f = *tmp->getProdutos();
        Produto *produt;
        for(int i = 0; i < tmp->getQtde(); i++) {
            f = *f.getProximo();
            produt = *f.getValor();
            cout << "   (" << (i + 1) << ") ";
            imprimir(produt);
        }
        selecao = recebeInt("Selecione o número do produto para a remoção (0 para cancelar): ", 0, tmp->getQtde());
        selecao--;
        if(selecao >= 0)
            tmp->delProduto(selecao);
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
        if(selecao > 0) {
            Produto *p = *(f->getProdutos())->Posiciona(selecao);
            
            string input;
            
            cout << "O código é: " << p->getCb() << " (ENTER para manter): ";
            getline(cin, input);
            if(input != "")
                p->setCb(input);

            cout << "A descrição é: " << p->getDescricao() << " (ENTER para manter): ";
            getline(cin, input);
            if(input != "")
                p->setDescricao(input);

            cout << "O tipo é: " << p->getTipo() << " (ENTER para manter): ";
            getline(cin, input);
            if(input != "")
                p->setTipo(input);

            stringstream ss;
            ss << "O preço é: " << p->getPreco() << " (0 para manter): ";
            input = ss.str();
            float preco = recebeFloat(input, 0);
            if(preco > 0)
                p->setPreco(preco);

            ss.clear();
            ss << "A quantidade é: " << p->getQtde() << " (0 para manter): ";
            input = ss.str();
            float qtde = recebeInt(input, 0);
            if(qtde > 0)
                p->setQtde(qtde);
        }
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
            Lista<Produto*> *f = tmp->getProdutos();
            Produto *produt;
            for(int i = 0; i < tmp->getQtde(); i++) {
                f = f->getProximo();
                produt = *f->getValor();
                cout << "   (" << (i + 1) << ") ";
                imprimir(produt);
                cout << endl;
                cout << "______________________________________________" << endl;
            }

        } else
            cout << "Nenhum produto no fornecedor selecionado." << endl;
        
        if(pausa)
            parar();
        return selecao;

    } else {        //Imprime todos os produtos de todos os fornecedores
        Lista<Fornecedor> *tmp = e->getProximo();
        while(tmp) {
            cout << "Produtos do fornecedor " << tmp->getValor()->getRSocial() << endl;
            Lista<Produto*> f = *(tmp->getValor())->getProdutos();
            Produto *produt;
            for(int i = 0; i < tmp->getValor()->getQtde(); i++) {
                f = *f.getProximo();
                produt = *f.getValor();
                cout << "   (" << (i + 1) << ") ";
                imprimir(produt);
                cout << endl;
                cout << "______________________________________________" << endl;
            }
            tmp = tmp->getProximo();
        }
    }
        
    if(pausa)
        parar();
    return -1;

}

void imprimir(Produto *p, bool detalhes) {
    string tipo = p->getTipo();
    minusculas(tipo);
    if(detalhes) {
        if(tipo == "bebida")
            cout << *dynamic_cast<Bebida*>(p);
        else if(tipo == "fruta")
            cout << *dynamic_cast<Fruta*>(p);
        else if(tipo == "doce")
            cout << *dynamic_cast<Doce*>(p);
        else if(tipo == "salgado")
            cout << *dynamic_cast<Salgado*>(p);
        else if(tipo == "cd")
            cout << *dynamic_cast<CD*>(p);
        else if(tipo == "dvd")
            cout << *dynamic_cast<DVD*>(p);
        else if(tipo == "livro")
            cout << *dynamic_cast<Livro*>(p);
        else
            cout << *dynamic_cast<Produto*>(p);
    } else
        cout << *p;
}

/**
* @brief        Função que imprime a lista de produtos
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    filtro Filtro de listagem (0 = sem filtro, 1 = filtrar por tipo, 2 = filtrar por codigo, 3 = exibir menos detalhes)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       Número máximo na lista
*/
int impPrLista(Lista<Fornecedor> *e, int filtro, bool pausa) {
    string ftipo = "", fcod = "";
    if(filtro == 1) {
        int selecao = showMenu("Selecione um tipo de produto", tipos_prods, qtde_tipos);
        if(selecao <= 0)
            return -1;
        ftipo = tipos_prods[--selecao];
        minusculas(ftipo);
    }
    if(filtro == 2) {
        cout << "Digite o código que você quer procurar: ";
        getline(cin, fcod);
    }
    
    Lista<Fornecedor> *tmp = e->getProximo();
    int j = 0;
    while(tmp) {
        Lista<Produto*> *f = tmp->getValor()->getProdutos();
        Produto *produt;
        for(int i = 0; i < tmp->getValor()->getQtde(); i++) {
            f = f->getProximo();
            produt = *f->getValor();
            string tip = produt->getTipo();
            minusculas(tip);
            switch(filtro) {
                case 1:
                    if(tip == ftipo) {
                        cout << "   (" << ++j << ") ";
                        imprimir(produt);
                        cout << endl;
                        cout << "______________________________________________" << endl;
                    }
                    break;
                case 2:
                    if(produt->getCb() == fcod) {
                        cout << "   (" << ++j << ") ";
                        imprimir(produt);
                        cout << endl;
                        cout << "______________________________________________" << endl;
                    }
                    break;
                case 3:
                    cout << "   (" << ++j << ") ";
                    imprimir(produt, false);
                    cout << endl;
                    cout << "______________________________________________" << endl;
                    break;
                default:
                    cout << "   (" << ++j << ") ";
                    imprimir(produt);
                    cout << endl;
                    cout << "______________________________________________" << endl;
            }
        }
        tmp = tmp->getProximo();
    }
        
    if(pausa)
        parar();
    return j;

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
        saida << tmp->getValor()->exportar() << endl;
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
    stringstream info, detalhe;
    bool tem_forn = false;
    Fornecedor *tmp;
    
    int conta1 = 0, conta2 = 0;
    entrada.clear();
    entrada.seekg(0);
    Produto *pp;
    
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto;
            
            if(texto.substr(0, 7) == "fornec;") {
                tmp = new Fornecedor();
                string tipo;
                getline(info, tipo, ';');
                info >> *tmp;
                e->Insere(*tmp);
                tem_forn = true;
                conta1++;
            }

            if(texto.substr(0, 7) == "produt;") {
                if(tem_forn) {
                    string tipo;
                    getline(info, tipo, ';');
                    getline(info, tipo, ';');
                    minusculas(tipo);
                    if(tipo == "bebida") {
                        pp = new Bebida();
                        info >> *dynamic_cast<Bebida*>(pp);
                    } else if(tipo == "fruta") {
                        pp = new Fruta();
                        info >> *dynamic_cast<Fruta*>(pp);
                    } else if(tipo == "doce") {
                        pp = new Doce();
                        info >> *dynamic_cast<Doce*>(pp);
                    } else if(tipo == "salgado") {
                        pp = new Salgado();
                        info >> *dynamic_cast<Salgado*>(pp);
                    } else if(tipo == "cd") {
                        pp = new CD();
                        info >> *dynamic_cast<CD*>(pp);
                    } else if(tipo == "dvd") {
                        pp = new DVD();
                        info >> *dynamic_cast<DVD*>(pp);
                    } else if(tipo == "livro") {
                        pp = new Livro();
                        info >> *dynamic_cast<Livro*>(pp);
                    } else
                        info >> *pp;
                    tmp->addProduto(pp);
                    conta2++;
                }
            }
        }
    }
    entrada.close();
    cout << "Banco de dados aberto com sucesso!" << endl;
    cout << conta1 << " fornecedores e " << conta2 << " produtos encontrados." << endl;
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

/**
* @brief        Função que retorna um produto, dada uma determinada posicao na lista numerada
* @param[in]    *e Lista de fornecedores e seus produtos
* @param[in]    pos Posição do produto na lista numerada
* @return       Produto selecionado
*/
Produto *capturaProduto(Lista<Fornecedor> *e, int pos) {
    Lista<Fornecedor> *tmp = e;
    Lista<Produto*> *p;
    Produto *retorno;
    int j = 1;
    while(tmp && j <= pos) {
        p = tmp->getValor()->getProdutos();
        if((j + tmp->getValor()->getQtde()) > pos)
            break;
        j += tmp->getValor()->getQtde();
        tmp = tmp->getProximo();
    }
    retorno = *p->Posiciona(pos - j);

    return retorno;
}

#define qtde_vendas 5                 /**< Quantidade de opções de tipos no menu */

string opcoes_vendas[qtde_vendas] = {
    "Adicionar um produto",   //1  - ok
    "Remover um produto",    //2  - ok
    "Listar os produtos",     //3  - ok
    "Encerrar a venda",  //4  - ok
    "(Voltar ao menu)"       //5  - ok
};                /**< Opções de tipos de produtos */

/**
* @brief        Função que realiza uma venda
* @param[in]    *e Lista de fornecedores com seus produtos
* @param[in]    *v Lista de venda com seus itens
*/
void venda(Lista<Fornecedor> *e, Lista<Venda> *v) {
    while(1) {
        switch(showMenu("Venda de Produtos", opcoes_vendas, qtde_vendas)) {
            case 0: //Voltar ao menu
                return;
                break;
            case 1: //Adicionar um produto
                venda_add(e, v);
                break;
            case 2: //Remover um produto
                venda_del(e, v);
                break;
            case 3: //Listar os produtos
                venda_lis(v);
                break;
            case 4: //Encerrar a venda
                venda_enc(v);
                break;
        }
    }
}

void venda_add(Lista<Fornecedor> *e, Lista<Venda> *v) {
    //Lista todos os itens do cadastro
    int maximo = impPrLista(e, 3, false);
    if(maximo == -1)
        return;
    //Seleciona um deles
    int selecao = recebeInt("Digite o número do produto (0 para cancelar): ", 0, maximo);
    if(selecao == 0)
        return;
    Venda *nova = new Venda();

    Lista<Fornecedor> *tmp = e->getProximo();
    Lista<Produto*> *p;
    Produto *retorno;
    int j = 1;
    while(tmp && j <= selecao) {
        p = tmp->getValor()->getProdutos();
        if((j + tmp->getValor()->getQtde()) > selecao)
            break;
        j += tmp->getValor()->getQtde();
        tmp = tmp->getProximo();
    }
    retorno = *p->Posiciona(selecao - j);

    nova->setProduto(retorno);

    int qtd = recebeInt("Digite a quantidade: ", 1, retorno->getQtde());
    nova->setQtde(qtd);
    
    v->Insere(*nova);
}

void venda_lis(Lista<Venda> *v, bool pausa) {
    cout << "Nº  Código" << string(4, ' ') << "\t|Descrição" << string(22, ' ') << "\t|Qtde  " << "\t|Total" << endl;
    v->Exibe(1);
    if(pausa)
        parar();
}

void venda_del(Lista<Fornecedor> *e, Lista<Venda> *v) {
    v->Exibe(true);
    int selecao = recebeInt("Digite o número do produto (0 para cancelar): ", 0, v->getTamanho());
    if(selecao == 0)
        return;
    v->RemovePos(--selecao);
}

void venda_enc(Lista<Venda> *v) {
    venda_lis(v, false);
    if(!v->getProximo())
        return;
    Lista<Venda> *tmp = v->getProximo();
    float total = 0;
    for(int i = 0; i < v->getTamanho(); i++) {
        Produto *p = tmp->getValor()->getProduto();
        total += (p->getPreco() * tmp->getValor()->getQtde());
        tmp = tmp->getProximo();
    }
    cout << "_____________________________________" << endl;
    cout << "Total da compra: " << total << endl;
    cout << "_____________________________________" << endl << endl;
    parar();
    string sim_nao[2] = {"Sim", "Não"};
    int ret = showMenu("Encerrar a venda?", sim_nao, 2);
    if(ret == 0) //Escolheu 'não'
        return;
    
    tmp = v->getProximo();
    for(int i = 0; i < v->getTamanho(); i++) {
        Produto *p = tmp->getValor()->getProduto();
        p->setQtde(p->getQtde() - tmp->getValor()->getQtde());
        tmp = tmp->getProximo();
    }
    while(v->getTamanho() > 0)
        v->RemovePos(0);
}

/**
* @brief        Função que imprime a lista de estoque
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPrListaEstoque(Lista<Fornecedor> *e, bool pausa) {
    if(!e)
        return -1;
    Lista<Fornecedor> *tmp = e->getProximo();
    bool primeiro = true;
    while(tmp) {
        if(primeiro) {
            cout << endl << "  Código" << string(4, ' ') << "\t|Descrição" << string(21, ' ') << "\t|Quantidade" << endl;
            primeiro = false;
        }
        Lista<Produto*> *f = tmp->getValor()->getProdutos();
        Produto *produt;
        for(int i = 0; i < tmp->getValor()->getQtde(); i++) {
            f = f->getProximo();
            produt = *f->getValor();
            cout << "  " << produt->getEstoque() << endl;
        }
        tmp = tmp->getProximo();
    }
    
    cout << endl;
    
    if(pausa)
        parar();
    return -1;

}