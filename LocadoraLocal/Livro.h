#ifndef LIVRO_H
#define LIVRO_H
#include "Produto.h"
#include<string>
using namespace std;
class Livro: public Produto
{
private:
    string autor;
    string genero;
public:
    Livro(float _preco, float _quantEstoque, string _nome, string _autor, string _genero);
	Livro();
    void setAutor(string a);
    void setGenero(string g);
    string getAutor();
    string getGenero();
	virtual string GetTipo();
};
#endif // LIVRO_H
