#include "DVD_Software.h"

DVD_Software::DVD_Software() {
}

DVD_Software::DVD_Software(const DVD_Software& orig) {
}

DVD_Software::~DVD_Software() {
}

DVD_Software::DVD_Software(string _nome, float _preco, float _quantidade, string _versao, int _ano, string _requisitos): Produto(_nome, _preco, _quantidade) {
    this->versao = _versao;
    this->ano = _ano;
    this->requisitos = _requisitos;
}

int DVD_Software::GetAno() const {
    return ano;
}

void DVD_Software::SetAno(int ano) {
    this->ano = ano;
}

string DVD_Software::GetRequisitos() const {
    return requisitos;
}

void DVD_Software::SetRequisitos(string requisitos) {
    this->requisitos = requisitos;
}

string DVD_Software::GetVersao() const {
    return versao;
}

void DVD_Software::SetVersao(string versao) {
    this->versao = versao;
}

string DVD_Software::GetTipo() {
    return "Software";
}