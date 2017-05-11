/* 
 * File:   Vendedor.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 09:08
 */

#include "Vendedor.h"

Vendedor::Vendedor() {
}

Vendedor::Vendedor(const Vendedor& orig) {
}

Vendedor::~Vendedor() {
}

double Vendedor::getComissao() const {
    return comissao;
}

void Vendedor::setComissao(double comissao) {
    this->comissao = comissao;
}

double Vendedor::getValorVendido() const {
    return valorVendido;
}

void Vendedor::setValorVendido(double valorVendido) {
    this->valorVendido = valorVendido;
}

double Vendedor::calculaSalario() {
    return (Empregado::calculaSalario()+(valorVendido * (1 + comissao)));
}