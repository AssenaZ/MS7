#ifndef METEOOWN_H
#define METEOOWN_H

#include "requeteown.h"
#include "SNClientHTTP.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


struct ConditionsActuelles{

    string nomVillePays;
    string description;
    int temperature;
    int temperatureRessentie;
    string directionVent;
    int vitesseVent;
    string urlIcone;


};


class meteoOWN
{
public:
    meteoOWN();
    void rechercher(string v, string p);
    string extraireContenuEntreBalises(string balise,string balise2, int positionDepart);



private:
    RequeteOWN requete;
    SNClientHTTP clientOWN;
    string reponseXML;
    ofstream meteo;
    ConditionsActuelles actuellement;
};



#endif // METEOOWN_H
