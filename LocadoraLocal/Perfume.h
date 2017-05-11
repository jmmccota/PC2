#ifndef PERFUME_H
#define PERFUME_H
#include<string>
#include "Produto.h"
using namespace std;


class Perfume : public Produto
{
private:
    string marca;
    float ml;

public:
    Perfume( float _preco, float _quantEstoque, string _nome, string _marca, float _ml );
	Perfume();
    void setMarca(string m);
    void setMl(float mili);
    string getMarca();
    float getMl();
	virtual string GetTipo();

};

#endif // PERFUME_H
