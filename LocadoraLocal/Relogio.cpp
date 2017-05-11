#include "Relogio.h"

Relogio::Relogio(float _preco, float _quantEstoque, string _nome, string _marca, bool _tipo ):  Produto(_nome,_preco, _quantEstoque), marca(_marca), tipo(_tipo) {}
Relogio::Relogio() {}
void Relogio::setMarca(string m)
{
    marca = m;
}
void Relogio::setTipo (bool t)
{
    tipo = t;
}
string Relogio::getMarca()
{
    return marca;
}
bool Relogio::getTipo()
{
    return tipo;
}

string Relogio::GetTipo(){
	return "Relogio";
}
