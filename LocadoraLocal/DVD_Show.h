/* 
 * File:   DVD_Show.h
 * Author: aluno-cefet
 *
 * Created on 20 de Março de 2013, 08:42
 */

#ifndef DVD_SHOW_H
#define	DVD_SHOW_H
#include <string>
#include "Produto.h"
using namespace std;



class DVD_Show: public Produto {
public:
    DVD_Show();
    DVD_Show(const DVD_Show& orig);
    virtual ~DVD_Show();
    DVD_Show(string _nome, float _preco, float _quantidade, string _artista, int _numMusicas, int _ano);

    int GetAno() const;

    void SetAno(int ano);

    string GetArtista() const;

    void SetArtista(string artista);

    int GetNumMusicas() const;

    void SetNumMusicas(int numMusicas);
    
     virtual string GetTipo();

private:
    string artista;
    int numMusicas;
    int ano;
};

#endif	/* DVD_SHOW_H */

