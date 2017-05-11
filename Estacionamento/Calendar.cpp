
/*
 * File:   Ex14.cpp
 * Author: cefetmg
 *
 * Created on 17 de Dezembro de 2012, 13:45
 */

#include <ctime>
#include "Calendar.h"
#include <iostream>
using namespace std;

/**Calendar::Calendar() {
        time_t currentTime;
        // get and print the current time
        time(&currentTime);
        //cout << "It is now " << ctime(&currentTime) << endl;
        struct tm * ptm = localtime(&currentTime);
        //cout<<currentTime;
        this->dia = ptm->tm_mday;
        this->mes = ((ptm->tm_mon) + 1);
        this->ano = (ptm->tm_year + 1900);
        this->hora=ptm->tm_hour;
        this->minuto=ptm->tm_min;
        this->segundo=ptm->tm_sec;
}**/
Calendar::Calendar(){

}
void Calendar::toString() {
        cout <<"\n"<< dia << "/" << mes << "/"<<ano;
        cout<<hora<<":"<<minuto<<":"<<segundo;
    }
int Calendar::pegaDia(time_t data){
    int diaA;
    time(&data);
    struct tm * ptm = localtime(&data);
    diaA = ptm->tm_mday;

   return diaA;
}
/**int Calendar::pegaHora(time_t hora){
    int horaA;
    time(&hora);
    struct tm * ptm = localtime(&hora);
    horaA = ptm->tm_hour;
   return horaA;
}
int Calendar::pegaMinuto(time_t minuto){
    int minA;
    time(&minuto);
    struct tm * ptm = localtime(&minuto);
    minA =ptm->tm_min;
   return minA;
}
int Calendar::pegaMes(time_t mes){
    int mesA;
    time(&mes);
    struct tm * ptm = localtime(&mes);
    mesA =((ptm->tm_mon) + 1);
   return mesA;

}
int Calendar::pegaAno(time_t ano){
    int anoA;
    time(&ano);
    struct tm * ptm = localtime(&ano);
    anoA =(ptm->tm_year + 1900);

   return anoA;
}**/
