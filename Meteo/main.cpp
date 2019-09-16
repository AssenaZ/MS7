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
    cout <<  Affiche.temperatureMax << endl;
    cout << Affiche.temperatureMin << endl;



    return a.exec();
}

