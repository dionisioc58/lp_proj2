/**
 * @file	npereciveis.cpp
 * @brief	Implementacao dos métodos das classes derivadas de produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"
#include "subproduto.h"

/**
* @details Os valores de estilo, artista e album são inicializados com vazio
*/
CD::CD() {
    tipo = "CD";
    estilo = "";
    artista = "";
    album = "";
}

/**
* @details Destrutor padrão
*/
CD::~CD() {
    //VAZIO
}

/**
* @return estilo do Produto
*/
string CD::getEstilo() {
    return estilo;
}

/**
* @details O método modifica o estilo do Produto
* @param   e estilo
*/
void CD::setEstilo(string e) {
    estilo = e;
}
/**
* @return artista do Produto
*/
string CD::getArtista() {
    return artista;
}

/**
* @details O método modifica o artista do Produto
* @param   a artista
*/
void CD::setArtista(string a) {
    artista = a;
}
/**
* @return Album do Produto
*/
string CD::getAlbum() {
    return album;
}

/**
* @details O método modifica o Album do Produto
* @param   n Album
*/
void CD::setAlbum(string n) {
    album = n;
}

string CD::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << estilo << ";" << artista << ";" << album;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void CD::capturar() {
    cout << "Digite o estilo: ";
    getline(cin, estilo);
    cout << "Digite o nome do artista: ";
    getline(cin, artista);
    cout << "Digite o nome do álbum: ";
    getline(cin, album);
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, CD &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Est. : " << p.getEstilo() << " - ";
    os << "Art. : " << p.getArtista() << " - ";
    os << "Álb. : " << p.getAlbum();
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, CD &b) {
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.estilo, ';');
    getline(is, b.artista, ';');
    getline(is, b.album, ';');

    return is;
}

/**
* @details Os valores de titulo, genero e duracao são inicializados com vazio
*/
DVD::DVD() {
    tipo = "DVD";
    titulo = "";
    genero = "";
    duracao = "";
}

/**
* @details Destrutor padrão
*/
DVD::~DVD() {
    //VAZIO
}

/**
* @return titulo do Produto
*/
string DVD::getTitulo() {
    return titulo;
}

/**
* @details O método modifica o titulo do Produto
* @param   t titulo
*/
void DVD::setTitulo(string t) {
    titulo = t;
}
/**
* @return genero do Produto
*/
string DVD::getGenero() {
    return genero;
}

/**
* @details O método modifica o genero do Produto
* @param   g genero
*/
void DVD::setGenero(string g) {
    genero = g;
}
/**
* @return duracao do Produto
*/
string DVD::getDuracao() {
    return duracao;
}

/**
* @details O método modifica o duracao do Produto
* @param   d duracao
*/
void DVD::setDuracao(string d) {
    duracao = d;
}

string DVD::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << titulo << ";" << genero << ";" << duracao;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void DVD::capturar() {
    cout << "Digite o título: ";
    getline(cin, titulo);
    cout << "Digite o gênero: ";
    getline(cin, genero);
    cout << "Digite o nome do duração: ";
    getline(cin, duracao);
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, DVD &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Tit. : " << p.getTitulo() << " - ";
    os << "Gên. : " << p.getGenero() << " - ";
    os << "Dur. : " << p.getDuracao();
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, DVD &b) {
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.titulo, ';');
    getline(is, b.genero, ';');
    getline(is, b.duracao, ';');

    return is;
}

/**
* @details Os valores de titulo, autor, editora e ano de publicacao são inicializados com vazio
*/
Livro::Livro() {
    tipo = "Livro";
    autor = "";
    titulo = "";
    editora = "";
    anopub = "";
}

/**
* @details Destrutor padrão
*/
Livro::~Livro() {
    //VAZIO
}

/**
* @return titulo do Produto
*/
string Livro::getTitulo() {
    return titulo;
}

/**
* @details O método modifica o titulo do Produto
* @param   t titulo
*/
void Livro::setTitulo(string t) {
    titulo = t;
}
/**
* @return autor do Produto
*/
string Livro::getAutor() {
    return autor;
}

/**
* @details O método modifica o autor do Produto
* @param   a autor
*/
void Livro::setAutor(string a) {
    autor = a;
}
/**
* @return editora do Produto
*/
string Livro::getEditora() {
    return editora;
}

/**
* @details O método modifica o editora do Produto
* @param   e editora
*/
void Livro::setEditora(string e) {
    editora = e;
}

/**
* @return anopub do Produto
*/
string Livro::getAnopub() {
    return anopub;
}

/**
* @details O método modifica o anopub do Produto
* @param   a anopub
*/
void Livro::setAnopub(string a) {
    anopub = a;
}

string Livro::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << autor << ";" << titulo << ";" << editora << ";" << anopub;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

void Livro::capturar() {
    cout << "Digite o autor: ";
    getline(cin, autor);
    cout << "Digite o título: ";
    getline(cin, titulo);
    cout << "Digite a editora: ";
    getline(cin, editora);
    cout << "Digite o ano de publicação: ";
    getline(cin, anopub);
}

/** 
* @details O operador é sobrecarregado para representar a Fornecedor e seus produtos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Fornecedor a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Livro &p) {
    os << *dynamic_cast<Produto*>(&p);
    os << "Aut. : " << p.getAutor() << " - ";
    os << "Tit. : " << p.getTitulo() << " - ";
    os << "Edit.: " << p.getEditora() << " - ";
    os << "Ano. : " << p.getAnopub();
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Fornecedor a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Livro &b) {
    is >> *dynamic_cast<Produto*>(&b);

    getline(is, b.autor, ';');
    getline(is, b.titulo, ';');
    getline(is, b.editora, ';');
    getline(is, b.anopub, ';');

    return is;
}