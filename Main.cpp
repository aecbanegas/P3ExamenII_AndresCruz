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
    NodoArbol* raiz=new NodoArbol(new Militar("Yagabarish Skrobernov","M_17","72","General"));//nodo principal raiz, unico que contiene militar de rango general
    int opcmenu=0;//variable que guarda la opcion seleccionada
    while(opcmenu!=3){
        cout<<"     Menu Ejercito Siberia"<<endl
            <<"1. Agregar Militar"<<endl
            <<"2. Visualizar"<<endl
            <<"3. Salir"<<endl
            <<"Ingrese una opcion: "<<endl;
        cin>>opcmenu;
        if(opcmenu==1){//Ejercicio 1, Agregar Militares al nodo principal
            int opcsoldado;//menu de rangos
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
            vector<NodoArbol*> tipoactual;//vector donde se guardaran los militares con el mismo rango al seleccionado
            string rango;
            switch (opcsoldado){//switch menu de rangos
                /*
                al obtener la opcion seleccionada, se le asigna a rango temporalmente el nombre de rango superior,
                para asignar a este un hijo, luego de llamar el metodo recursivo se cambia nuevamente el contenido
                de la variable al rango seleccionado para reutilizar la variable
                */
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
                /*
                si el vector esta vacio significa que no existe algun militar que tenga un rango superior inmediato
                por lo que un nuevo militar no puede ser asignado como hijo en el arbol
                */
                cout<<"El tipo seleccionado no puede ser creado debido"<<endl
                    <<"a que no hay un soldado de grado mayor al que este"<<endl
                    <<"pueda ser asignado!!"<<endl
                    <<"Intente Nuevamente"<<endl;
            }else{
                for (int i = 0; i < tipoactual.size(); i++){//muestra las posicion y los militares superiores
                    cout<<"Posicion: "<<i<<" "<<tipoactual[i]->getMilitar()->getNombre()<<" - "<<tipoactual[i]->getMilitar()->getRango()<<endl;
                }
                cout<<"Ingrese la posicion del soldado al cual desea asignar el nuevo militar: "<<endl;
                int possoldado;
                cin>>possoldado;
                while(possoldado<0||possoldado>=tipoactual.size()){
                    cout<<"Ingrese la posicion del soldado al cual desea asignar el nuevo militar: "<<endl;
                    cin>>possoldado;
                }
                //llenado de variables para instanciar militares
                string nombre,codigo,edad;
                cout<<"Ingrese el nombre del militar:"<<endl;
                getline(cin,nombre);
                getline(cin,nombre);
                cout<<"Ingrese el codigo del militar:"<<endl;
                getline(cin,codigo);
                cout<<"Ingrese la edad del militar:"<<endl;
                getline(cin,edad);
                //se agrega hijo al nodo seleccionado
                tipoactual[possoldado]->agregarHijo(new Militar(nombre,codigo,edad,rango));
                cout<<"Se ha creado con exito el nuevo integrante militar!"<<endl;
            }
        }
        if(opcmenu==2){
            //llamado de metodos para visualizar
            /*
                imprimirNcurses muestra y enlista los militares, dependiendo de su rango
                y permite cambio de color de la pantalla de manera dinamica
            */
            imprimirNcurses(raiz);
            /*
                guarda un archivo con nombre elegido por el usuario que contiene el listado 
                obtennido anteriormente
            */
            guardarArchivo(raiz);
        }
    }
    delete raiz;
    return 0;
}
void PreOrden(NodoArbol* nodo, stringstream &textoarchivo){//Imprimir en ncurses
    textoarchivo<<nodo->getMilitar()->toString()<<"\n";//asigna los toString obtenidos de militares a un stringstream
    for (int i = 0; i < nodo->getHijos().size(); i++){//continua con el siguiente hijo
        PreOrden(nodo->getHijos()[i],textoarchivo);//llamado metodo recursivo
    }
}
void PreOrdenEspecial(NodoArbol* nodo, vector<NodoArbol*> &tipoactual, string rango){//militarTipoActual
    if(rango==nodo->getMilitar()->getRango()){//verifica que el rango del militar actual sea el mismo que el que se busca para agregarlo a la lista
        tipoactual.push_back(nodo);
    }
    for (int i = 0; i < nodo->getHijos().size(); i++){//continua con el siguiente hijo
        PreOrdenEspecial(nodo->getHijos()[i],tipoactual,rango);//llamado metodo recursivo
    }
}
void imprimirNcurses(NodoArbol* raiz){
    initscr();//abre la ventana de ncurses
    noecho();//no muestra los caracteres al escribirlos
    stringstream acumuladordatos;
    PreOrden(raiz,acumuladordatos);
    string imprimir=acumuladordatos.str();
    char color='n';
    start_color();//inicializacion de colores
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
   do{//do while
       clear();
        if(color=='n'){//asignacion de colores segun caracter
            attrset(COLOR_PAIR(1));//asigna color a escritura
            bkgd(COLOR_PAIR(1));//asigna color al fondo
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
   }while((color=getch())!='x');//condicion para poder cambiar colores cuantas veces quiera
    refresh();//refrescar el contenido de la pantalla de ncurses
    endwin();//cierre de ventana
}
void guardarArchivo(NodoArbol* raiz){//metodo para guardar archivo
    string nomArchivo;
    cout<<"Ingrese el nombre del archivo:"<<endl;
    cin>>nomArchivo;
    ofstream file;//archivo de escritura
    string archivoFinalName="Listados/"+nomArchivo+".txt";
    file.open(archivoFinalName);//apertura de archivo
    stringstream acumuladordatos;
    PreOrden(raiz,acumuladordatos);//llamado a metodo recursivo
    string imprimir=acumuladordatos.str();
    file<<imprimir;//meter los datos en archivo
    file.close();//cerrar archivo
    cout<<"Se ha creado con exito el archivo de texto!"<<endl;
}