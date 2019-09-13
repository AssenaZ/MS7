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
    //meteo.extraireContenuEntreBalises("temperature",0);


    return a.exec();
}

