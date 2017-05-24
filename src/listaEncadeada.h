/**
* @file listaEncadeada.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#ifndef _LISTA_H_ // Uso do pré-processador
#define _LISTA_H_ // Definição do identificador do cabeçalho

#include "emprestimo.h"
#include "usuario.h"
#include "livro.h"
#include <vector>
#include <fstream>


/**
* @brief função auxiliar para coparar data passada com data atual
* @ppp dia
* @ppp mes
* @ppp ano
* @rrr true/false
*/
bool check_atrasado(int dia, int mes, int ano){
	time_t agora; // variael para pegar o tempo de maquina atual
	struct tm * agora_struct; // cria um ponteiro de struct de data

	agora = time(NULL); // função para pegar o tempo atual
	agora_struct = localtime(&agora); // modificar o tempo para moso GTM -3
	agora_struct->tm_year += (2017-agora_struct->tm_year); // Modifica a referencia do ao de 117 para 2017

	if (ano < agora_struct->tm_year) { //faz comparação do dia e retorna true para atrasado
		return true;
	}

	else if (mes < agora_struct->tm_mon) { //faz comparação do mes e retorna true para atrasado
		return true;
	}

	else if (dia < agora_struct->tm_mday ) { //faz comparação do ano e retorna true para atrasado
		return true;
	}else{
		return false; // retorna falso para nao atrasado
	}
}
/**
* @brief Fução de separar palavras de uma frase em varias strings
* @ppp in string contendo a frase a ser tratada
* @ppp &palavras Vrctor de string para guardar as palavras separadas
*/
void tratar_texto(string in, vector<string>& palavras){

	int i =0, j = 0;
	string guarda;

	do{ 
		if(in[i] == ';'){
			//guarda += '\0';
			palavras.push_back(guarda);
			guarda = "";
			j++;
		}else{
			guarda += in[i];
			
		}
		j++;
		i++;

		
	}while(in[i] != '\0');

	palavras.push_back(guarda);
}
/**
* @class Lista
* @brief objeto generico com a finalidade de criar e manipular lista de qualquer objeto.
*/
template<typename T>
class Lista {
private:
	T* value; //variavel de objeto de qualuqer tipo
	T* first; // variavel que indica qual o inicio da lista
	T* end; // variavel que indica qual é o ultimo da lista
	int quantidade; // variavel que indica quantidade
public:
	/**
	* @brief Costructor de uma lista de objeto generico
	*/
	Lista();
	//GETTERS
	/**
    * @brief Retorna um ponteiro do objeto limitador inicial
    */
	T* getFirst();
	/**
    * @brief Retorna um ponteiro do objeto limitador final
    */
	T* getEnd();
	/**
    * @brief Retorna a variavel quantidade do objeto
    */
	int getQuantidade();
	//SETTERS
	

	//funçoes
	/**
    * @brief Lista todos os objetos da lista
    */
	void listar();
	/**
    * @brief Iseri objeto generico no final da lista
    * @param T* Generico
    */
	void inserir(T*);
	/**
    * @brief Busca um objeto na lista
    * @param string Recebe uma string para a busca
    * @return curr Retorna objeto encontrado
    */
	T* buscar(string); // buscar por string
	/**
    * @brief Remove objeto da lista buscando por string
    * @param string String com o nome TAG do objeto
    */
	void remover(string); // busca por string
	/**
    * @brief Recebe o nome do arquivo como string e faz leiura e estanciamento dos objetos
    * @param string
    */
	void ler_banco(string );
	/**
    * @brief Tratamento de exeção para a classe Emprestimo
    * @param string Contendo o nome do arquivo
    * @param Lista<Usuario> Ponteiro de uma lista de usuario
    * @param Lista<Livros> ponteiro de uma lista de livros
    */
	void ler_emprestimo(string , Lista<Usuario>* , Lista<Livro>* );
	/**
    * @brief Função especifica para classe Emprestimos; Imprime todos os atrasados
    */
	void atrasados();

};
/**
    * @brief Cria uma lista de objeto generico
    */
template <typename T>
Lista<T>::Lista(){
	this->first = new T();
    this->end = new T();

	first->setNext(end);
	first->setPrevious(NULL);

	end->setNext(NULL);
	end->setPrevious(first);

	quantidade = 0;

}
//GETTERS
/**
    * @brief retorna um ponteiro do objeto limitador inicial
    */
template<typename T>
T* Lista<T>::getFirst(){ return first;}
/**
    * @brief retorna um ponteiro do objeto limitador final
    */
template<typename T>
T* Lista<T>::getEnd(){ return end;}
/**
    * @brief retorna a variavel quantidade
    */
template <typename T>
int Lista<T>::getQuantidade(){ return this->quantidade;}

//FUNÇOES
/**
* @brief Lista todos os objetos da lista
*/
template<typename T>
void Lista<T>::listar(){
	T* curr = first->getNext(); //CRIA UM OBJETO PARA PERCORRER
	cout << "INICIO DA LISTA ";
	while(curr != end){ // PERCORRE IMPRIMINDO ENQUANTO NAO CHEGAR AO FINAL DA LISTA
		cout << "-----------" << endl;
		cout << *curr << endl << endl;
		curr = curr->getNext();
	}
	cout << "FIM DA LISTA ----------------" << endl << endl;

}
/**
* @brief Inseri objeto generico no final da lista
* @param *novo Ponteiro para um objeto generico
*/
template <typename T>
void Lista<T>::inserir(T* novo){ 

	novo->setNext(this->end); 	
	novo->setPrevious(this->end->getPrevious()); 	
	
	novo->getNext()->setPrevious(novo); 	
	novo->getPrevious()->setNext(novo); 	
	
	this->quantidade++;
}

/**
    * @brief Busca e retorna objeto generico
    * @param String para comparar os nomes dos objetos genericos
    * @return curr Retora o objeto encontrado
    */
template<typename T>
T* Lista<T>::buscar(string s){
	T* curr = first->getNext();

	while(curr->TAG != s && curr != end){
		curr = curr->getNext();
	}
	if (curr == end)
	{
		return NULL;
	}



	return curr; // retornar T
}

 /**
    * @brief Remove objeto da lista
    * @param s String com o nome do objeto generico a ser removido
    */
template <typename T>
void Lista<T>::remover(string s){
	
	T* curr = first->getNext();

	while(curr->TAG != s && curr != end){
		curr = curr->getNext();
	}

	unlink(curr);
	delete curr;
	quantidade--;

} 
/**
* @brief Recebe o nome do arquivo e faz a leitura criando objetos genericos
* @param arq Nome do arquivo a ser lido
*/
template<typename T>
void Lista<T>::ler_banco(string arq){
	
	fstream arquivo(arq);
	string linha;

	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			vector<string> palavras; //cria um vector temporario para armazenar a linha tratada

			tratar_texto(linha, palavras);  // trata a linha do banco de dados
			
			T* novo_node = new T(palavras); //Cria novo objeto
			
			palavras.erase(palavras.begin(), palavras.end()); // limpa o vector
			inserir(novo_node);
		}

		arquivo.close();

	}
	else{
		cout << "ARQUIVO NAO ABRIU!" << endl;
	}
}
/**
* @brief Função especifica para leitura de objetos do tipo Emprestimo
* @param arq Nome do arquivo a ser lido
* @param usuario Lista de usuarios
* @param livros Lista de livros
*/
template<typename T>
void Lista<T>::ler_emprestimo(string arq,
								 Lista<Usuario>* usuarios,
								  Lista<Livro>* livros ){
								
	fstream arquivo(arq);
	string linha;

	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			//cria um vector temporario para armazenar a linha tratada
			vector<string> palavras;
			// trata a linha do banco de dados
			tratar_texto(linha, palavras);
			//Criar objeto
			T* novo_node = new T(usuarios->buscar(palavras[0]), livros->buscar(palavras[1]), stoi(palavras[2]), stoi(palavras[3]), stoi(palavras[4]));
			// limpa o vector
			palavras.erase(palavras.begin(), palavras.end());
			inserir(novo_node);
		}

		arquivo.close();

	}
	else{
		cout << "ARQUIVO NAO ABRIU!" << endl;
	}
}
/**
* @brief Função especifica para Emprestimos; Lista todos os emprestimos atrasados
*/
template<typename T>
void Lista<T>::atrasados(){

	T* curr = first->getNext();

	while(curr != end){
		if(check_atrasado(curr->getDia(), curr->getMes(), curr->getAno())){
			char barra = '/';
			cout << "Usuario: " << curr->getUsuario()->getNome() << endl
				 << "Livro: " << curr->getLivro()->getTitulo() << endl
				 << "Devolução atrasada desde " 
				 << curr->getDia()<< barra
				 << curr->getMes()<< barra
				 << curr->getAno()<< endl << endl;
		}
		curr = curr->getNext();
	}


}
#endif // fim da definição _LISTAENCADEADA_H_