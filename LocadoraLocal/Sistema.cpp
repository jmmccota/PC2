/* 
 * File:   Sistema.cpp
 * Author: aluno-cefet
 * 
 * Created on 13 de Março de 2013, 08:36
 */

#include "Sistema.h"

Sistema::Sistema() {
}

Sistema::Sistema(const Sistema& orig) {
}

Sistema::~Sistema() {
}

bool Sistema::addVenda(Venda *venda){
	vendas.push_back(venda);

	Carrinho *cc = venda->GetCarrinho();
	vector<Item *>::iterator p;
    for (p = cc->getItem()->begin(); p < cc->getItem()->end(); p++) {
           (*p)->confirmaCompra();
    }
	return true;
}
    
bool Sistema::cadastrar(Produto *produto){
	cesto.push_back(produto);
    return true;
}

bool Sistema::addUsuario(Usuario *usuario){
	usuarios.push_back(usuario);
    return true;
}

vector<Venda*> *Sistema::getVendas(){
	return &vendas;
}
vector<Produto*> *Sistema::getProdutos(){
	return &cesto;
}
vector<Usuario*> *Sistema::getUsuarios(){
	return &usuarios;
}