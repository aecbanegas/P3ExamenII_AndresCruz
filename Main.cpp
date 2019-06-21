#include <ncurses.h>
#include <iostream>
#include "Militar.h"
#include "NodoArbol.h"
#include <sstream>
#include <fstream>
using namespace std;
void PreOrden(NodoArbol*, stringstream&);
void PreOrdenEspecial(NodoArbol*,vector<NodoArbol*>&,string);
void imprimirNcurses(NodoArbol*);
void guardarArchivo(NodoArbol*);
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
            vector<NodoArbol*> tipoactual;
            string rango;
            switch (opcsoldado){
                case 1:
                    rango="General";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Coronel";
                    break;
                case 2:
                    rango="Coronel";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Mayor";
                    break;
                case 3:
                    rango="Mayor";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Capitan";
                    break;
                case 4:
                    rango="Capitan";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Teniente";
                    break;
                case 5:
                    rango="Teniente";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Sargento";
                    break;
                case 6:
                    rango="Sargento";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Cabo";
                    break;
                case 7:
                    rango="Cabo";
                    PreOrdenEspecial(raiz,tipoactual,rango);
                    rango="Soldado";
                    break;
                
            }
            if(tipoactual.empty()){
                cout<<"El tipo seleccionado no puede ser creado debido"<<endl
                    <<"a que no hay un soldado de grado mayor al que este"<<endl
                    <<"pueda ser asignado!!"<<endl
                    <<"Intente Nuevamente"<<endl;
            }else{
                for (int i = 0; i < tipoactual.size(); i++){
                    cout<<"Posicion: "<<i<<" "<<tipoactual[i]->getMilitar()->getNombre()<<" - "<<tipoactual[i]->getMilitar()->getRango()<<endl;
                }
                cout<<"Ingrese la posicion del soldado al cual desea asignar el nuevo militar: "<<endl;
                int possoldado;
                cin>>possoldado;
                while(possoldado<0||possoldado>=tipoactual.size()){
                    cout<<"Ingrese la posicion del soldado al cual desea asignar el nuevo militar: "<<endl;
                    cin>>possoldado;
                }
                string nombre,codigo,edad;
                cout<<"Ingrese el nombre del militar:"<<endl;
                getline(cin,nombre);
                getline(cin,nombre);
                cout<<"Ingrese el codigo del militar:"<<endl;
                getline(cin,codigo);
                cout<<"Ingrese la edad del militar:"<<endl;
                getline(cin,edad);
                tipoactual[possoldado]->agregarHijo(new Militar(nombre,codigo,edad,rango));
                cout<<"Se ha creado con exito el nuevo integrante militar!"<<endl;
            }
        }
        if(opcmenu==2){
            imprimirNcurses(raiz);
            guardarArchivo(raiz);
        }
    }
    delete raiz;
    return 0;
}
void PreOrden(NodoArbol* nodo, stringstream &textoarchivo){//Imprimir en ncurses
    textoarchivo<<nodo->getMilitar()->toString()<<"\n";
    for (int i = 0; i < nodo->getHijos().size(); i++){
        PreOrden(nodo->getHijos()[i],textoarchivo);
    }
}
void PreOrdenEspecial(NodoArbol* nodo, vector<NodoArbol*> &tipoactual, string rango){//militarTipoActual
    if(rango==nodo->getMilitar()->getRango()){
        tipoactual.push_back(nodo);
    }
    for (int i = 0; i < nodo->getHijos().size(); i++){
        PreOrdenEspecial(nodo->getHijos()[i],tipoactual,rango);
    }
}
void imprimirNcurses(NodoArbol* raiz){
    initscr();
    noecho();
    stringstream acumuladordatos;
    PreOrden(raiz,acumuladordatos);
    string imprimir=acumuladordatos.str();
    char color='n';
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    init_pair(3,COLOR_BLUE,COLOR_RED);
    init_pair(4,COLOR_BLUE,COLOR_WHITE);
    /*char actual='n';
    do
    {
        /* code 
    } while (/* condition );
    */
   do{
       clear();
        if(color=='n'){
            attrset(COLOR_PAIR(1));
            bkgd(COLOR_PAIR(1));
        }else if(color=='i'){
            attrset(COLOR_PAIR(2));
            bkgd(COLOR_PAIR(2));
        }else if(color=='c'){
            attrset(COLOR_PAIR(3));
            bkgd(COLOR_PAIR(3));
        }else if(color=='l'){
            attrset(COLOR_PAIR(4));
            bkgd(COLOR_PAIR(4));
        }
        printw(imprimir.c_str());
   }while((color=getch())!='x');
    refresh();
    endwin();
}
void guardarArchivo(NodoArbol* raiz){
    string nomArchivo;
    cout<<"Ingrese el nombre del archivo:"<<endl;
    cin>>nomArchivo;
    ofstream file;
    string archivoFinalName="Listados/"+nomArchivo+".txt";
    file.open(archivoFinalName);
    stringstream acumuladordatos;
    PreOrden(raiz,acumuladordatos);
    string imprimir=acumuladordatos.str();
    file<<imprimir;
    file.close();
    cout<<"Se ha creado con exito el archivo de texto!"<<endl;
}