/* 
 * File:   ContainerRefrigerado.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 09:30
 */

#include "ContainerRefrigerado.h"

ContainerRefrigerado::ContainerRefrigerado() {
}

ContainerRefrigerado::ContainerRefrigerado(const ContainerRefrigerado& orig) {
}

ContainerRefrigerado::~ContainerRefrigerado() {
}

ContainerRefrigerado::ContainerRefrigerado(string _origem, string _destino, double _peso, double _temperatura, string _alimentacao):Container(_origem,_destino,_peso), temperatura(_temperatura), alimentacao(_alimentacao){
    
}

string ContainerRefrigerado::GetAlimentacao() const {
    return alimentacao;
}

void ContainerRefrigerado::SetAlimentacao(string alimentacao) {
    this->alimentacao = alimentacao;
}

double ContainerRefrigerado::GetTemperatura() const {
    return temperatura;
}

void ContainerRefrigerado::SetTemperatura(double temperatura)  {
    this->temperatura = temperatura;
}
