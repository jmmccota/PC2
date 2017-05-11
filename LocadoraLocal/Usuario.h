/* 
 * File:   Usuario.h
 * Author: aluno-cefet
 *
 * Created on 20 de Março de 2013, 08:56
 */

#ifndef USUARIO_H
#define	USUARIO_H
#include <string>
using namespace std;

class Usuario {
public:
    Usuario();
	Usuario(string nome, string cpf, string nasc, string tel, string end);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    string GetCpf() const;
    void SetCpf(string cpf);

    string GetNasc() const;

    void SetNasc(string nasc);

    string GetNome() const;

    void SetNome(string nome);

    string GetEndereco() const;

    void SetEndereco(string endereco);
	string GetTelefone() const;

    void SetTelefone(string telefone);

private:
    string nome, cpf, endereco,telefone, nasc;
};

#endif	/* USUARIO_H */

