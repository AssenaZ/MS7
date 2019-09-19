#include "meteoown.h"

#include <sstream>

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

    string req;
    req = requete.previsionsRequeteOWN();
    cout<<req;

    SNClientHTTP clientOWN;


    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();
    reponseXML = clientOWN.CorpsReponse();
   // cout<<reponseXML;

    ofstream MeteoCourante;
    MeteoCourante.open("PrevisionMeteo.xml");
    MeteoCourante<< reponseXML;
    MeteoCourante.close();


    // saisi des balises souhaitées
    /*string balise;
    cout<<"First balise: "<<endl;
    cin>>balise;
    string balise2;
    cout<<"Second parameter : "<<endl;
    cin>>balise2;*/

    /*string reponse = extraireContenuEntreBalises("temperature", "value",0);
    string reponse2 = extraireContenuEntreBalises("speed", "value",0);
    cout<<reponse<<endl;
    cout<<reponse2<<endl;*/


    actuellement.DateA = extraireContenuEntreBalises("time","to",0);


    actuellement.DateF = extraireContenuEntreBalises("time","from",0);
  istringstream(extraireContenuEntreBalises("temperature","value",0)) >>  actuellement.temperature;
  istringstream(extraireContenuEntreBalises("temperature","max",0)) >>  actuellement.temperatureMax;
  istringstream(extraireContenuEntreBalises("temperature","min",0)) >>  actuellement.temperatureMin;

 // istringstream(extraireContenuEntreBalises("windSpeed","mps",0)) >>  actuellement.vitesseVent;




  //-----------------------------------previsions---------------------------------------


   /* if (clientOWN.LongueurCorpsReponse() > 0)
    { cout << "OK" << endl;
    reponseXML = clientOWN.CorpsReponse();
    }
    else {"error";}
*/
   int pos = reponseXML.find("from");

  for(int i=0; i<4; i++)
  {

//      cout<<pos<<endl;
      pos = reponseXML.find("from",pos+1);

      previsions[i].DateA = extraireContenuEntreBalises("time","to",pos);
      previsions[i].DateF = extraireContenuEntreBalises("time","from",pos);
     // previsions[i].date = extraireContenuEntreBalises("","2019-09-19",pos);
      istringstream(extraireContenuEntreBalises("temperature","value",pos)) >>  previsions[i].temperature;
      istringstream(extraireContenuEntreBalises("temperature","max",pos)) >>  previsions[i].temperatureMax;
      istringstream(extraireContenuEntreBalises("temperature","min",pos)) >>  previsions[i].temperatureMin;
      // istringstream(extraireContenuEntreBalises("windSpeed","mps",0)) >>  actuellement.vitesseVent;
  }


//  string time = "2019-09-19T15:00:00";
//  istringstream iss("2019-09-19");

//  size_t t = time.find("2019-09-19");
//  cout<<t;

}

string meteoOWN::extraireContenuEntreBalises(string balise,string balise2 ,int positionDepart)
{

    int positionDepartBalise = reponseXML.find(balise,positionDepart);
    int positionFinaleBalise = reponseXML.find("</"+balise+">",positionDepartBalise);
    string chaineFinale = reponseXML.substr(positionDepartBalise+balise.length(),positionFinaleBalise-positionDepartBalise-balise.length()-1);

   int positionDepartBalise2 = reponseXML.find(balise2,positionDepartBalise);
   int positionFinaleBalise2 = reponseXML.find("\"",positionDepartBalise2+balise2.length()+1+1);
   string chaineFinale2 = reponseXML.substr(positionDepartBalise2+balise2.length()+1+1,positionFinaleBalise2-positionDepartBalise2-balise2.length()-1-1);
   return chaineFinale2;

}

ConditionsActuelles meteoOWN::Actuellement()
{
    return actuellement;
}

ConditionsAVenir meteoOWN::Previsions(int indice)
{
   return previsions[indice];
   }

















