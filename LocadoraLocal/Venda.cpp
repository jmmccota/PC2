/* 
 * File:   Venda.cpp
 * Author: aluno-cefet
 * 
 * Created on 13 de Março de 2013, 08:32
 */

#include "Venda.h"

long Venda::cont = 0;

Venda::Venda() {
	cont++;
    codigo = cont;
}

Venda::Venda(const Venda& orig) {
}

Venda::~Venda() {
}

Carrinho* Venda::GetCarrinho() const {
    return carrinho;
}

void Venda::SetCarrinho(Carrinho *carrinho) {
    this->carrinho = carrinho;
}

long Venda::GetCodigo() const {
    return codigo;
}


time_t Venda::GetData() const {
    return data;
}

void Venda::SetData(time_t data) {
    this->data = data;
}

void Venda::SetUsuario(Usuario *u){
	usuario = u;
}

Usuario* Venda::GetUsuario() const {
    return usuario;
}

void Venda::setValorTotalCompra(float valor){
	valorTotalCompra = valor;
}

float Venda::GetValorTotalCompra() const{
	return valorTotalCompra;
}
void Venda::setValorFrete(float valor){
	valorFrete = valor;
}

float Venda::GetValorFrete() const{
	return valorFrete;
}

void Venda::setCodigo(int c){
	this->codigo = c;
}