/* 
 * File:   DVD_Software.h
 * Author: aluno-cefet
 *
 * Created on 20 de Março de 2013, 08:46
 */

#ifndef DVD_SOFTWARE_H
#define	DVD_SOFTWARE_H
#include <string>
#include "Produto.h"
using namespace std;

class DVD_Software: public Produto{
public:
    DVD_Software();
    DVD_Software(const DVD_Software& orig);
    DVD_Software(string _nome, float _preco, float _quantidade, string _versao, int _ano, string _requisitos);
    virtual ~DVD_Software();
    
    int GetAno() const;
    void SetAno(int ano);
    string GetRequisitos() const;
    void SetRequisitos(string requisitos);
    string GetVersao() const;
    void SetVersao(string versao);
    string GetTipo();

private:
    int ano;
    string requisitos,versao;
};

#endif	/* DVD_SOFTWARE_H */

