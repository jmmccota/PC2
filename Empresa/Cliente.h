/* 
 * File:   Cliente.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 08:42
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include "Pessoa.h"


class Cliente: public Pessoa {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    double getCreditoMax() const ;

    void setCreditoMax(double creditoMax) ;

    double getValorDevido() const ;

    void setValorDevido(double valorDevido) ;
    
    double obterSaldo();
private:
    double creditoMax, valorDevido;

};

#endif	/* CLIENTE_H */

