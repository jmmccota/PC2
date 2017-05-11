/* 
 * File:   DVD_Filme.cpp
 * Author: aluno-cefet
 * 
 * Created on 13 de Março de 2013, 09:09
 */

#include "DVD_Filme.h"

DVD_Filme::DVD_Filme() {
}

DVD_Filme::DVD_Filme(string _nome, float _preco, float _quantidade, string _diretor, long _ano): Produto( _nome, _preco, _quantidade){
    diretor = _diretor;
    ano = _ano;
}

DVD_Filme::DVD_Filme(const DVD_Filme& orig) {
}

DVD_Filme::~DVD_Filme() {
}

long DVD_Filme::GetAno() const {
    return ano;
}

void DVD_Filme::SetAno(long ano) {
    this->ano = ano;
}

string DVD_Filme::GetDiretor() const {
    return diretor;
}

void DVD_Filme::SetDiretor(string diretor) {
    this->diretor = diretor;
}

string DVD_Filme::GetTipo(){
    return "Filme";
}

