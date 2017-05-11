#include "Estacionamento.h"
#include "Vaga.h"
#include "Veiculo.h"
#include "Calendar.h"
#include <string>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

Estacionamento::Estacionamento(){
    posicao = 0;
    tipos = 0;
   // qVeiculos = 0;
	vposicao = 0;
    qVeiculosEstacionados = 0;
}
Estacionamento::Estacionamento(int q){
    //Estacionamento();
    posicao = 0;
    tipos = 0;
	vposicao = 0;
    qVeiculosEstacionados = 0;
    qVeiculos = 1;
    qVagas = q;
    v = new Vaga*[q];
    veiculos = new Veiculo*[1];

    for(int i = 0; i<1; i++){
        veiculos[i] = new Veiculo();
    }
    for(int i = 0; i<q; i++){
        v[i] = new Vaga();
    }
}

Estacionamento::~Estacionamento() {
    delete v;
    v = NULL;
    delete veiculos;
    veiculos = NULL;
}
/*
void Estacionamento::setQVagas(int q) { //vetor dinamico para vagas
    qVagas = q;
    v = new Vaga*[q];
}
*/
void Estacionamento::addVaga(Vaga *v) {
    this->v[posicao] = v;

    //veiculos[vposicao] = v->getVeiculo();

    /**cout<<"\n End. vaga:"<<v;
    cout<<"\n End veic:"<<v->getVeiculo();
    cout<<"\n End veic. posi:"<<veiculos[vposicao];
**/
    /**cout<<"\n P2:"<<veiculos[vposicao]->getMarca();
    cout<<"\n Posicao:"<<vposicao;
    cout<<"\n Vetor Posi:"<<v->getVeiculo();
**/
    qVeiculosEstacionados++;
    posicao++;
    //vposicao++;

    }


void Estacionamento::setVagas(Vaga **v, int tam){
    qVagas = tam;
	this->v = v;
}

void Estacionamento::setTarifas(float *tax, string *tipos, int tam){
	valores = tax;
	this->tipos = tam;
	tValores = tipos;
}

int Estacionamento::getQTipos() const{
        return tipos;
}

/**void Estacionamento::estaciona(Veiculo *v){  //Provavelmente deve estar funcionando esse vetor dinamico que inventei!
	veiculos[vposicao]=v;
	vposicao++;
}**/

void Estacionamento::estaciona(Veiculo *v){  //Provavelmente deve estar funcionando esse vetor dinamico que inventei!
	veiculos[vposicao]=v;
	vposicao++;
	Veiculo** aux= new Veiculo*[vposicao];
	cout<<"\n Posições"<<vposicao;

	for(int i=0; i<vposicao;i++){
        aux[i]=veiculos[i];
	}
	veiculos=aux;
	qVeiculos++;
}/**
void Estacionamento::estaciona2(Veiculo *v){  //Provavelmente deve estar funcionando esse vetor dinamico que inventei!
	//sizeof(veiculos)/sizeof(Veiculo *)
	if(vposicao <= qVeiculos){
		veiculos[vposicao] = v;
		vposicao++;
	} else {
		aumentaVetor();
		veiculos[vposicao] = v;
		vposicao++;
	}
	//Vetor dinamico
    //http://www.uems.br/docentes/rmmuller/arquivos.pdf
    //http://www.dimap.ufrn.br/~adilson/DIm327/arquivos.pdf
}


void Estacionamento::aumentaVetor() {

	Veiculo **aux = new Veiculo*[qVeiculos+1];

    for (int i=0; i<qVeiculos+1; i++){
		aux[i] = veiculos[i];
    }
    veiculos=aux;
    //aux = v;
/*
    delete veiculos;
    qVeiculos++;
    veiculos = new Veiculo*[qVeiculos];
    for (int i=0; i<qVeiculos; i++){
       veiculos[i] = aux[i];
    }

    cout<<"\n Qtd Veiculos:"<<qVeiculos;
}*/
int Estacionamento::getQVagas() const {
    return qVagas;
}
int Estacionamento::getQVeiculos() const {
    return qVeiculos;
}

Veiculo** Estacionamento::getVeiculos() const {
    //cout<<"\nEsta pegando veiculos\n";
    //cout<<"\n Entrei Veiculo";
    return veiculos;
}

Vaga** Estacionamento::getVagas() {
        //cout<<"\n Aki";
        return v;
}

Vaga* Estacionamento::getVaga(int posicao) const{
    return v[posicao];
}

int Estacionamento::getPosicao() const {
    return posicao;

}

int Estacionamento::getQVeiculosEstacionados() const{
    return qVeiculosEstacionados;
}
float* Estacionamento::getValores() const{
	return valores;
}
string* Estacionamento::getTValores() const{
    return tValores;
}

Veiculo* Estacionamento::getVeiculo(string placa) const{
	for(int i = 0; i<vposicao; i++){
		if(veiculos[i]->getPlaca().compare(placa) == 0){
			return veiculos[i];
		}
	}
	//cout<<"\nEntrou aqui!\n";
	return NULL;
}

/**Veiculo* Estacionamento::getVeiculoDia(int dia){

    for(int i = 0; i<(sizeof(veiculos)/sizeof(int)); i++){
        int auxDia;

		time_t auxTempo= veiculos[i]->getEntrada();

        auxDia=c.pegaDia(auxTempo);
        if( dia == auxDia){
            return veiculos[i];
        }
	}
}**/
