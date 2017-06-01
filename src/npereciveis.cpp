/**
 * @file	npereciveis.cpp
 * @brief	Implementacao dos métodos das classes derivadas de produto
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @author	Eduardo Rique (luiseduardorique@gmail.com)
 * @since	30/05/2017
 * @date	30/05/2017
 */

#include "produto.h"
#include "subprodutos.h"

/**
* @details Os valores de estilo, artista e nome album são inicializados com vazio
*/
CD::CD() {
    estilo = "";
    artista = "";
    NomeAlbum = "";
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
* @return NomeAlbum do Produto
*/
string CD::getNomeAlbum() {
    return NomeAlbum;
}

/**
* @details O método modifica o NomeAlbum do Produto
* @param   n NomeAlbum
*/
void CD::setNomeAlbum(string n) {
    NomeAlbum = n;
}

/**
* @details Os valores de titulo, genero e duracao são inicializados com vazio
*/
DVD::DVD() {
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

/**
* @details Os valores de titulo, autor, editora e ano de publicacao são inicializados com vazio
*/
Livro::Livro() {
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