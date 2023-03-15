#include "Livraria.h" // Incluindo arquivos de cabeçalho LVP09_CLIENTE.h e LVP09_MESA

int Livraria::senha = 2411; // Inicializando o static maximoinstancias com o valor 10

Livraria::Livraria(){

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

}
