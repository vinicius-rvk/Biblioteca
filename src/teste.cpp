#include <iostream>
#include <string>
#include <ctime>
using namespace std;


bool check_atrasado(int dia, int mes, int ano){
	time_t agora;
	struct tm * agora_struct;

	agora = time(NULL);
	agora_struct = localtime(&agora);
	agora_struct->tm_year += (2017-agora_struct->tm_year);

	if (ano < agora_struct->tm_year) {
		cout << "O livro está atrasado." << endl;
		return true;
	}

	else if (mes < agora_struct->tm_mon) {
		cout << "O livro está atrasado." << endl;
		return true;
	}

	if (dia < agora_struct->tm_mday ) {
		cout << "O livro está atrasado." << endl;
		return true;
	}

	cout << "O livro está dentro do prazo." << endl;

return false;

}
/*#include <vector>
#include <fstream>



  *Funcão da internet http://www.arquivodecodigos.net/dicas/2-como-quebrar-separar-uma-string-usando-ponto-e-virgula-como-delimitador-1301.html
  *Recebe uma strings, um char delimitador e um vetor de strings vazio
  *A string recebida e uma das linhas dos textos lidos
  

void separar(string& str, char delim, vector<string>& pedacos) {
    string::size_type i = 0;
    string::size_type j = str.find(delim);

    while (j != string::npos) {
        pedacos.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(delim, j);

        if (j == string::npos)
            pedacos.push_back(str.substr(i, str.length()));
    }
}
void tratar_texto(string in, vector<string>& palavras){

	//vector<string> palavras;
	int i =0, j = 0;
	string guarda;

	do{ 
		if(in[i] == ';'){
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


void ler(string arq){
	
	fstream arquivo(arq);
	string linha;


	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			vector<string> palavras;

			//separar(linha, ';', palavras);
			tratar_texto(linha, palavras);
			cout << palavras[0] << endl << palavras[1] << endl;
			palavras.erase(palavras.begin(), palavras.end());
		}
		arquivo.close();

	}
	else{
		cout << "ARQUIVO NAO ABRIU!" << endl;
	}
}
*/
int main(void){
	
	int dia, mes, ano;
		cin >> dia;
		cin >> mes; 
		cin >> ano;

	if(check_atrasado(dia, mes, ano)){
		cout << "Esta atrasado!" << endl;
	}



	return 0;
}


