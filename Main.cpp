#include <ncurses.h>
#include <iostream>
#include "Militar.h"
#include "NodoArbol.h"
#include <sstream>
using namespace std;
void PreOrden();
void imprimirNcurses();
int main(){
    NodoArbol* raiz=new NodoArbol(new Militar("Yagabarish Skrobernov","M_17","72","General"));
    int opcmenu=0;
    while(opcmenu!=3){
        cout<<"     Menu Ejercito Siberia"<<endl
            <<"1. Agregar Militar"<<endl
            <<"2. Visualizar"<<endl
            <<"3. Salir"<<endl
            <<"Ingrese una opcion: "<<endl;
        cin>>opcmenu;
        if(opcmenu==1){
            int opcsoldado;
            cout<<"     Seleccione que rango de militar desea ingresar:"<<endl
                <<"1. Coronel"<<endl
                <<"2. Mayor"<<endl
                <<"3. Capitan"<<endl
                <<"4. Teniente"<<endl
                <<"5. Sargento"<<endl
                <<"6. Cabo"<<endl
                <<"7. Soldado"<<endl
                <<"Ingrese un opcion:"<<endl;
            cin>>opcsoldado;
            switch (opcsoldado){
                case 1:
                    /* code */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    /* code */
                    break;
                case 5:
                    /* code */
                    break;
                case 6:
                    /* code */
                    break;
                case 7:
                    /* code */
                    break;
                default:
                    break;
            }
        }
        if(opcmenu==2){

        }
    }
    delete raiz;
    return 0;
}
void PreOrden(NodoArbol raiz){
    
}
void imprimirNcurses(){
    initscr();
    
    endwin();
}