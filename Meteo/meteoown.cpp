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
    //cout<<reponseXML;

    ofstream MeteoCourante;
    MeteoCourante.open("Meteo.xml");
    MeteoCourante<< reponseXML;
    MeteoCourante.close();

    //extraireContenuEntreBalises("temperature""speed",0);

}

string meteoOWN::extraireContenuEntreBalises(string balise, int positionDepart)
{

    int positionDepartBalise = reponseXML.find(balise,positionDepart);
    int positionFinaleBalise = reponseXML.find("</"+balise+">",positionDepartBalise);
    string chaineFinale = reponseXML.substr(positionDepartBalise+balise.length(),positionFinaleBalise-positionDepartBalise-balise.length()-1);

    cout<<chaineFinale;
    //cout<<positionFinaleBalise<<endl;
    //cout<<positionDepartBalise;

}

