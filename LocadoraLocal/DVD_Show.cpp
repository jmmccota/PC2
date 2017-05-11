/* 
 * File:   DVD_Show.cpp
 * Author: aluno-cefet
 * 
 * Created on 20 de Março de 2013, 08:42
 */

#include "DVD_Show.h"

DVD_Show::DVD_Show() {
}

DVD_Show::DVD_Show(const DVD_Show& orig) {
}

DVD_Show::~DVD_Show() {
}

DVD_Show::DVD_Show(string _nome, float _preco, float _quantidade, string _artista, int _numMusicas, int _ano): Produto(_nome, _preco, _quantidade){
    this->artista = _artista;
    this->numMusicas = _numMusicas;
    this->ano = _ano;
}

int DVD_Show::GetAno() const {
    return ano;
}

void DVD_Show::SetAno(int ano) {
    this->ano = ano;
}

string DVD_Show::GetArtista() const {
    return artista;
}

void DVD_Show::SetArtista(string artista) {
    this->artista = artista;
}

int DVD_Show::GetNumMusicas() const {
    return numMusicas;
}

void DVD_Show::SetNumMusicas(int numMusicas) {
    this->numMusicas = numMusicas;
}

string DVD_Show::GetTipo() {
    return "Show";
}
