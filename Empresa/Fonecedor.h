/* 
 * File:   Fonecedor.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 08:24
 */

#ifndef FONECEDOR_H
#define	FONECEDOR_H

#include "Pessoa.h"


class Fonecedor : public Pessoa{
public:
    Fonecedor();
    Fonecedor(const Fonecedor& orig);
    virtual ~Fonecedor();

    double GetCreditoMax() const ;

    void SetCreditoMax(double creditoMax) ;

    double GetValorDevido() const ;

    void SetValorDevido(double valorDevido) ;
    double obterSaldo();
private:
    double creditoMax, valorDevido;

};

#endif	/* FONECEDOR_H */

