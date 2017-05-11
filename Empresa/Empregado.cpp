/* 
 * File:   Empregado.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 08:36
 */

#include "Empregado.h"

Empregado::Empregado() {
}

Empregado::Empregado(const Empregado& orig) {
}

Empregado::~Empregado() {
}

double Empregado::GetIR() const {
    return IR;
}

void Empregado::SetIR(double IR) {
    this->IR = IR;
}

int Empregado::GetNumeroSecao() const {
    return numeroSecao;
}

void Empregado::SetNumeroSecao(int numeroSecao) {
    this->numeroSecao = numeroSecao;
}

double Empregado::GetSalarioBase() const {
    return salarioBase;
}

void Empregado::SetSalarioBase(double salarioBase) {
    this->salarioBase = salarioBase;
}

void Empregado::calculaSalario() {
    return (salarioBase*(1-IR));
}
