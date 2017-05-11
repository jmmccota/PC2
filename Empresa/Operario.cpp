/* 
 * File:   Operario.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 09:01
 */

#include "Operario.h"
#include "Empregado.h"

Operario::Operario() {
}

Operario::Operario(const Operario& orig) {
}

Operario::~Operario() {
}

double Operario::GetComissao() const {
    return comissao;
}

void Operario::SetComissao(double comissao) {
    this->comissao = comissao;
}

double Operario::GetValorProducao() const {
    return valorProducao;
}

void Operario::SetValorProducao(double valorProducao) {
    this->valorProducao = valorProducao;
}

double Operario::calculaSalario() const {
    return (Empregado::calculaSalario()+(valorProducao*(1+comissao)));
}
