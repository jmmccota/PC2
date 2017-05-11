/* 
 * File:   Usuario.cpp
 * Author: aluno-cefet
 * 
 * Created on 20 de Março de 2013, 08:56
 */

#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::Usuario(const Usuario& orig) {
}
Usuario::Usuario(string nome, string cpf, string nasc, string tel, string end){
	this->nome = nome;
	this->cpf = cpf;
	this->nasc = nasc;
	this->telefone = tel;

	this->endereco = end;

}
Usuario::~Usuario() {
}

string Usuario::GetCpf() const {
    return cpf;
}

void Usuario::SetCpf(string cpf) {
    this->cpf = cpf;
}

string Usuario::GetNasc() const {
    return nasc;
}

void Usuario::SetNasc(string nasc) {
    this->nasc = nasc;
}

string Usuario::GetNome() const {
    return nome;
}

void Usuario::SetNome(string nome) {
    this->nome = nome;
}

string Usuario::GetEndereco() const {
    return endereco;
}

void Usuario::SetEndereco(string endereco) {
    this->endereco = endereco;
}

string Usuario::GetTelefone() const {
    return telefone;
}

void Usuario::SetTelefone(string telefone) {
    this->telefone = telefone;
}
