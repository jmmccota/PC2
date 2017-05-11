/* 
 * File:   Operario.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 09:01
 */

#ifndef OPERARIO_H
#define	OPERARIO_H

class Operario {
public:
    Operario();
    Operario(const Operario& orig);
    virtual ~Operario();

    double GetComissao() const ;

    void SetComissao(double comissao) ;

    double GetValorProducao() const ;

    void SetValorProducao(double valorProducao) ;

    double calculaSalario();

private:
    double valorProducao, comissao;

};

#endif	/* OPERARIO_H */

