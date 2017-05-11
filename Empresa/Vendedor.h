/* 
 * File:   Vendedor.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 09:08
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include "Empregado.h"


class Vendedor : public Empregado{
public:
    Vendedor();
    Vendedor(const Vendedor& orig);
    virtual ~Vendedor();
   
    double getComissao() const;

    void setComissao(double comissao) ;

    double getValorVendido() const ;

    void setValorVendido(double valorVendido) ;

    double calculaSalario();
private:
    double comissao, valorVendido;
};

#endif	/* VENDEDOR_H */

