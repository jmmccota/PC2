/* 
 * File:   Pessoa.h
 * Author: cefetmg
 *
 * Created on 27 de Fevereiro de 2013, 08:11
 */

#ifndef PESSOA_H
#define	PESSOA_H
#include <string>
using namespace std;
class Pessoa {
public:
    Pessoa();
    Pessoa(const Pessoa& orig);
    virtual ~Pessoa();

    string GetCpf() const ;
    void SetCpf(string cpf);

    int GetIdade() const ;
    void SetIdade(int idade);
    
    string GetNome() const ;
    void SetNome(string nome);
protected:
    string nome,cpf;
    int idade;
private:

};

#endif	/* PESSOA_H */

