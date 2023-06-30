#include "ModeloDeParcial.h"
#include "AgenteArchivo.h"

#include <iostream>


ModeloDeParcial::ModeloDeParcial(){

}

void ModeloDeParcial::Punto1(){
    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();

    bool vec2022[10] = {false};
    bool vec2021[10] = {false};

    for (int i=0 ; i<cantMultas ; i++ ){
        regMulta = archMulta.leer(i);
        if(regMulta.getFechaMulta().getAnio() == 2022 && !regMulta.getEliminado()){
            vec2022[regMulta.getTipoInfraccion()] = true;
        }
        if(regMulta.getFechaMulta().getAnio() == 2021 && !regMulta.getEliminado()){
            vec2021[regMulta.getTipoInfraccion()-1] = true;
        }
    }
    std::cout << "Los tipos de infraccion de punto 1 son: ";
    for (int i=0 ; i<10 ; i++ ){
        if(vec2022[i] && !vec2021[i]){
            std::cout << i+1 << " ";
        }
    }
std::cout << std::endl;
}

void ModeloDeParcial::Punto2(){
    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();
    float mayorMonto = 0;
    int idAgenteMax;
    int idMultaMax;

    for (int i=0 ; i<cantMultas ; i++ ){
        regMulta = archMulta.leer(i);
        if(regMulta.getPagada() && !regMulta.getEliminado() && regMulta.getMonto() > mayorMonto){
            mayorMonto = regMulta.getMonto();
            idAgenteMax = regMulta.getIDAgente();
            idMultaMax = regMulta.getIDMulta();
        }
    }

    AgenteArchivo archAgente;
    Agente regAgente;
    int cantAgentes = archAgente.getCantidadRegistros();

    std::cout<<"Punto 2 "<<std::endl;
    std::cout<<"--------"<<std::endl;

    for (int i=0 ; i<cantAgentes ; i++ ){
        regAgente = archAgente.leer(i);
        if(regAgente.getIdAgente() == idAgenteMax){
            std::cout << "Multa: " << idMultaMax << std::endl;
            std::cout << "Monto: $" << mayorMonto << std::endl;
            std::cout << "Id agente: " << idAgenteMax << std::endl;
            std::cout << "Apellido: " << regAgente.getApellidos() << std::endl;
            std::cout << "Nombre: " << regAgente.getNombres() << std::endl;
        }
    }


}

void ModeloDeParcial::Punto3(){
    AgenteArchivo archAgente;
    Agente regAgente;
    int cantAgentes = archAgente.getCantidadRegistros();

    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();
    int cont = 0;

    for (int i=0 ; i<cantAgentes ; i++ ){
        regAgente = archAgente.leer(i);
        bool cumpleCondcion = false;

        for (int j=0 ; j<cantMultas ; j++ ){
            regMulta = archMulta.leer(j);
            if(!cumpleCondcion && regAgente.getIdAgente() == regMulta.getIDAgente() && regMulta.getMonto() > 25000 && !regMulta.getEliminado()){
                cumpleCondcion = true;
                cont++;
            }
        }
    }

    std::cout <<"La cantidad de agentes del punto C es: " << cont << std::endl;
}

void ModeloDeParcial::Punto4(){
    AgenteArchivo archAgente;
    Agente regAgente;
    int cantAgentes = archAgente.getCantidadRegistros();

    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();

    for (int i=0 ; i<cantAgentes ; i++ ){
        regAgente = archAgente.leer(i);
        bool vecMultas[10]={false};
        bool repitioTipo = false;
        for (int j=0 ; j<cantMultas ; j++ ){
            regMulta = archMulta.leer(j);
            if(regAgente.getIdAgente() == regMulta.getIDAgente() && !regMulta.getEliminado() && regMulta.getFechaMulta().getAnio() == 2022){
                if(!vecMultas[regMulta.getTipoInfraccion()-1]){
                    vecMultas[regMulta.getTipoInfraccion()-1] = true;
                }
                else{
                    repitioTipo = true;
                }

            }
        }
        if(repitioTipo){
            std::cout<<"Id Agente: "<< regAgente.getIdAgente() <<"  Apellido: "<<regAgente.getApellidos() << "  Nombre: " << regAgente.getNombres()<<std::endl;
        }
    }
}
