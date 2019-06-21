#pragma once
#include <string>
using namespace std;
class Militar{
    private:
        string nombre;
        string codigo;
        string edad;
        string rango;
    public:
        Militar(string,string,string,string);
        string toString();
        string getRango();
};