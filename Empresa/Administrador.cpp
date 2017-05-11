/* 
 * File:   Administrador.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 08:46
 */

#include "Administrador.h"

Administrador::Administrador() {
}

Administrador::Administrador(const Administrador& orig) {
}

Administrador::~Administrador() {
}

double Administrador::calculaSalario() {
    return (Empregado::calculaSalario() + ajudasDeCusto);
}

double Administrador::getAjudasDeCusto() const {
    return ajudasDeCusto;
}

void Administrador::setAjudasDeCusto(double ajudasDeCusto) {
    this->ajudasDeCusto = ajudasDeCusto;
}

