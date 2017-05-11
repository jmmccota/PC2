#include "Veiculo.h"
#include "Calendar.h"
#include <ctime>

Veiculo::Veiculo() {
    qEstacionado=0;
}

Veiculo::Veiculo(string marca, string modelo, string cor, string placa, int tipo){
    Veiculo();
    this->marca = marca;
    this->modelo = modelo;
    this->cor = cor;
    this->placa = placa;
    this->tipo = tipo;
}
Veiculo::~Veiculo() {}

void Veiculo::setCor(string c) {
    cor = c;
}

void Veiculo::setMarca(string m) {
    marca = m;
}

void Veiculo::setModelo(string m) {
    modelo = m;
}

void Veiculo::setPlaca(string p) {
    placa = p;
}

void Veiculo::setTipo(int t){
    tipo = t;
}

void Veiculo::estaciona(){
	estacionado = true;
    qEstacionado++;
}

string Veiculo::getCor() const {
    return cor;
}

string Veiculo::getMarca() const {
   return marca;
}

string Veiculo::getModelo() const {
    return modelo;
}

string Veiculo::getPlaca() const {
    return placa;
}

int Veiculo::getTipo() const {
    return tipo;
}

int Veiculo::getQEstacionado() const {
    return qEstacionado;
}

bool Veiculo::isEstacionado() const {
	return estacionado;
}

void Veiculo::setEntrada(time_t entrada){
    Calendar c;
    int dia;
    this->entrada=entrada;
    dia=c.pegaDia(entrada);
    setDiaEntrada(dia);
}
int Veiculo::getDiaEntrada()const{
    return diaEntrada;
}

void Veiculo::setDiaEntrada(int diaEntrada){
    this->diaEntrada=diaEntrada;
}

void Veiculo::setSaida(time_t saida){
    this->saida=saida;
    estacionado=false;
}
time_t Veiculo::getEntrada() const{
    return entrada;
}
time_t Veiculo::getSaida() const{
    return saida;
}

void Veiculo::setEstaciona(bool estacionado){

    this->estacionado=estacionado;
}
