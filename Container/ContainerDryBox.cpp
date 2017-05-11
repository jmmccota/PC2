/* 
 * File:   ContainerDryBox.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 09:30
 */

#include "ContainerDryBox.h"

ContainerDryBox::ContainerDryBox() {
    
}

ContainerDryBox::ContainerDryBox(const ContainerDryBox& orig) {
}

ContainerDryBox::~ContainerDryBox() {
}

ContainerDryBox::ContainerDryBox(string _origem, string _destino, double _peso, bool _animal): Container(_destino,_destino,_peso), animal(_animal) {
}

bool ContainerDryBox::IsAnimal() const {
    return animal;
}

void ContainerDryBox::SetAnimal(bool animal) {
    this->animal = animal;
}

