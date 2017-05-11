#ifndef ESTACIONAMENTO_H
#define	ESTACIONAMENTO_H
#include "Vaga.h"
#include "Veiculo.h"
#include "Calendar.h"
#include <string>
using namespace std;
class Estacionamento {
public:
    Estacionamento();
	Estacionamento(int q);
    void addVaga(Vaga *v);
	void setVagas(Vaga **v, int tam);
	void setTarifas(float *tax, string *tipos, int tam);
    //void setQVagas(int p);
    void estaciona(Veiculo *ve);

    Vaga** getVagas();
    Veiculo** getVeiculos() const;
	Veiculo* getVeiculo(string placa) const;
    int getQVagas() const;
    int getPosicao() const;
    Vaga* getVaga(int posicao) const;
    int getQVeiculosEstacionados() const;
	float* getValores() const;
	string* getTValores() const;
	int getQVeiculos() const;
	int getQTipos() const;
	//Veiculo* getVeiculoDia(int dia);
    virtual ~Estacionamento();
private:
    Vaga **v;
    //Calendar c;
    int qVagas, qVeiculos,tipos;
    int posicao, vposicao;
    int qVeiculosEstacionados;
	float *valores;
	string *tValores;
    Veiculo **veiculos;

	void aumentaVetor();
};
#endif	/* ESTACIONAMENTO_H */

