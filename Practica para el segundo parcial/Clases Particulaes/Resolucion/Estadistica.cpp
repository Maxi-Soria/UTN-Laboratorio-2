#include "Estadistica.h"
#include <iostream>

void Estadistica::Mostrar(){
    std::cout<<"Curso #"<<idCurso<<std::endl;
    std::cout<<"Recaudacion"<<recaudacio<<std::endl;

}

void Estadistica::setIdCurso(int id){
    idCurso = id;
}


void Estadistica::setRecaudacion(float rec){
    recaudacio = rec;
}

