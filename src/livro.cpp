/**
* @file livro.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#include "livro.h"

using namespace std;

/**
* @brief Construtor de um objeto a patir de strings como argumento
* @param titulo Titulo do livro
* @param autor Autor do livro*
* @param editora Editora do livro
* @param ano Ano da edição
*/
Livro::Livro(string titulo, string autor, string editora, string ano):
        titulo(titulo),
        autor(autor),
        editora(editora),
        ano(ano),
        next(NULL),
        previous(NULL)
        {}
 /**
* @brief Construtor de um objeto a partir de um vector de string (tras consigo os parametros)
* Utilizado em leitura de banco de dados
* @param palavra Um vector de string 
*/       
Livro::Livro(vector<string>& palavra):
        titulo(palavra[0]),
        autor(palavra[1]),
        editora(palavra[2]),
        ano(palavra[3]),
        next(NULL),
        previous(NULL)
        {}
/**
* Costrutor de um objeto vazio
*/
Livro::Livro():
        titulo(" "),
        autor(" "),
        editora(" "),
        ano(" "),
        next(NULL),
        previous(NULL)
        {}
// GETTERS
/**
* @brief Fução para retornar a variavel titulo do livro.
* @return titulo
*/     
string Livro::getTitulo(){return titulo;}
/**
* @brief Fução para retornar a variavel autor do livro.
* @return autor
*/
string Livro::getAutor(){return autor;}
/**
* @brief Fução para retornar a variavel editora do livro.
* @return editora
*/
string Livro::getEditora(){return editora;}
/**
* @brief Fução para retornar a variavel ano do livro.
* @return ano
*/
string Livro::getAno(){return ano;}
/**
* @brief Fução para retornar o ponteiro da variavel next do livro.
* @return next
*/
Livro* Livro::getNext(){return this->next;}
/**
* @brief Fução para retornar o ponteiro da variavel previous do livro.
* @return previous
*/
Livro* Livro::getPrevious(){return this->previous;}

// SETTERS
/** 
* @brief Função para modificar a variavel titulo do objeto
* @param titulo
*/
void Livro::setTitulo(string titulo){this->titulo = titulo;}
/** 
* @brief Função para modificar a variavel autor do objeto
* @param autor
*/
void Livro::setAutor(string autor){this->autor = autor;}
/** 
* @brief Função para modificar a variavel editora do objeto
* @param editora
*/
void Livro::setEditora(string editora){this->editora = editora;}
/** 
* @brief Função para modificar a variavel ano do objeto
* @param ano
*/
void Livro::setAno(string ano){this->ano = ano;}
/** 
* @brief Função para modificar o ponteiro da variavel next do objeto
* @param next
*/
void Livro::setNext(Livro* proximo){this->next = proximo;}
/** 
* @brief Função para modificar o ponteiro da variavel previous do objeto
* @param previous
*/
void Livro::setPrevious(Livro* anterior){this->previous = anterior;}

// SOBRECARGA DE OPERADORES
// sobrecarga de operadores
/**
* @brief Sobecarga do operador >>
* @param &o
* @param &livro
* @return o
*/
ostream& operator<<(ostream &o, Livro &livro){
   
    o << livro.getTitulo() <<" ;";
    o << livro.getAutor() <<" ;";
    o << livro.getEditora() <<" ;Ano ";
    o << livro.getAno() <<".";

    return o;
}
/**
* @brief Sobecarga do operador <<
* @param &in
* @param &livro
* @return in
*/
istream& operator>>(istream &in, Livro &livro){
    
    string xtitulo, xautor, xeditora, xano;
    cout << "Titulo: ";
    in >> xtitulo;
    cout << "Autor: ";
    in >> xautor;
    cout << "Editora: ";
    in >> xeditora;
    cout << "Ano: ";
    in >> xano;

    livro.setTitulo(xtitulo);
    livro.setAutor(xautor);
    livro.setEditora(xeditora);
    livro.setAno(xano);
    livro.TAG = xtitulo;

    return in;
}
