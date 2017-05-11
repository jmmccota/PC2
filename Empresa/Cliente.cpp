/* 
 * File:   Cliente.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 08:42
 */

#include "Cliente.h"

Cliente::Cliente() {
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

double Cliente::getCreditoMax() const {
    return creditoMax;
}

void Cliente::setCreditoMax(double creditoMax) {
    this->creditoMax = creditoMax;
}

double Cliente::getValorDevido() const {
    return valorDevido;
}

void Cliente::setValorDevido(double valorDevido) {
    this->valorDevido = valorDevido;
}

void Cliente::obterSaldo() {
    return (creditoMax - valorDevido);
}
