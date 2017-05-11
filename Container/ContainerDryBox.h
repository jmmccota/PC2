/* 
 * File:   ContainerDryBox.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 09:30
 */

#ifndef CONTAINERDRYBOX_H
#define	CONTAINERDRYBOX_H

#include "Container.h"


class ContainerDryBox : public Container{
public:
    ContainerDryBox();
    ContainerDryBox(string _origem, string _destino, double _peso, bool _animal);
    ContainerDryBox(const ContainerDryBox& orig);
    virtual ~ContainerDryBox();

    bool IsAnimal() const;
    void SetAnimal(bool animal);

private:
    bool animal;
};

#endif	/* CONTAINERDRYBOX_H */