#ifndef METEOOWN_H
#define METEOOWN_H

#include "requeteown.h"
#include "SNClientHTTP.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class meteoOWN
{
public:
    meteoOWN();
    void rechercher(string v, string p);
    string extraireContenuEntreBalises(string balise, int positionDepart);


private:
    RequeteOWN requete;
    SNClientHTTP clientOWN;
    string reponseXML;
    ofstream meteo;



};

#endif // METEOOWN_H
