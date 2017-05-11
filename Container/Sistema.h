/* 
 * File:   Sistema.h
 * Author: cefetmg
 *
 * Created on 4 de Março de 2013, 14:15
 */

#ifndef SISTEMA_H
#define	SISTEMA_H

#include "Container.h"


class Sistema {
public:
    Sistema();
    Sistema(const Sistema& orig);
    virtual ~Sistema();
    void addContainer(Container *c);
    Container* outContainer();
    Container* infoContainer(long id);
    int qtdeDrybox();
private:
    Container **containers;
};

#endif	/* SISTEMA_H */

