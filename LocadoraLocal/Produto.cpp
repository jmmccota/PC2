#include "Produto.h"
int Produto::cont = 0;

Produto::Produto() {
	cont++;
    codigo = cont;
}

Produto::Produto(string _nome, float _preco, float _quantidade) {
    nome = _nome;
    preco = _preco;
    quantNoEstoque = _quantidade;
	cont++;
    codigo = cont;
}

Produto::Produto(const Produto& orig) {

}

Produto::~Produto() {
}

int Produto::GetCodigo() const {
    return codigo;
}

void Produto::SetCodigo(int codigo) {
    this->codigo = codigo;
}

float Produto::GetPreco() const {
    return preco;
}

void Produto::SetPreco(float preco) {
    this->preco = preco;
}

float Produto::GetQuantNoEstoque() const {
    return quantNoEstoque;
}

void Produto::SetQuantNoEstoque(float quantNoEstoque) {
    this->quantNoEstoque = quantNoEstoque;
}

string Produto::GetNome() const {
    return nome;
}

void Produto::SetNome(string nome) {
    this->nome = nome;
}
