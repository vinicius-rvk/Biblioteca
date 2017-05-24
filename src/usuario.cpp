/**
* @file usuario.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#include "usuario.h"

using namespace std;
/**
* Costrutor de um objeto vazio
*/
Usuario::Usuario():
	nome(""),
	endereco(""),
	identidade(""),
    next(NULL),
    previous(NULL)
	{}
/**
* @brief Construtor de um objeto a partir de um vector de string (tras consigo os parametros)
* Utilizado em leitura de banco de dados
* @param palavra Um vector de string 
*/
Usuario::Usuario(vector<string>& palavra):
	nome(palavra[0]),
	endereco(palavra[1]),
	identidade(palavra[2]),
    next(NULL),
    previous(NULL)
	{}
/**
* @brief Construtor de um objeto a patir de strings como argumento
* @param nome Nome do usuario
* @param endeeco Endeeço do usuario*
* @param identidade Identidade do usuario
*/
Usuario::Usuario(string nome, string endereco, string identidade):
	nome(nome),
	endereco(endereco),
	identidade(identidade),
    next(NULL),
    previous(NULL)
	{}

	// Usuario::GETTERS
/**
* @brief Fução para retornar a variavel nome do usuario.
* @return nome
*/
string Usuario::getNome(void){ return this->nome;}

/**
* @brief Fução para retornar a variavel endereço do usuario.
* @return endereco
*/
string Usuario::getEndereco(void){ return this->endereco;}
/**
* @brief Fução para retornar a variavel identidade do usuario.
* @return identidade
*/
string Usuario::getIdentidade(void){ return this->identidade;}
/**
* @brief Fução para retornar o ponteiro da variavel next do usuario.
* @return next
*/
Usuario* Usuario::getNext(){return this->next;}
/**
* @brief Fução para retornar o ponteiro da variavel previous do usuario.
* @return previous
*/
Usuario* Usuario::getPrevious(){return this->previous;}


	//SETTERS
/** 
* @brief Função para modificar a variavel nome do objeto
* @param nome
*/
void Usuario::setNome(string nome){this->nome = nome;}
/** 
* @brief Função para modificar a variavel endereço do objeto
* @param endereco
*/
void Usuario::setEndereco(string endereco){this->endereco = endereco;}
/** 
* @brief Função para modificar a variavel identidade do objeto
* @param identidade
*/
void Usuario::setIdentidade(string identidade){this->identidade = identidade;}
/** 
* @brief Função para modificar o ponteiro da variavel next do objeto
* @param next
*/
void Usuario::setNext(Usuario* proximo){this->next = proximo;}
/** 
* @brief Função para modificar o ponteiro da variavel previous do objeto
* @param previous
*/
void Usuario::setPrevious(Usuario* anterior){this->previous = anterior;}

// sobrecarga de operadores
/**
* @brief Sobecarga do operador >>
* @param &o
* @param &usuario
* @return o
*/
ostream& operator<<(ostream& o, Usuario &usuario){
	o << usuario.getNome() << endl;
	o << usuario.getEndereco() << endl;
	o << usuario.getIdentidade() << endl;
	return o;
}
/**
* @brief Sobecarga do operador <<
* @param &in
* @param &usuario
* @return in
*/
istream& operator>>(istream& in, Usuario &usuario){
	string xnome, xendereco, xidentidade;
	cout << "Nome: ";
	in >> xnome;
	cout << "Endereço: ";
	in >> xendereco;
	cout << "Identidade";
	in >> xidentidade;

	usuario.setNome(xnome);
	usuario.setEndereco(xendereco);
	usuario.setIdentidade(xidentidade);
	usuario.TAG = xnome;


	return in;
}