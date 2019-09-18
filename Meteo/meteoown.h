#ifndef METEOOWN_H
#define METEOOWN_H

#include "requeteown.h"
#include "SNClientHTTP.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


typedef struct {

    string nomVillePays;
    string description;
    float temperature;
    float temperatureMax;
    float temperatureMin;
    float temperatureRessentie;
    string directionVent;
    float vitesseVent;
    string urlIcone;


}ConditionsActuelles;

typedef struct {

    string nomVillePays;
    string description;
    float temperature;
    float temperatureMax;
    float temperatureMin;
    float temperatureRessentie;
    string directionVent;
    float vitesseVent;
    string urlIcone;

}ConditionsAVenir;


class meteoOWN
{
public:
    meteoOWN();
    void rechercher(string v, string p);
    string extraireContenuEntreBalises(string balise,string balise2, int positionDepart);
    ConditionsActuelles Actuellement();
    ConditionsAVenir Previsions(int indice);


private:
    int pos;
    RequeteOWN requete;
    SNClientHTTP clientOWN;
    string reponseXML;
    ofstream meteo;
    ConditionsActuelles actuellement;
    ConditionsAVenir previsions[4];
};



#endif // METEOOWN_H
