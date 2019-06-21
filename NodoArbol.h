#pragma once
#include "Militar.h"
#include <vector>
using namespace std;
class NodoArbol{
    private:
        Militar* militar;
        vector<NodoArbol*> NodoHijos;
    public:
        ~NodoArbol();
        NodoArbol(Militar*);
        void agregarHijo(Militar*);
        vector<NodoArbol*> getHijos();
        Militar* getMilitar();
};