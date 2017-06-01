/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     15/05/2017
*/

#include "tarefa3/bancodados.h"

/**
* @brief        Função que coleta o nome para o cadastro de uma turma
* @return       Nome da turma
*/
string inputTurma() {
    string nome;
    cout << "Digite o nome da turma: ";
    getline(cin, nome);
    return nome;
}

/**
* @brief        Função que coleta os dados para cadastro de um aluno
* @return       Funcionário coletado
*/
Aluno inputAluno() {
    //Coleta dados do aluno
    string input;
    Aluno novo;

    cout << "Digite o nome do aluno: ";
    getline(cin, input);
    novo.setNome(input);

    cout << "Digite a matrícula do aluno: ";
    getline(cin, input);
    novo.setMatricula(input);

    int faltas = recebeInt("Digite a quantidade de faltas: ", 0);
    novo.setFaltas(faltas);

    float nota = recebeFloat("Digite a nota: ", 0);
    novo.setNota(nota);
    
    return novo;
}

/**
* @brief        Função que verifica se uma turma já existe no cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    nome Nome da turma a ser verificada
* @return       Retorna true caso já exista
*/
bool existeTurma(Turma *e, int n, string nome) {
    //Testa se já existe no cadastro
    for(int i = 0; i < n; i++) {
        if(e[i].getNome() == nome) {
            cout << "Turma já cadastrada!" << endl;
            return true;
        }
    }
    return false;
}

/**
* @brief        Função que realiza o cadastro uma turma
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *cadTurma(Turma *e, int &n) {
    string nome = inputTurma();
    if(existeTurma(e, n, nome))
        return e;

    Turma *r = new Turma[n + 1];
    
    //Se já tem Turmas, aumenta o vetor, copia a antiga lista para um novo maior
    int j = 0;
    for(int i = 0; i < n; i++) {
        r[j].setNome(e[i].getNome());
        r[j].setAlunos(e[i].getAlunos());
        j++;
    }
    if(n > 0)
        delete[] e;

    r[n++].setNome(nome); //Guarda a nova turma informada
    
    return r;
}

/**
* @brief        Função que remove uma turma do cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após a exclusão
*/
Turma *delTurma(Turma *e, int &n) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a remoção (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(selecao > (n - 1)) {
        cout << "Seleção inválida!" << endl;
        return e;
    }

    Turma *r = new Turma[n - 1];

    //Se já tem turmas, diminui o vetor, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < n; i++)
        if(i != selecao) {
            r[j].setNome(e[i].getNome());
            r[j].setAlunos(e[i].getAlunos());
            j++;
        }

    delete[] e;
    n--;
    return r;
}

/**
* @brief        Função que adiciona um aluno à uma turma (apresenta escolha)
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *addAl(Turma *e, int n) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    Aluno f;
    f = inputAluno();
    e[selecao].addAluno(f);
    return e;
}

/**
* @brief        Função que adiciona alunos à uma turma (apresenta escolha),
*               carregando-os apartir de um arquivo CSV
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *addAlArq(Turma *e, int n, bool pausa) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a adição (0 para cancelar): ", 0);
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
    Aluno f;
    while(!lista.eof()) {
        lista >> f;
        linhas++;
        if(f.getNome() != "\n") {
            e[selecao].addAluno(f);
            funcs++;
        }
    }
    lista.close();
    cout << "Importação concluída com sucesso! " << endl;
    cout << linhas << " linhas no arquivo." << endl;
    cout << funcs << " alunos cadastrados." << endl;

    if(pausa) {
        cin.ignore();
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }

    return e;
}

/**
* @brief        Função que remove um aluno de uma turma (apresenta escolha)
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *delAl(Turma *e, int n) {
    if(n == 0)
        return e;

    int empsel = impAl(e, n, false, false); //Captura a turma selecionada
    int selecao = recebeInt("Digite o número do aluno à remover (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(!e[empsel].delAluno(selecao))
        cout << "Não foi possível remover!" << endl;
    return e;
}

/**
* @brief        Função que imprime as turmas no cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
void impTurmas(Turma *e, int n, bool pausa) {
    cout << "Lista de turmas cadastradas: " << endl;
    for(int i = 0; i < n; i++)
        cout << "-- (" << (i + 1) << ") " << e[i] << endl;
    cout << endl;
    if(pausa) {
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }
}

/**
* @brief        Função que imprime a lista de alunos de uma ou todas 
                as turmas do cadastro
* @param[inout] *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    all "true" imprime todos os alunos de todas as turmas
                "false" imprime apenas os alunos de uma turma (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número da turma selecionada
*/
int impAl(Turma *e, int n, bool all, bool pausa) {
    if(n == 0)
        return -1;
    if(!all) {      //Imprime todos os alunos de uma turma
        impTurmas(e, n, false);
        int selecao = recebeInt("Digite o número da turma (0 para cancelar): ", 0);
        if(selecao == 0)
            return -1;
        selecao--;  //O usuário vai digitar o número com base em 1

        if(e[selecao].getQtde() > 0) {
            cout << "Alunos da turma " << e[selecao].getNome() << endl;
            Lista<Aluno> *f = e[selecao].getAlunos();
            Aluno alun;
            //for(int i = 0; i < e[selecao].getQtde(); i++) {
            for(int i = 0; i < e[selecao].getQtde(); i++) {
                f = f->getProximo();
                alun = f->getValor();
                cout << "   (" << (i + 1) << ") " << alun << endl;
            }

        } else
            cout << "Nenhum aluno na turma selecionada." << endl;
        
        if(pausa) {
            cout << "Pressione ENTER para continuar...";
            string pausa;
            getline(cin, pausa);
        }
        return selecao;
    } else {        //Imprime todos os funcionários de todas as empresas
        for(int j = 0; j < n; j++) {
            if(e[j].getQtde() > 0) {
                cout << "Alunos da turma " << e[j].getNome() << endl;
                Lista<Aluno> *f = e[j].getAlunos();
                Aluno alun;
                for(int i = 0; i < e[j].getQtde(); i++) {
                    f = f->getProximo();
                    alun = f->getValor();
                    cout << "   (" << (i + 1) << ") " << alun << endl;
                }
            }
        }
        
        if(pausa) {
            cout << "Pressione ENTER para continuar...";
            string pausa;
            getline(cin, pausa);
        }
        return -1;
    }
}

/**
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
*/
void salvarBD(string nome, Turma *e, int n) {
    ofstream saida(nome);
    if(!saida) {
        cout << "Não foi possível abrir o arquivo para salvar." << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        saida << e[i].exportar() << endl;
        Lista<Aluno> *aa = e[i].getAlunos();
        for(int j = 0; j < e[i].getQtde(); j++) {            
            aa = aa->getProximo();
            saida << aa->getValor().exportar() << endl;
        }
    }

    saida.close();
    cout << "Banco de dados salvo com sucesso!" << endl;
}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *abrirBD(string nome, Turma *e, int &n) {
    ifstream entrada(nome);
    if(!entrada) {
        cout << "Não foi possível abrir o arquivo de dados." << endl;
        return e;
    }
    string texto;
    stringstream info;
    n = 0;
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto.substr(0, 5) == "turma")
            n++;
    }
    Turma *r = new Turma[n];
    
    int conta = -1;
    entrada.clear();
    entrada.seekg(0);
    
    Aluno f;
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto.substr(6);

            if(texto.substr(0, 6) == "turma;")
                info >> r[++conta];

            if(texto.substr(0, 6) == "aluno;") {
                if(conta > -1) {
                    info >> f;
                    r[conta].addAluno(f);
                }
            }
        }   
    }
    entrada.close();
    cout << "Recuperação concluída com sucesso!" << endl;

    return r;
}