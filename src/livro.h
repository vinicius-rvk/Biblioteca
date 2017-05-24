/**
* @file livro.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/

#ifndef _LIVRO_H_ // Uso do pré-processador
#define _LIVRO_H_ // Definição do identificador do cabeçalho

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
* @class Livro
* @brief Classe com finalidade de registo de um Livro
*/
class Livro{
private:
	string titulo, //Titulo do livro
			autor, // Autor do livro
			editora, // Editora do livro
			ano; // Ano de publicação do livro
    Livro* next; // poteiro para livro proximo em uma lista encadeada
    Livro* previous; // ponteiro para livro anterior em uma lista encadeada

public:
    /**
    * @brief Marcar os objetos com um unico identificador, tornando assim uma busca generia em todos os tipos de objeto.
    */
    string TAG = titulo;
    /**
     * @brief Construtor de um objeto recebendo todos os parametros
     */
    Livro(string titulo, string autor, string editora, string ano);
    /**
    * Costrutor de um objeto vazio
    */
    Livro();
    /**
    * @brief Construtor de um objeto a partir de um vector de string (tras consigo os parametros)
    * Utilizado em leitura de banco de dados
    */
    Livro(vector<string>& );
    // GETTERS
    /**
     * @brief Função para retornar a variavel titulo de um objeto Livro
     * @return autor
    */
    string getTitulo();
    /**
     * @brief Função para retornar a variavel autor de um objeto Livro
     * @return autor
    */
    string getAutor();
    /**
     * @brief Função para retornar a variavel editora de um objeto Livro
     * @return editora
    */
    string getEditora();
    /**
     * @brief Função para retornar a variavel ano de um objeto Livro
     * @return ano
    */
    string getAno();
    /**
    * @brief retorna um ponteiro do proximo objeto em uma lista encadeada
    */
    Livro* getNext();
    /**
    * @brief retorna um ponteiro do objeto anterior em uma lista encadeada
    */
    Livro* getPrevious();
    /**
     * @brief Função para retornar a variavel titulo de um objeto Livro
     * @return titulo
    */

    // SETTERS
    /**
     * @brief Função para modificar o titulo do objeto
     * @param string titulo
    */
    void setTitulo(string titulo);
    /**
     * @brief Função para modificar o autor do objeto
     * @param string autor
    */
    void setAutor(string autor);
    /**
     * @brief Função para modificar o editora do objeto
     * @param string editora
    */
    void setEditora(string editora);
    /**
     * @brief Função para modificar o editora do objeto
     * @param string editora
    */
    void setAno(string ano);
    /**
    * @brief Função para modificar o ponteiro do proximo objeto
    * @param *proximo
    */
    void setNext(Livro* proximo);
    /**
    * @brief Função para modificar o ponteiro do objeto anterior
    * @param *anteior
    */
    void setPrevious(Livro* anterior);
    // SOBRECARGA DE OPERADORES
    /**
    * @brief função sorecarregada para imprimir o este objeto
    */
    friend ostream& operator<<(ostream&, Livro&);
    /**
    * @brief função sorecarregada para receber o este objeto
    */
    friend istream& operator>>(istream&, Livro&);

};






#endif  // fim da definição _FINAL _LIVROS_H_
