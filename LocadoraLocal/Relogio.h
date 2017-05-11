#ifndef RELOGIO_H
#define RELOGIO_H
#include"Produto.h"
#include<string>
using namespace std;


class Relogio : public Produto
{
private:
    string marca;
    bool tipo; //true = analogico    false = digital

public:
    Relogio(float _preco, float _quantEstoque, string _nome, string _marca, bool _tipo );
	Relogio( );
    void setMarca(string m);
    void setTipo (bool t);
    string getMarca();
    bool getTipo();
	virtual string GetTipo();
};

#endif // RELOGIO_H
