#include <iostream>
#include "Tarea.h"

using namespace std;

Tarea::Tarea(){
    _id = 0;
    _descripcion = "Sin Dato";
    _dificultad = "Sin Dato";
    _estado = "Sin Dato";
}

Tarea::Tarea(int id, std::string descripcion,std::string dificultad, Fecha fechaLimite, std::string estado){
    _id = id;
    _descripcion = descripcion;
    _dificultad = dificultad;
    _fechaLimite = fechaLimite;
    _estado = estado;
}


void Tarea::Cargar(){
    int dia = 3, mes = 5, anio = 2020;
    cout << "Ingrese id: ";
    cin >> _id;
    cin.ignore();
    cout << "Ingrese la descripcion: ";
    getline(cin,_descripcion);
    cout << "Ingrese la dificultad: ";
    cin >> _dificultad;
    cout << "Ingrese la fecha limite: " << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;
    _fechaLimite = Fecha(dia,mes,anio);
    cout << "Ingrse el estado: ";
    cin >>_estado;
    cout << endl;

}

void Tarea::Mostrar(){
    cout << "ID : " <<_id << endl;
    cout << "DESCRIPCION: " << _descripcion << endl;
    cout << "DIFICULTAD: " << _dificultad << endl;
    cout << "FECHA LIMITE: ";
    cout << _fechaLimite.toString("DD/MM/AAAA") << endl;
    cout << "ESTADO: " << _estado << endl;
    cout << endl;
}


///GETERS
int Tarea::getId(){return _id;}
string Tarea::getDescripcion(){return _descripcion;}
string Tarea::getDificultad(){return _dificultad;}
Fecha Tarea::getFechaLimite(){return _fechaLimite;}
string Tarea::getEstado(){return _estado;}

void Tarea::setID(int ID){_id = ID;}
void Tarea::setDescripcion(std::string descripcion){_descripcion = descripcion;}
void Tarea::setFechaLimite(Fecha fechaLimite){_fechaLimite = fechaLimite;}
void Tarea::setNivelDificultad(int dificultad){_dificultad = dificultad;}
void Tarea::setEstado(std::string estado){_estado = estado;}
