/**
* @file emprestimo.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#include "emprestimo.h"

using namespace std;
/**
* Costrutor de um objeto vazio
*/
Emprestimo::Emprestimo():livro(), 
							usuario(),
							next(NULL),
							previous(NULL)
							{}
/**
* @brief Construtor de um objeto a patir de objetos e inteiros.
* @param usuario Objeto do tipo Usuario
* @param livro Objeto do tipo Livro
* @param dia Dia da devolição
* @param mes Mes da devolição
* @param ano Ano da devolição
*/
Emprestimo::Emprestimo(Usuario* usuario,
							 Livro* livro, int dia, int mes, int ano):
								livro(livro),
								usuario(usuario),
								next(NULL),
								previous(NULL)
								{
									emprestimo.dia = dia;
									emprestimo.mes = mes;
									emprestimo.ano = ano;
								}
/**
* @brief Construtor de um objeto a patir de objetos e inteiros.
* @param usuario Objeto do tipo Usuario
* @param livro Objeto do tipo Livro
*/
Emprestimo::Emprestimo(Usuario* usuario, Livro* livro):
							livro(livro),
							usuario(usuario),
							next(NULL),
							previous(NULL)
							{
								cout << "dia da devolução: ";
								cin >> emprestimo.dia;
								cout << "mes da devolução: ";
								cin >> emprestimo.mes;
								cout << "Ano da devolução: ";
								cin >> emprestimo.ano; 
							}
/**
* @Destrutor
* Deleta o objeto alocado 
*/
Emprestimo::~Emprestimo(){}
// GETTERS
/**
* @brief Fução para retornar o ponteiro do objeto usuario.
* @return usuario
*/
Usuario* Emprestimo::getUsuario(void){ return this->usuario;}
/**
* @brief Fução para retornar o ponteiro do objeto usuario.
* @return livro
*/
Livro* Emprestimo::getLivro(void){ return this->livro;}
/**
* @brief Fução para retornar o ponteiro da variavel next do usuario.
* @return next
*/
Emprestimo* Emprestimo::getNext(){return this->next;}
/**
* @brief Fução para retornar o ponteiro da variavel previous do usuario.
* @return previous
*/
Emprestimo* Emprestimo::getPrevious(){return this->previous;}
/**
* @brief Fução para retornar a variavel dia do usuario.
* @return dia
*/
int Emprestimo::getDia(){return emprestimo.dia;}
/**
* @brief Fução para retornar a variavel mes do usuario.
* @return mes
*/
int Emprestimo::getMes(){return emprestimo.mes;}
/**
* @brief Fução para retornar a variavel ano do usuario.
* @return ano
*/
int Emprestimo::getAno(){return emprestimo.ano;}
//SETTERS
/** 
* @brief Função para modificar o ponteiro da variavel usuario do objeto
* @param usuario
*/
void Emprestimo::setUsuario(Usuario* usuario){this->usuario = usuario;}
/** 
* @brief Função para modificar o ponteiro da variavel livro do objeto
* @param livro
*/
void Emprestimo::setLivro(Livro* livro){this->livro = livro;}
/** 
* @brief Função para modificar o ponteiro da variavel next do objeto
* @param next
*/
void Emprestimo::setNext(Emprestimo* proximo){this->next = proximo;}
/** 
* @brief Função para modificar o ponteiro da variavel previous do objeto
* @param previous
*/
void Emprestimo::setPrevious(Emprestimo* anterior){this->previous = anterior;}

// SOBRECARGA DE OPERADORES
// sobrecarga de operadores
/**
* @brief Sobecarga do operador >>
* @param &o
* @param &emprestimo
* @return o
*/
ostream& operator<<(ostream& o, Emprestimo& emprestimo){
	o << "USUARIO: " << endl << *emprestimo.getUsuario() << endl;
	o << "LIVRO: " << endl << *emprestimo.getLivro() << endl;

	return o;
}
