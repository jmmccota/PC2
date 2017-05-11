/*
 * File:   Veiculo.h
 * Author: cefetmg
 *
 * Created on 14 de Janeiro de 2013, 13:46
 */

#ifndef VEICULO_H
#define	VEICULO_H
#include <string>

using namespace std;

class Veiculo {
public:
    Veiculo();
    Veiculo(string marca, string modelo, string cor, string placa, int tipo);
    void setMarca(string m);
    void setModelo(string m);
    void setCor(string c);
    void setPlaca(string p);
    void setTipo(int t);
    void estaciona();
    void setEstaciona(bool estacionado);

    string getMarca() const;
    string getModelo() const;
    string getCor() const;
    string getPlaca() const;
    int getTipo() const;
    int getQEstacionado() const;
	bool isEstacionado() const;
	void setEntrada(time_t entrada);
    void setSaida(time_t saida);
    time_t getEntrada() const;
    time_t getSaida() const;
    int getDiaEntrada()const;
    void setDiaEntrada(int diaEntrada);


    virtual ~Veiculo();
private:
    string marca, modelo, cor, placa;
	bool estacionado;
	time_t entrada;
	int diaEntrada;
	time_t saida;
    int tipo,qEstacionado; //tipo 1 = carro ,  2 = moto
};

#endif	/* VEICULO_H */
