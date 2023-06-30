#include <iostream>
#include "ListaDeTareas.h"
#include <iomanip>
#include "funciones.h"
using namespace std;


ListaDeTareas::ListaDeTareas(){
    _cantTareas = 0;
}


void ListaDeTareas::Agregar(Tarea t){
    if(_cantTareas < 10){

        _listaTareas[_cantTareas] = t;
        _cantTareas++;
    }

}

void ListaDeTareas::ordenar(){
    Tarea aux;
    for (int i=0 ; i<_cantTareas ; i++ ){
        for (int j=0 ; j<_cantTareas-1 ; j++ ){
            if(_listaTareas[j].getFechaLimite().toString("YYYY/MM/DD") > _listaTareas[j+1].getFechaLimite().toString("YYYY/MM/DD")){
                aux = _listaTareas[j];
                _listaTareas[j] = _listaTareas[j+1];
                _listaTareas[j+1] = aux;
            }
        }
    }
}


void ListaDeTareas::Mostrar(){

    ordenar();

    for (int i=0 ; i< _cantTareas ; i++ ){

        cout << setw(3) << setiosflags(ios::left) << _listaTareas[i].getId();
        cout << setw(40) << setiosflags(ios::left) << _listaTareas[i].getDescripcion();
        cout << setw(10) << setiosflags(ios::left) << _listaTareas[i].getDificultad();
        cout << setw(15) << setiosflags(ios::left) << _listaTareas[i].getFechaLimite().toString();
        cout << setw(15) << setiosflags(ios::left) << _listaTareas[i].getEstado() << endl;
    }

}

void ListaDeTareas::MostrarTarea(int id){
    cout << "-------------------------" << endl;
    cout << " ESTADO DEL ID INGRESADO " << endl;
    cout << "-------------------------" << endl;
    for (int i=0 ; i<_cantTareas; i++ ){
        if(_listaTareas[i].getId() == id){
            _listaTareas[i].Mostrar();
        }
    }

}

void ListaDeTareas::ModificarEstado(int id){
    for (int i=0 ; i<_cantTareas ; i++ ){
        if(_listaTareas[i].getId() == id ){
            _listaTareas[i].setEstado("Hecho");
        }
    }

}



void ListaDeTareas::mostrarDeadLine(){

    for (int i=0 ; i<_cantTareas; i++ ){
        cout << setw(3) << setiosflags(ios::left) << _listaTareas[i].getId();
        cout << setw(40) << setiosflags(ios::left) << _listaTareas[i].getDescripcion();
        cout << setw(15) << setiosflags(ios::left) << _listaTareas[i].getFechaLimite().toString();
        cout << setw(15) << "Dias faltantes: " << contarDiasFaltantes(_listaTareas[i].getFechaLimite()) << endl;

    }

}


listaDeTareas::ListaDeTareas* getLista(){return *_listaTareas;}
