#ifndef VAGA_H
#define	VAGA_H
#include "Veiculo.h"

using namespace std;

class Vaga {
public:
    Vaga();
    Vaga(int numero, int piso, int estado);
    void setNumero(int n);
    void setPiso(int p);
    void setEstado(bool e);
    bool setVeiculo(Veiculo *v);

    bool isOcupado() const;
    int getNumero() const;
    int getPiso() const;
    Veiculo* getVeiculo() const;

    virtual ~Vaga();
private:
    bool estado; // verdadeiro = ocupado
    int qEntrada;
    Veiculo *v;
    int numero, piso;
};
#endif	/* VAGA_H */

