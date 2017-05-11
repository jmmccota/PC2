/* 
 * File:   ContainerRefrigerado.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 09:30
 */

#ifndef CONTAINERREFRIGERADO_H
#define	CONTAINERREFRIGERADO_H

#include "Container.h"

class ContainerRefrigerado : public Container {
public:
    ContainerRefrigerado();
    ContainerRefrigerado(string _origem, string _destino, double _peso, double _temperatura, string _alimentacao);
    ContainerRefrigerado(const ContainerRefrigerado& orig);
    virtual ~ContainerRefrigerado();

    string GetAlimentacao() const;
    void SetAlimentacao(string alimentacao);
    double GetTemperatura() const;
    void SetTemperatura(double temperatura);

private:
    double temperatura;
    string alimentacao;
};

#endif	/* CONTAINERREFRIGERADO_H */

