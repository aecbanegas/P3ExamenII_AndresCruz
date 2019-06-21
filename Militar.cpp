#include "Militar.h"
Militar::Militar(string nom,string cod, string ed, string ran){
    nombre=nom;
    codigo=cod;
    edad=ed;
    rango=ran;
}
string Militar::getRango(){
    return rango;
}
string Militar::toString(){
    
    if(rango=="General")
        return nombre+" - "+rango;
    if(rango=="Coronel")
        return "    "+nombre+" - "+rango;
    if(rango=="Mayor")
        return "        "+nombre+" - "+rango;
    if(rango=="Capitan")
        return "            "+nombre+" - "+rango;
    if(rango=="Teniente")
        return "                "+nombre+" - "+rango;
    if(rango=="Sargento")
        return "                    "+nombre+" - "+rango;
    if(rango=="Cabo")
        return "                        "+nombre+" - "+rango;
    if(rango=="Soldado")
        return "                            "+nombre+" - "+rango;
    return "Error";
}
string Militar::getNombre(){
    return nombre;
}