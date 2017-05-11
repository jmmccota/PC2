/* 
 * File:   Produto.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 08:20
 */

#ifndef PRODUTO_H
#define	PRODUTO_H
#include <string>
using namespace std;

class Produto {
public:
    Produto();
    Produto(const Produto& orig);
    virtual ~Produto();
    Produto(string _nome, float _preco, float _quantidade);
    int GetCodigo() const;    
    void SetCodigo(int codigo) ;
    float GetPreco() const ;
    void SetPreco(float preco) ;
    float GetQuantNoEstoque() const ;
    void SetQuantNoEstoque(float quantNoEstoque) ;
    string GetNome() const;
    void SetNome(string nome);
    virtual string GetTipo() = 0;
private:
    static int cont;
    int codigo;
    float preco, quantNoEstoque;
    string nome;
};

#endif	/* PRODUTO_H */

