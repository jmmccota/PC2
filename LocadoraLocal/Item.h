/* 
 * File:   Item.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 08:24
 */

#ifndef ITEM_H
#define	ITEM_H

#include "Produto.h"


class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();

    float GetPreco() const ;
    void SetPreco(float preco);
    Produto* GetProduto() const;
    void SetProduto(Produto* produto) ;
    float GetQuantidade() const ;
    void SetQuantidade(float quantidade) ;
	void confirmaCompra();
private:
    Produto *produto;
    float preco, quantidade;

};

#endif	/* ITEM_H */

