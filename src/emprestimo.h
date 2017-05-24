/**
 *@file emprestimo.h
 *@autor Roberto Vinicius Kuo <viniciusrvk@gail.com>
 *
 */
#ifndef _EMPRESTIMO_H_ // Uso do pré-processador
#define _EMPRESTIMO_H_ // Definição do identificador do cabeçalho

#include <iostream>
#include "livro.h"
#include "usuario.h"
#include <ctime>

using namespace std;


/**
 * @brief estrutura para guardar uma data
 */
struct data
{
	int dia,
		mes,
		ano;
};

/**
*	@class Emprestimo
*	@brief Objeto com a finalidade de guardar um registro de emprestimo
 */
class Emprestimo 
{
private:
	Livro* livro; /** Objeto Livro; mais informaçoes ver arquivo livro.h / livro.cpp */
	Usuario* usuario; /** Objeto Usuario; mais informaçoes ver arquivo usuario.h / usuario.cpp */
	data emprestimo; /** Para guardar uma data*/
	Emprestimo* next; /** Função de apontar para o proximo em uma lista */
    Emprestimo* previous; /** Função de apontar para o anterior em uma lista */


public:
	/**
	* Costructor
	* Costroi um objeto vazio
	*/
	Emprestimo();
	/**
	* Costructor
	* @brief Costroi um objeto com informaçoes completas.
	* Recebe um ponteiro de um objeto do tipo Usuario e do tipo Livro, inteiros para data. 
	* Utilizado mais para leitra de banco de dados
	*/
	Emprestimo(Usuario*, Livro*, int, int, int);
	/**
	* Costructor
	* @brief Costroi um objeto recebendo dois objetos dos tipos Usuario e Livro
	* Recebe um ponteiro de um objeto do tipo Usuario e do tipo Livro.
	* Utilizado para cadastrar um novo obeto manualmene (desde que usuario e livro estejam cadastrados)
	*/
	Emprestimo(Usuario*, Livro*);
	/**
	* @Destrutor
	* Deleta o objeto alocado 
	*/
	~Emprestimo();
	// GETTERS
	/**
	* @brief função para retornar o objeto Livro
	* 
	*/
	Livro* getLivro(void);
	/**
	* @brief função para retornar o objeto Usuario
	* 
	*/
	Usuario* getUsuario(void);
	/**
	* @brief função para retornar o objeto proximo em uma lista encadeada
	* 
	*/
	Emprestimo* getNext();
	/**
	* @brief função para retornar o objeto anterior em uma lista ecadeada
	* 
	*/
	Emprestimo* getPrevious();
	/**
	* @brief função para retornar o dia de devolução do livro
	*/
	int getDia();
	/**
	* @brief função para retornar o mes de devolução do livro
	*/
	int getMes();
	/**
	* @brief função para retornar o ano de devolução do livro
	*/
	int getAno();
	//SETTERS
	/**
	* @brief função para modificar o objeto Livro
	*/
	void setLivro(Livro*);
	/**
	* @brief função para modificar o objeto Usuario
	*/
	void setUsuario(Usuario*);
	/**
	* @brief função para modificar o objeto proximo em uma lista encadeada
	*/
	void setNext(Emprestimo* proximo);
	/**
	* @brief função para modificar o objeto anterior em uma lista encadeada
	*/
	void setPrevious(Emprestimo* anterior);


	/**
	* @brief função sobrecarregada para imprimir o objeto
	*/
	friend ostream& operator<<(ostream&, Emprestimo&);
	
};

#endif // fim da definição _EMPRESTIMO_H_