#include "NodoArbol.h"
NodoArbol::NodoArbol(Militar* Pmilitar){
    militar=Pmilitar;
}
NodoArbol::~NodoArbol(){
    for (int i = 0; i < NodoHijos.size(); i++)
    {
        delete NodoHijos[i];
    }
    NodoHijos.clear();
    delete militar;
}
void NodoArbol::agregarHijo(Militar* Pmilitar){
    NodoArbol* Pnodohijo=new NodoArbol(Pmilitar);
    NodoHijos.push_back(Pnodohijo);
}