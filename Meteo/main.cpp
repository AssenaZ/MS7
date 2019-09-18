#include <QCoreApplication>
#include "requeteown.h"
#include "meteoown.h"
#include "SNClientHTTP.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

string v;
string p;


    cout<< "Ville ?"<<endl;
    cin>> v;

    cout<< "Pays ?"<<endl;
    cin>> p;

    meteoOWN meteo;
    meteo.rechercher(v,p);

    ConditionsActuelles Affiche = meteo.Actuellement();
    cout << "La temperature actuelle est de : " << Affiche.temperature << " degres celsius " << endl;
    cout<< "La temperature max est de : "  <<  Affiche.temperatureMax << " degres celsius " << endl;
    cout << "La temperature min est de : " << Affiche.temperatureMin << " degres celsius " << endl;
    cout<<endl;
    //cout<< "La vitesse du vent est : " << Affiche.vitesseVent << endl;


    for(int indice=0;indice<4;indice++)
    {

    ConditionsAVenir Prevision = meteo.Previsions(indice);
    cout << "La temperature a l'avenir va etre de : " << Prevision.temperature << " degres celsius " << endl;
    cout<< "La temperature max a l'avenir va etre de : "  <<  Prevision.temperatureMax << " degres celsius " << endl;
    cout << "La temperature min a l'avenir va etre de : " << Prevision.temperatureMin << " degres celsius " << endl;
    cout<<endl;


    }
    return a.exec();
}

