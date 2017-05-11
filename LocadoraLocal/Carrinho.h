/* 
 * File:   Carrinho.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 08:31
 */

#ifndef CARRINHO_H
#define	CARRINHO_H

#include "Item.h"
#include <vector>


class Carrinho {
public:
    Carrinho();
    Carrinho(const Carrinho& orig);
    virtual ~Carrinho();
    bool addItem(Item *item);
	vector<Item*> *getItem();
private:
	vector<Item *> itens;
    
};

#endif	/* CARRINHO_H */

