#include "Livraria.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA

int Livraria::senha = 2411; // Inicializando o static senha como 2411

Livraria::Livraria(){
    ifstream arquivo1; // Variaveis auxiliares para manipulação de arquivos
    string nome, autor, isbn, tipoficcao, tipo, tipomidia, narrativa; 
    int ano, ranking;
    double preco; 
    arquivo1.open("listaficcao.txt"); // abre arquivo para leitura
    if(arquivo1.is_open()){ // caso o arquivo1 esteja aberto:
	    while(!arquivo1.eof()){ // enquanto nao for fim de arquivo...
        
		    getline(arquivo1, nome); // metodos getline e cin para recebimento a partir do arquivo e colocação nas variaveis

			if (arquivo1.eof())  //esta solucao nao eh muito elegante para c++
				break;
            
			getline(arquivo1,autor);
            getline(arquivo1,tipoficcao);
            getline(arquivo1,narrativa);
            arquivo1>>isbn;
            arquivo1>>preco;
            arquivo1>>ano;
            Ficcao livroficcao(tipoficcao, narrativa); // Criando objeto do tipo Ficcao 
            livroficcao.setNome(nome); // Usando métodos set para setar os dados do objeto livroficcao
            livroficcao.setAno(ano);
            livroficcao.setAutor(autor);
            livroficcao.setIsbn(isbn);
            livroficcao.setPreco(preco);
            livrosficcao.push_back(livroficcao); // Inserindo o objeto no vetor dos livros de ficção
            arquivo1.ignore();
		} 
    }
    else{ // Caso não seja possivel abrir o arquivo txt.
		cout<<"Não foi possível abrir o arquivo de livros de ficção!"<<endl;
	}
    arquivo1.close(); // Fecha o arquivo

    ifstream arquivo2;
    arquivo2.open("listanaoficcao.txt"); // abre arquivo para leitur
    if(arquivo2.is_open()){ // LIVROS FICÇÃO
	    while(!arquivo2.eof()){ // enquanto nao for fim de arquivo...
		    getline(arquivo2,nome);
			if (arquivo2.eof())  // Caso chegue no fim do arquivo, sai do while
				break;
 
			getline(arquivo2,autor); // metodos getline e cin para recebimento a partir do arquivo e colocação nas variaveis
            getline(arquivo2,tipo);
            getline(arquivo2,tipomidia);
			arquivo2>>isbn;
			arquivo2>>preco;
            arquivo2>>ano;
            arquivo2>>ranking;
            Naoficcao livronaoficcao(tipo, tipomidia, ranking); // Criando objeto do tipo Naoficcao 
            livronaoficcao.setAno(ano);
            livronaoficcao.setNome(nome);
            livronaoficcao.setAutor(autor);
            livronaoficcao.setIsbn(isbn);
            livronaoficcao.setPreco(preco);
            livrosnaoficcao.push_back(livronaoficcao);
            arquivo2.ignore();
		} 
    }
    else{ // Caso não haja arquivo, informa erro:
		cout<<"Não foi possível abrir o arquivo de livros de não ficção!"<<endl;
	}
    arquivo2.close(); // Fecha o arquivo
}

bool Livraria::login(int senha) const{ // Método de login do funcionário
    if (this->senha == senha){ // Caso a senha informada na main seja diferente da já pré infomrada na classe, retorna false
        return true;
    }
    return false;
}

bool Livraria::cadastrarLivroF(Ficcao livro){
    for(unsigned i(0); i < livrosficcao.size(); i++){ // Repetindo para a lista com n produto
        if (livro.getIsbn() == livrosficcao[i].getIsbn()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            return false;
        }
    }
    livrosficcao.push_back(livro);
    return true;
}

bool Livraria::cadastrarLivroNF(Naoficcao livro){
    for(unsigned i(0); i < livrosnaoficcao.size(); i++){ // Repetindo para a lista com n produto
        if (livro.getIsbn() == livrosnaoficcao[i].getIsbn()){ // Caso a string carregada da main seja igual a contida no método getNome, do nésimo Produto:
            return false;
        }
    }
    livrosnaoficcao.push_back(livro);
    return true;
}


bool Livraria::mostrarLivrosF(){ // Método para mostrar livros do vetor livrosficcao
    sort(livrosficcao.begin(), livrosficcao.end(), [](const auto& aux1, const auto& aux2 ) 
    {
        return aux1.nome < aux2.nome;
    }); // Função para realizar a ordenação dos elementos pela ordem alfabetica. De modo que aux1 e aux2 são objetos auxiliares para realizar a comparação.
    for(unsigned i(0); i < livrosficcao.size(); i++){ // For repetindo para o vetor com n livrosficcao
        cout << "===============LISTA DE LIVROS DE FICÇÃO====================" << endl; // Imprimindo dados de livrodeficção 
        cout << "Nome do livro: " << livrosficcao[i].getNome() << endl; // Carregando da posição i os dados do livrodeficção 
        cout << "Autor do livro: " << livrosficcao[i].getAutor() << endl; 
        cout << "Tipo de Ficção: " << livrosficcao[i].getTipoficcao() << endl; 
        cout << "Narrativa: " << livrosficcao[i].getNarrativa() << endl; 
        cout << "Código ISBN: " << livrosficcao[i].getIsbn() << endl; 
        cout << "Ano do Livro: " << livrosficcao[i].getAno() << endl; 
        cout << "Preço do Livro: " << livrosficcao[i].getPreco() << endl; 
    }
    return true; // Retorna true
}

bool Livraria::mostrarLivrosNF(){ // Método para mostrar livros do vetor livrosnaoficcao
    sort(livrosnaoficcao.begin(), livrosnaoficcao.end(), [](const auto& aux1, const auto& aux2 )
    {
        return aux1.getRanking() < aux2.getRanking();
    }); // Função para realizar a ordenação dos elementos pela ordem de ranking. De modo que aux1 e aux2 são objetos auxiliares para realizar a comparação de cada elemento.
    for(unsigned i(0); i < livrosnaoficcao.size(); i++){ // For repetindo para o vetor com n clientes
        cout << "=============== LISTA DE LIVROS DE NÃO-FICÇÃO ====================" << endl; // Imprimindo dados de livronaoficcao  
        cout << "Nome do livro: " << livrosnaoficcao[i].getNome() << endl; // Carregando da posição i os dados de livronaoficcao 
        cout << "Autor do livro: " << livrosnaoficcao[i].getAutor() << endl; 
        cout << "Tipo do livro: " << livrosnaoficcao[i].getTipo() << endl;
        cout << "Tipo de Mídia: " << livrosnaoficcao[i].getTipomidia() << endl;
        cout << "Ranking do livro: " << livrosnaoficcao[i].compararanking(livrosnaoficcao[i].getRanking()) << "  Númerico: "<< livrosnaoficcao[i].getRanking() <<endl;
        cout << "Código ISBN: " << livrosnaoficcao[i].getIsbn() << endl; 
        cout << "Ano do Livro: " << livrosnaoficcao[i].getAno() << endl; 
        cout << "Preço do Livro: " << livrosnaoficcao[i].getPreco() << endl; 
    }
    return true; // retorna true
}

bool Livraria::venderLivroF(string isbn){ // Função para vender um livro de ficção, carregando o Isbn da main
    for(unsigned i(0); i < livrosficcao.size(); i++){ // Repetindo para a lista com n livrosficcao
        if (isbn == livrosficcao[i].getIsbn()){ // Caso a string carregada da main seja igual a contida no método getIsbn, do nésimo livrodeficção:
            livrosficcao.erase(livrosficcao.begin()+i); // Exclui da posição inicial + i do vetor, o livro com o isbn informado
            return true; // retorna true
        }
    }
    return false; // caso o livro não seja achado, retorna false
}

bool Livraria::venderLivroNF(string isbn){ // Função para vender um livro de ficção, carregando o Isbn da main
    for(unsigned i(0); i < livrosnaoficcao.size(); i++){ // Repetindo para a lista com n livronaoficcao
        if (isbn == livrosnaoficcao[i].getIsbn()){ // Caso a string carregada da main seja igual a contida no método getIsbn, do nésimo livronaoficcao:
            livrosnaoficcao.erase(livrosnaoficcao.begin()+i); // Exclui da posição inicial + i do vetor, o livro com o isbn informado
            return true; // retorna true
        }
    }
    return false; // caso o livro não seja achado, retorna false
}

Livraria::~Livraria(){ // Destrutor 
	ofstream arquivo1;
	arquivo1.open("listaficcao.txt", ios::trunc);
//	ofstream arquivo("listaLivros.txt", ios::trunc);

	if (arquivo1.is_open()){
		for (unsigned i=0;i<livrosficcao.size();i++){
			arquivo1<<livrosficcao[i].getNome()<<endl;
			arquivo1<<livrosficcao[i].getAutor()<<endl;
            arquivo1<<livrosficcao[i].getTipoficcao()<<endl;
            arquivo1<<livrosficcao[i].getNarrativa()<<endl;
			arquivo1<<livrosficcao[i].getIsbn()<<endl;
			arquivo1<<livrosficcao[i].getPreco()<<endl;
            arquivo1<<livrosficcao[i].getAno()<<endl;
		}
	}else{
		cout<<"Não foi possível abrir o arquivo de não ficção!"<<endl;
	}
	
    arquivo1.close();  //fecha arquivo
    ofstream arquivo2;
	
    arquivo2.open("listanaoficcao.txt", ios::trunc);
	if (arquivo2.is_open()){
		for (unsigned i=0;i<livrosnaoficcao.size();i++){
			arquivo2<<livrosnaoficcao[i].getNome()<<endl;
			arquivo2<<livrosnaoficcao[i].getAutor()<<endl;
            arquivo2<<livrosnaoficcao[i].getTipo()<<endl;
            arquivo2<<livrosnaoficcao[i].getTipomidia()<<endl;
            arquivo2<<livrosnaoficcao[i].getIsbn()<<endl;
			arquivo2<<livrosnaoficcao[i].getPreco()<<endl;
            arquivo2<<livrosnaoficcao[i].getAno()<<endl;
            arquivo2<<livrosnaoficcao[i].getRanking()<<endl;

		}
	}else{
		cout<<"Não foi possível abrir o arquivo de não ficção!"<<endl;
	}
	
	arquivo2.close();  //fecha arquivo

}
