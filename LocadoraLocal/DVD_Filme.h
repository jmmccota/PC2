/* 
 * File:   DVD_Filme.h
 * Author: aluno-cefet
 *
 * Created on 13 de Março de 2013, 09:09
 */

#ifndef DVD_FILME_H
#define	DVD_FILME_H
#include <string>
#include "Produto.h"
using namespace std;

class DVD_Filme: public Produto {
public:
    DVD_Filme();
    DVD_Filme(string _nome, float _preco, float _quantidade, string _diretor, long _ano);
    DVD_Filme(const DVD_Filme& orig);
    virtual ~DVD_Filme();
    long GetAno() const;
    void SetAno(long ano);
    string GetDiretor() const ;
    void SetDiretor(string diretor) ;
    virtual string GetTipo();
private:
    string diretor;
    long ano;    

};

#endif	/* DVD_FILME_H */

