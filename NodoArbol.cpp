#include "NodoArbol.h"
NodoArbol::NodoArbol(Militar* Pmilitar){
    militar=Pmilitar;
}
NodoArbol::~NodoArbol(){
    //destructor que libera memoria de los nodos hijos
    //y de los militares asignados a cada nodo
    for (int i = 0; i < NodoHijos.size(); i++)
    {
        delete NodoHijos[i];
    }
    NodoHijos.clear();
    delete militar;
}
void NodoArbol::agregarHijo(Militar* Pmilitar){
    //asigna al nodo un nodo hijo
    NodoArbol* Pnodohijo=new NodoArbol(Pmilitar);
    NodoHijos.push_back(Pnodohijo);
}
vector<NodoArbol*> NodoArbol::getHijos(){
    return NodoHijos;
}
Militar* NodoArbol::getMilitar(){
    return militar;
}