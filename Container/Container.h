/* 
 * File:   Container.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 09:23
 */

#ifndef CONTAINER_H
#define	CONTAINER_H
#include <string>
using namespace std;
class Container {
public:
    Container(string _origem, string _destino, double _peso);
    Container();
    Container(const Container& orig);
    virtual ~Container();

    string GetDestino() const ;

    void SetDestino(string destino) ;

    long GetIdentificador() const;

    string GetOrigem() const;

    void SetOrigem(string origem) ;

    double GetPeso() const ;

    void SetPeso(double peso) ;
private:
    long identificador;
    string destino, origem;
    double peso;
    static long cont;
};

#endif	/* CONTAINER_H */

