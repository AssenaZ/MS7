#include "requeteown.h"
#include <iostream>
#include <string>

using namespace std;


RequeteOWN::RequeteOWN()
{
    ville = "Paris";
    pays = "France";
    cle = "634e643c9e696188015e7f1dbe11a909";
}

RequeteOWN::~RequeteOWN()
{

}

string RequeteOWN::creerRequeteOWN()
{
    string http = "GET /data/2.5/weather?q="+ville+","+pays+"&units=metric&appid="+cle+"&mode=xml HTTP/1.1\r\n";
        http += "host: api.openweathermap.org\r\n";
        http += "Connection: keep-alive\r\n";
        http += "\r\n";
       return http;
}
