//	Lista.h
//	
//	Criada por Roberto Vinicius Kuo
//
#include <iostream>
#include "listaEncadeada.h"

using namespace std;

/**
* @brief Funçao para operação 1
* @param lista_livro Uma lista de livros para a busca 
*/
void buscar_livro(Lista<Livro>* lista_livro){
	string str_1;

	cout << "Titulo do livro que deseja buscar: ";
	cin.ignore(); // para nao dar erro no getline
	getline(cin, str_1);
	
	if(lista_livro->buscar(str_1) != NULL){ // caso livro nao exista, sera retornado NULL
		cout << *lista_livro->buscar(str_1) << endl << endl;
	}
	else{
		cout << "Livro nao encontrado." << endl;
	}
}
/**
* @brief Função para a operação 2
* @param lista_emprestimo
* @param lista_usuario Lista contendo todos os usuarios
* @param lista_livros Lista contendo todos os livros
*/
void cadastrar_emprestimo(Lista<Emprestimo>* lista_emprestimo, 
			Lista<Usuario>* lista_usuario, 
			Lista<Livro>* lista_livro){
	string str_1, str_2;

	cout << "Digite o nome do usuario que solicitou o emprestimo: ";
	cin.ignore(); // função de limpar o buffer para nao dar erro no getline
	getline(cin, str_1); 
	cin.ignore(); // ignora o buffer

	if(lista_usuario->buscar(str_1) != NULL){ // casa nao exista o usuario
		
		cout << "Digite o titulo do livro a ser emprestado: ";  
		getline(cin, str_2);

		if(lista_livro->buscar(str_2) != NULL){ // caso nao exista o livro
			
			Emprestimo* novo_emprestimo = new Emprestimo(lista_usuario->buscar(str_1), lista_livro->buscar(str_2));

			lista_emprestimo->inserir(novo_emprestimo);
			
			cout << "Emprestimo cadastrado com sucesso!" << endl;
		}else{
			cout << "Livro nao encontrado no nosso banco de dados." << endl;
		}
	}else {
		cout << "Usuario não cadastrado." << endl;
	}
}

/**
* @brief Função principal
*/
int main (void){
	int operacao; // variavel para ser usada na seleção da operação desejada

	string banco_livro = "livros.txt"; // Nome do arquivo
	string banco_usuario = "usuario.txt"; // Nome do arquivo
	string banco_emprestimo = "emprestimo.txt"; // Nome do arquivo

	Lista<Usuario>* lista_usuario = new Lista<Usuario>(); 
	Lista<Livro>* lista_livro = new Lista<Livro>();
	Lista<Emprestimo>* lista_emprestimo = new Lista<Emprestimo>();

	lista_usuario->ler_banco(banco_usuario);
	lista_livro->ler_banco(banco_livro);
	lista_emprestimo->ler_emprestimo(banco_emprestimo, lista_usuario, lista_livro);


/*
*/
	cout << "Operaçoes ----" << endl;
	cout << "(1) - Buscar livro." << endl;
	cout << "(2) - Realizar emprestimo." << endl;
	cout << "(3) - Emprestimos atrasados." << endl;
	cin >> operacao;

	switch (operacao){
		case 1 :
				buscar_livro(lista_livro);
				break;
		case 2 :
				cadastrar_emprestimo(lista_emprestimo, lista_usuario, lista_livro);
				break;
		case 3 :
				lista_emprestimo->atrasados();
				break;
		default: 
				cout << "Operação não existente.";
	}		

	
	

	//cout << "Deu certo, Vlww!" << endl;

	return 0;
}

 