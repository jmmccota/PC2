/* 
 * File:   Container.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 09:23
 */

#include "Container.h"
#include <string>
using namespace std;

static long Container::cont = 0;

Container::Container() {
    identificador = cont;
    cont++;
}
Container::Container(string _origem, string _destino, double _peso): origem(_origem), destino(_destino), peso(_peso){
    identificador = cont;
    cont++;
}

Container::Container(const Container& orig) {
}

Container::~Container() {
}

string Container::GetDestino() const {
    return destino;
}

void Container::SetDestino(string destino) {
    this->destino = destino;
}

long Container::GetIdentificador() const {
    return identificador;
}

string Container::GetOrigem() const {
    return origem;
}

void Container::SetOrigem(string origem) {
    this->origem = origem;
}

double Container::GetPeso() const {
    return peso;
}

void Container::SetPeso(double peso) {
    this->peso = peso;
}
