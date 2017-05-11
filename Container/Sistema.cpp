/* 
 * File:   Sistema.cpp
 * Author: cefetmg
 * 
 * Created on 4 de Março de 2013, 14:15
 */

#include "Sistema.h"

Sistema::Sistema() {
    containers = new Container[60];
    for(int i = 0; i<60; i++){
        containers[i] = new Container();
    }
}

Sistema::Sistema(const Sistema& orig) {
}

Sistema::~Sistema() {
}

bool Sistema::addContainer(Container* c){

}

Container* Sistema::infoContainer(long id){

}

Container* Sistema::outContainer(){

}

int Sistema::qtdeDrybox(){

}


