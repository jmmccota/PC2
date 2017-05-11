/* 
 * File:   Venda.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 08:32
 */

#ifndef VENDA_H
#define	VENDA_H
#include "Carrinho.h"
#include "Usuario.h"
class Venda {
public:
    Venda();
    Venda(const Venda& orig);
    virtual ~Venda();
    Carrinho* GetCarrinho() const ;
    void SetCarrinho(Carrinho *carrinho) ;
    long GetCodigo() const ;
    time_t GetData() const ;
    void SetData(time_t data) ;
	void SetUsuario(Usuario *u);
	Usuario* GetUsuario() const;
	void setValorTotalCompra(float valor);
	void setValorFrete(float valor);
	void setCodigo(int c);
	float GetValorTotalCompra() const;
	float GetValorFrete() const;
    
private:
    static long cont;
    long codigo;
    time_t data;
    float valorTotalCompra, valorFrete;
    Carrinho *carrinho;
	Usuario *usuario;
};

#endif	/* VENDA_H */

