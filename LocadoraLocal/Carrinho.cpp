/* 
 * File:   Carrinho.cpp
 * Author: aluno-cefet
 * 
 * Created on 13 de Março de 2013, 08:31
 */

#include "Carrinho.h"

Carrinho::Carrinho() {
}

Carrinho::Carrinho(const Carrinho& orig) {
}

Carrinho::~Carrinho() {
}
bool Carrinho::addItem(Item *item){
	itens.push_back(item);    
	return true;
}

vector<Item*> *Carrinho::getItem(){
	return &itens;
}

