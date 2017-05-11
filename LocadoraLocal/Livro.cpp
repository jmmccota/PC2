#include "Livro.h"

Livro::Livro(float _preco, float _quantEstoque, string _nome, string _autor, string _genero): Produto(_nome,_preco, _quantEstoque){
	this->autor = _autor;
	this->genero = _genero;
}

Livro::Livro(){};

void Livro::setAutor(string a)
{
    autor = a;
}
void Livro::setGenero(string g)
{
    genero = g;
}
string Livro::getAutor()
{
    return autor;
}
string Livro::getGenero()
{
    return genero;
}

string Livro::GetTipo()
{
    return "Livro";
}
