/* 
 * File:   Administrador.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 08:46
 */

#ifndef ADMINISTRADOR_H
#define	ADMINISTRADOR_H

#include "Empregado.h"


class Administrador: public Empregado {
public:
    Administrador();
    Administrador(const Administrador& orig);
    virtual ~Administrador();

    double calculaSalario();
    double getAjudasDeCusto() const;
    void setAjudasDeCusto(double ajudasDeCusto) ;

private:
    double ajudasDeCusto;
};

#endif	/* ADMINISTRADOR_H */

