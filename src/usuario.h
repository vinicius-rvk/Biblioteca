/**
* @file usuario.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#ifndef _USUARIO_H_ // Uso do pré-processador
#define _USUARIO_H_ // Definição do identificador do cabeçalho

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
* @class Livro
* @brief Classe com finalidade de registo de um Livro
*/
class Usuario{
private:
	string nome, // Nome do usuario
			endereco, // Endereço do usuario
			identidade; // Identidade do usuario
    Usuario* next; // poteiro para livro proximo em uma lista encadeada
    Usuario* previous; // ponteiro para livro anterior em uma lista encadeada

public:
    /**
    * @brief Marcar os objetos com um unico identificador, tornando assim uma busca generia em todos os tipos de objeto.
    */
	string TAG = nome;
    /**
    * @brief Construtor de um objeto a partir de um vector de string (tras consigo os parametros)
    * Utilizado em leitura de banco de dados
    */	
	Usuario(vector<string>& );
    /**
    * Costrutor de um objeto vazio
    */	
	Usuario();
    /**
    * Costrutor de um objeto completo (utilizado para cadastrar um novo usuario).
    */
	Usuario(string, string, string);

	// GETTERS
    /**
     * @brief Função para retornar a variavel nome de um objeto Livro
     * @return nome
    */
	string getNome(void);
	/**
     * @brief Função para retornar a variavel endereco de um objeto Livro
     * @return edereco
    */
	string getEndereco(void);
	/**
     * @brief Função para retornar a variavel identidade de um objeto Livro
     * @return identidade
    */
	string getIdentidade(void);
	/**
    * @brief retorna um ponteiro do proximo objeto em uma lista encadeada
    */
	Usuario* getNext();
	/**
    * @brief retorna um ponteiro do objeto anterior em uma lista encadeada
    */
	Usuario* getPrevious();

	//SETTERS
	/**
     * @brief Função para modificara a variavel nome do objeto
     * @param nome
    */
	void setNome(string);
	/**
     * @brief Função para modificara a variavel endereco do objeto
     * @param endereco
    */
	void setEndereco(string);
	/**
     * @brief Função para modificara a variavel identidade do objeto
     * @param idenidade
    */
	void setIdentidade(string);
	/**
    * @brief Função para modificar o ponteiro do proximo objeto
    * @param *proximo
    */
	void setNext(Usuario* proximo);
	/**
    * @brief Função para modificar o ponteiro do objeto anterior
    * @param *anteior
    */
	void setPrevious(Usuario* anterior);
	// SOBRECARGA DE OPERADORES 
	/**
    * @brief função sorecarregada para imprimir o este objeto
    */
	friend ostream& operator<<(ostream&, Usuario&);
    /**
    * @brief função sorecarregada para receber o este objeto
    */
	friend istream& operator>>(istream&, Usuario&);
	
};

#endif // fim da definição _USUARIO_H_