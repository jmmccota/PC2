#include "Vaga.h"
#include <string>

Vaga::Vaga(int numero, int piso, int estado){
    this->numero = numero;
    this->piso = piso;
    this->estado = estado;
}

Vaga::Vaga(){}

Vaga::~Vaga() {}

void Vaga::setNumero(int n) {
    numero = n;
}

void Vaga::setPiso(int p) {
    piso = p;
}

void Vaga::setEstado(bool e) {
    estado = e;
}

bool Vaga::setVeiculo(Veiculo* v){
	if( qEntrada==0){
        estado=false;
	}
	qEntrada++;
	if(!estado){
		this->v = v;
		estado = true;
		return true;
	}
    return false;
}

bool Vaga::isOcupado() const {
    return estado;
}

int Vaga::getPiso() const {
    return piso;
}

int Vaga::getNumero() const {
    return numero;
}

Veiculo* Vaga::getVeiculo() const{
    return v;
}

