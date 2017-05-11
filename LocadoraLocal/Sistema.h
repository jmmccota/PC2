/*
 * File:   Sistema.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 08:36
 */

#ifndef SISTEMA_H
#define	SISTEMA_H
#include "Produto.h"
#include "Venda.h"
#include "Usuario.h"
#include <vector>
using namespace std;

class Sistema {

public:
    Sistema();
    Sistema(const Sistema& orig);
    virtual ~Sistema();
    bool cadastrar(Produto *produto);
    bool addVenda(Venda *venda);
	bool addUsuario(Usuario *);
	vector<Venda *> *getVendas();
	vector<Produto *> *getProdutos();
	vector<Usuario *> *getUsuarios();

private:
    vector<Venda *> vendas;
    vector<Produto *> cesto;
	vector<Usuario *> usuarios;


};

#endif	/* SISTEMA_H */

