#include "Perfume.h"

Perfume::Perfume(float _preco, float _quantEstoque, string _nome, string _marca, float _ml ):  Produto(_nome,_preco, _quantEstoque), marca(_marca), ml(_ml) {}
Perfume::Perfume(){}
void Perfume::setMarca(string m)
{
    marca = m;
}
void Perfume::setMl(float mili)
{
    ml = mili;
}
string Perfume::getMarca()
{
    return marca;
}
float Perfume::getMl()
{
    return ml;
}
string Perfume::GetTipo(){
	return "Perfume";
}
