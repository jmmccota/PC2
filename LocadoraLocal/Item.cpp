/* 
 * File:   Item.cpp
 * Author: aluno-cefet
 * 
 * Created on 13 de Março de 2013, 08:24
 */

#include "Item.h"

Item::Item() {
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

float Item::GetPreco() const {
    return preco;
}

void Item::SetPreco(float preco) {
    this->preco = preco;
}

Produto* Item::GetProduto() const {
    return produto;
}

void Item::SetProduto(Produto* produto) {
    this->produto = produto;
}

float Item::GetQuantidade() const {
    return quantidade;
}

void Item::SetQuantidade(float quantidade) {
    this->quantidade = quantidade;
}

void Item::confirmaCompra() {
	float i = produto->GetQuantNoEstoque()-quantidade;
	produto->SetQuantNoEstoque(i);
}