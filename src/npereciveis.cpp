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
* @details Os valores de estilo, artista e álbum são inicializados com vazio
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
* @return Estilo
*/
string CD::getEstilo() {
    return estilo;
}

/**
* @details O método modifica o estilo
* @param   e Estilo
*/
void CD::setEstilo(string e) {
    estilo = e;
}
/**
* @return Artista
*/
string CD::getArtista() {
    return artista;
}

/**
* @details O método modifica o artista
* @param   a Artista
*/
void CD::setArtista(string a) {
    artista = a;
}
/**
* @return Álbum
*/
string CD::getAlbum() {
    return album;
}

/**
* @details O método modifica o álbum
* @param   n Álbum
*/
void CD::setAlbum(string n) {
    album = n;
}

/**
* @details Retorna uma string com os dados para exportação CSV
*/
string CD::exportar() {
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << estilo << ";" << artista << ";" << album;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/**
* @details Coleta os dados a partir da entrada padrão
*/
void CD::capturar() {
    cout << "Digite o estilo: ";
    getline(cin, estilo);
    cout << "Digite o nome do artista: ";
    getline(cin, artista);
    cout << "Digite o nome do álbum: ";
    getline(cin, album);
}

/** 
* @details O operador é sobrecarregado para representar o CD
* @param	os Referência para stream de saída
* @param	p Referência para o objeto CD a ser impresso
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
* @details O operador é sobrecarregado para representar o CD
* @param	is Referência para stream de entrada
* @param	b Referência para o objeto CD a ser criado com base nos 
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
* @details Os valores de título, gênero e duração são inicializados com vazio
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
* @return Título
*/
string DVD::getTitulo() {
    return titulo;
}

/**
* @details O método modifica o título
* @param   t Tíitulo
*/
void DVD::setTitulo(string t) {
    titulo = t;
}
/**
* @return Gênero
*/
string DVD::getGenero() {
    return genero;
}

/**
* @details O método modifica o gênero
* @param   g Gênero
*/
void DVD::setGenero(string g) {
    genero = g;
}
/**
* @return Duração
*/
string DVD::getDuracao() {
    return duracao;
}

/**
* @details O método modifica a duração
* @param   d Duração
*/
void DVD::setDuracao(string d) {
    duracao = d;
}

/**
* @details Retorna uma string com os dados para exportação CSV
*/
string DVD::exportar() {                                      /**< Retorna uma string com os dados para exportação CSV */
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << titulo << ";" << genero << ";" << duracao;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/**
* @details Coleta os dados a partir da entrada padrão
*/
void DVD::capturar() {
    cout << "Digite o título: ";
    getline(cin, titulo);
    cout << "Digite o gênero: ";
    getline(cin, genero);
    cout << "Digite o nome do duração: ";
    getline(cin, duracao);
}

/** 
* @details O operador é sobrecarregado para representar o DVD
* @param	os Referência para stream de saída
* @param	p Referência para o objeto DVD a ser impresso
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
* @details O operador é sobrecarregado para representar o DVD
* @param	is Referência para stream de entrada
* @param	b Referência para o objeto DVD a ser criado com base nos 
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
* @details Os valores de título, autor, editora e ano de publicação são inicializados com vazio
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
* @return Título
*/
string Livro::getTitulo() {
    return titulo;
}

/**
* @details O método modifica o título
* @param   t titulo
*/
void Livro::setTitulo(string t) {
    titulo = t;
}
/**
* @return Autor
*/
string Livro::getAutor() {
    return autor;
}

/**
* @details O método modifica o autor
* @param   a autor
*/
void Livro::setAutor(string a) {
    autor = a;
}
/**
* @return Editora
*/
string Livro::getEditora() {
    return editora;
}

/**
* @details O método modifica a editora
* @param   e editora
*/
void Livro::setEditora(string e) {
    editora = e;
}

/**
* @return Ano de publicação
*/
string Livro::getAnopub() {
    return anopub;
}

/**
* @details O método modifica o ano de publicação
* @param   a Ano de publicação
*/
void Livro::setAnopub(string a) {
    anopub = a;
}

/**
* @details Retorna uma string com os dados para exportação CSV
*/
string Livro::exportar() {
    stringstream ss;
    ss << dynamic_cast<Produto*>(this)->exportar();
    ss << ";" << autor << ";" << titulo << ";" << editora << ";" << anopub;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/**
* @details Coleta os dados a partir da entrada padrão
*/
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
* @details O operador é sobrecarregado para representar o livro
* @param	os Referência para stream de saída
* @param	p Referência para o objeto livro a ser impresso
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
* @details O operador é sobrecarregado para representar o livro
* @param	is Referência para stream de entrada
* @param	b Referência para o objeto livro a ser criado com base nos 
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