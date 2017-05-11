/* 
 * File:   Empregado.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 08:36
 */

#ifndef EMPREGADO_H
#define	EMPREGADO_H

#include "Pessoa.h"


class Empregado: public Pessoa{
public:
    Empregado();
    Empregado(const Empregado& orig);
    virtual ~Empregado();

    double GetIR() const;

    void SetIR(double IR);

    int GetNumeroSecao() const;

    void SetNumeroSecao(int numeroSecao) ;

    double GetSalarioBase() const ;

    void SetSalarioBase(double salarioBase) ;

    virtual double calculaSalario();    

private:
    int numeroSecao;
    double salarioBase, IR;

};

#endif	/* EMPREGADO_H */

