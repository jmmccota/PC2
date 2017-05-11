/* 
 * File:   Pessoa.cpp
 * Author: cefetmg
 * 
 * Created on 27 de Fevereiro de 2013, 08:11
 */

#include "Pessoa.h"

Pessoa::Pessoa() {
}

Pessoa::Pessoa(const Pessoa& orig) {
}

Pessoa::~Pessoa() {
}

string Pessoa::GetCpf() const {
    return cpf;
}

void Pessoa::SetCpf(string cpf) {
    this->cpf = cpf;
}

int Pessoa::GetIdade() const {
    return idade;
}

void Pessoa::SetIdade(int idade) {
    this->idade = idade;
}

string Pessoa::GetNome() const {
    return nome;
}

void Pessoa::SetNome(string nome) {
    this->nome = nome;
}
