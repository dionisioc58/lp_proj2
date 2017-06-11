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
    string input;
    int ints;
    float floats;
    cout << "Digite o tipo do produto: ";
    getline(cin, input);
    minusculas(input);
    string tipo = input;
    Produto *novo;

    if(tipo == "bebida") {
        novo = new Bebida();
        /*novo->setcb("45454");
        novo->setdescricao("Cerveja");
        novo->setpreco(2.89);
        novo->setQtde(150);
        static_cast<Bebida*>(novo)->setValidade("12/12/2017");
        static_cast<Bebida*>(novo)->setAcucar(15);
        static_cast<Bebida*>(novo)->setAlcool(6.8);*/
        novo->capturar();
        
        cout << "Digite a data de validade (dd/mm/aaaa): ";
        getline(cin, input);
        static_cast<Bebida*>(novo)->setValidade(input);

        ints = recebeInt("Digite a quantidade de açúcar: ", 0);
        static_cast<Bebida*>(novo)->setAcucar(ints);

        floats = recebeFloat("Digite o teor alcoólico: ", 0);
        static_cast<Bebida*>(novo)->setAlcool(floats);
        if(f->getProdutos()->Busca(&novo)) {
            cout << "Produto já cadastrado" << endl;
            parar();
        }
    }
    if(tipo == "fruta") {
        novo = new Fruta();
        novo->capturar();

        cout << "Digite a data de validade (dd/mm/aaaa): ";
        getline(cin, input);
        static_cast<Fruta*>(novo)->setValidade(input);
        
        ints = recebeInt("Digite o número de frutas: ", 0);
        static_cast<Fruta*>(novo)->setNum(ints);

        cout << "Digite a data de produção (dd/mm/aaaa): ";
        getline(cin, input);
        static_cast<Fruta*>(novo)->setDp(input);
    }
    if(tipo == "doce") {
        novo = new Doce();
        novo->capturar();

        cout << "Digite a data de validade (dd/mm/aaaa): ";
        getline(cin, input);
        static_cast<Doce*>(novo)->setValidade(input);

        ints = recebeInt("Digite a quantidade de açúcar: ", 0);
        static_cast<Doce*>(novo)->setAcucar(ints);

        ints = recebeInt("Tem gluten (1 para sim): ", 0);
        static_cast<Doce*>(novo)->setGluten(false);
        if(ints == 1)
            static_cast<Doce*>(novo)->setGluten(true);

        ints = recebeInt("Tem glicose (1 para sim): ", 0);
        static_cast<Doce*>(novo)->setGlicose(false);
        if(ints == 1)
            static_cast<Doce*>(novo)->setGlicose(true);
    }
    if(tipo == "salgado") {
        novo = new Salgado();
        novo->capturar();

        cout << "Digite a data de validade (dd/mm/aaaa): ";
        getline(cin, input);
        static_cast<Salgado*>(novo)->setValidade(input);

        ints = recebeInt("Digite a quantidade de sódio: ", 0);
        static_cast<Salgado*>(novo)->setSodio(ints);

        ints = recebeInt("Tem glúten (1 para sim): ", 0);
        static_cast<Salgado*>(novo)->setGluten(false);
        if(ints == 1)
            static_cast<Salgado*>(novo)->setGluten(true);

        ints = recebeInt("Tem lactose (1 para sim): ", 0);
        static_cast<Salgado*>(novo)->setLactose(false);
        if(ints == 1)
            static_cast<Salgado*>(novo)->setLactose(true);
    }
    if(tipo == "cd") {
        novo = new CD();
        novo->capturar();

        cout << "Digite o estilo: ";
        getline(cin, input);
        static_cast<CD*>(novo)->setEstilo(input);

        cout << "Digite o nome do artista: ";
        getline(cin, input);
        static_cast<CD*>(novo)->setArtista(input);

        cout << "Digite o nome do álbum: ";
        getline(cin, input);
        static_cast<CD*>(novo)->setAlbum(input);
    }
    if(tipo == "dvd") {
        novo = new DVD();
        novo->capturar();

        cout << "Digite o título: ";
        getline(cin, input);
        static_cast<DVD*>(novo)->setTitulo(input);

        cout << "Digite o gênero: ";
        getline(cin, input);
        static_cast<DVD*>(novo)->setGenero(input);

        cout << "Digite a duracao: ";
        getline(cin, input);
        static_cast<DVD*>(novo)->setDuracao(input);
    }
    if(tipo == "livro") {
        novo = new Livro();
        novo->capturar();

        cout << "Digite o autor: ";
        getline(cin, input);
        static_cast<Livro*>(novo)->setAutor(input);

        cout << "Digite o título: ";
        getline(cin, input);
        static_cast<Livro*>(novo)->setTitulo(input);

        cout << "Digite a editora: ";
        getline(cin, input);
        static_cast<Livro*>(novo)->setEditora(input);

        cout << "Digite o ano de publicação: ";
        getline(cin, input);
        static_cast<Livro*>(novo)->setAnopub(input);
    }
    f->addProduto(novo);
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
        Produto *p = *(f->getProdutos())->Posiciona(selecao);
        
        string input;
        
        cout << "O código é: " << p->getcb() << " (ENTER para manter): ";
        getline(cin, input);
        if(input != "")
            p->setcb(input);

        cout << "A descrição é: " << p->getdescricao() << " (ENTER para manter): ";
        getline(cin, input);
        if(input != "")
            p->setdescricao(input);

        cout << "O tipo é: " << p->gettipo() << " (ENTER para manter): ";
        getline(cin, input);
        if(input != "")
            p->settipo(input);

        stringstream ss;
        ss << "O preço é: " << p->getpreco() << " (0 para manter): ";
        input = ss.str();
        float preco = recebeFloat(input, 0);
        if(preco > 0)
            p->setpreco(preco);

        ss.clear();
        ss << "A quantidade é: " << p->getQtde() << " (0 para manter): ";
        input = ss.str();
        float qtde = recebeInt(input, 0);
        if(qtde > 0)
            p->setQtde(qtde);
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
            }
            tmp = tmp->getProximo();
        }
    }
        
    if(pausa)
        parar();
    return -1;

}

void imprimir(Produto *p) {
    string tipo = p->gettipo();
    minusculas(tipo);
    if(tipo == "bebida")
        cout << *dynamic_cast<Bebida*>(p) << endl;
    else if(tipo == "fruta")
        cout << *dynamic_cast<Fruta*>(p) << endl;
    else if(tipo == "doce")
        cout << *dynamic_cast<Doce*>(p) << endl;
    else if(tipo == "salgado")
        cout << *dynamic_cast<Salgado*>(p) << endl;
    else if(tipo == "cd")
        cout << *dynamic_cast<CD*>(p) << endl;
    else if(tipo == "dvd")
        cout << *dynamic_cast<DVD*>(p) << endl;
    else if(tipo == "livro")
        cout << *dynamic_cast<Livro*>(p) << endl;
    else
        cout << *dynamic_cast<Produto*>(p) << endl;
}

/**
* @brief        Função que imprime a lista de produtos
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    filtro Filtro de listagem (0 = sem filtro, 1 = filtrar por tipo, 2 = filtrar por codigo)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       Número máximo na lista
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
    int j = 0;
    while(tmp) {
        Lista<Produto*> *f = tmp->getValor()->getProdutos();
        Produto *produt;
        for(int i = 0; i < tmp->getValor()->getQtde(); i++) {
            j++;
            f = f->getProximo();
            produt = *f->getValor();
            string tip = produt->gettipo();
            minusculas(tip);
            switch(filtro) {
                case 1:
                    if(tip == ftipo) {
                        cout << "   (" << j << ") ";
                        imprimir(produt);
                    }
                    break;
                case 2:
                    if(produt->getcb() == fcod) {
                        cout << "   (" << j << ") ";
                        imprimir(produt);
                    }
                    break;
                default:
                    cout << "   (" << j << ") ";
                    imprimir(produt);
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
                        //info >> *d;
//                        parar();
                        //tmp->addProduto(d);
                        //conta2++;
                    } else if(tipo == "fruta") {
                        pp = new Fruta();
                        info >> *dynamic_cast<Fruta*>(pp);
                        //info >> *b;
//                        parar();
                        //tmp->addProduto(b);
                        //conta2++;
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
    parar();
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

/**
* @brief        Função que realiza uma venda
* @param[in]    *e Lista de fornecedores com seus produtos
* @param[in]    *v Lista de venda com seus itens
*/
void venda(Lista<Fornecedor> *e, Lista<Venda> *v) {
    //Lista todos os itens do cadastro
    int maximo = impPrLista(e, 0, false);
    //Seleciona um deles
    int selecao = recebeInt("Digite o número do produto (0 para cancelar): ", 0, maximo);
    if(selecao == 0)
        return;
    Venda *nova = new Venda();

    Lista<Fornecedor> *tmp = e;
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

    int qtd = recebeInt("Digite a quantidade: ", 1, 0);
    nova->setQtde(qtd);
    
    v->Insere(*nova);
    
    //Para testes
    cout << "Cód.\t|Desc.\t|Qtde\t|Total" << endl;
    v->Exibe();
    parar();
}

/**
* @brief        Função que imprime a lista de estoque
* @param[inout] *e Lista de Fornecedores do cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número do fornecedor selecionada
*/
int impPrListaEstoque(Lista<Fornecedor> *e, bool pausa) {
    Lista<Fornecedor> *tmp = e;
    while(tmp) {
        Lista<Produto*> *f = tmp->getValor()->getProdutos();
        Produto *produt;
        for(int i = 0; i < tmp->getValor()->getQtde(); i++) {
            f = f->getProximo();
            produt = *f->getValor();
            cout << "   (" << (i + 1) << ") " << produt->getEstoque() << endl;
        }
        tmp = tmp->getProximo();
    }
        
    if(pausa)
        parar();
    return -1;

}