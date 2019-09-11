#include "meteoown.h"



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

meteoOWN::meteoOWN()
{

}

void meteoOWN::rechercher(string v, string p)
{
    RequeteOWN requete;

    requete.ModifierPays(p);
    requete.ModifierVille(v);

    string req = requete.creerRequeteOWN();
    cout<<req;

    SNClientHTTP clientOWN;

    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();
    reponseXML = clientOWN.CorpsReponse();
    cout<<reponseXML;

    ofstream MeteoCourante;
    MeteoCourante.open("Meteo.xml");
    MeteoCourante<< reponseXML;
    MeteoCourante.close();

    reponseXML.find("current");
}

/*string extraireContenuEntreBalises(string balise, int positionDepart);
{
}*/
