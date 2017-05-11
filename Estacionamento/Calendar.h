#ifndef CALENDAR_H
#define	CALENDAR_H

#include<ctime>


class Calendar{
private:
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;

public:
    void toString();
    Calendar();
    int pegaDia(time_t data);
    /**int pegaHora(time_t hora);
    int pegaMinuto(time_t minuto);
    int pegaMes(time_t mes);
    int pegaAno(time_t ano);**/
};






#endif // CALENDAR_H

