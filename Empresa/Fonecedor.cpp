/* 
 * File:   Fonecedor.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 08:24
 */

#include "Fonecedor.h"

Fonecedor::Fonecedor() {
}

Fonecedor::Fonecedor(const Fonecedor& orig) {
}

Fonecedor::~Fonecedor() {
}

double Fonecedor::GetCreditoMax() const {
    return creditoMax;
}

void Fonecedor::SetCreditoMax(double creditoMax) {
    this->creditoMax = creditoMax;
}

double Fonecedor::GetValorDevido() const {
    return valorDevido;
}

void Fonecedor::SetValorDevido(double valorDevido) {
    this->valorDevido = valorDevido;
}
void Fonecedor::obterSaldo() {
    return (creditoMax-valorDevido);
}
