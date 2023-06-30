#include "ModeloParcial.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"
#include "MultaManager.h"
#include <iostream>
#include <iomanip>




void ModeloParcial::Punto1(){
    AgenteArchivo archAgente;
    Agente regAgente;
    int cantAgentes = archAgente.getCantidadRegistros();

    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();

    int cont = 0;

    for (int i=0 ; i<cantAgentes ; i++ ){
        regAgente = archAgente.leer(i);
        bool multoEn2022 = false;
        for (int j=0 ; j<cantMultas ; j++ ){
            regMulta = archMulta.leer(j);
            if(regAgente.getIdAgente() == regMulta.getIDAgente() && regMulta.getFechaMulta().getAnio() == 2022 && !regMulta.getEliminado()){
                    multoEn2022 = true;
            }
        }
        if(!multoEn2022){cont++;}
    }
    std::cout<<"La cantidad de agentes del Punto 1 es: " << cont << std::endl;

}

void ModeloParcial::Punto2(){
    AgenteArchivo archAgente;
    Agente regAgente;
    int cantAgentes = archAgente.getCantidadRegistros();

    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();

    for (int i=0 ; i<cantAgentes ; i++ ){
        regAgente = archAgente.leer(i);
        int contMultas = 0;
        float acuMonto = 0;
        for (int j=0 ; j<cantMultas ; j++ ){
            regMulta = archMulta.leer(j);
            if(regAgente.getIdAgente() == regMulta.getIDAgente() && regMulta.getFechaMulta().getAnio() == 2023 && !regMulta.getEliminado()){
                contMultas++;
                acuMonto += regMulta.getMonto();
            }
        }
        std::cout<<std::left<<std::setw(5)<<regAgente.getIdAgente()<<std::setw(15)<<regAgente.getApellidos()<<std::setw(15)<<regAgente.getNombres()<<std::setw(3)<<contMultas<<std::setw(8)<<acuMonto<<std::endl;

    }

}

void ModeloParcial::Punto3(){
    MultaArchivo archMulta;
    Multa regMulta;
    int cantMultas = archMulta.getCantidadRegistros();

    int vecTipoInfraccion[10]={};

    for (int i=0 ; i<cantMultas ; i++ ){
        regMulta = archMulta.leer(i);
        vecTipoInfraccion[regMulta.getTipoInfraccion()-1]++;
    }

    std::cout << "Multa  cantidad"<<std::endl;
    for (int i=0 ; i<10 ; i++ ){
        std::cout<<"# "<<i+1<<"       "<<vecTipoInfraccion[i]<<std::endl;
    }

}

void ModeloParcial::Punto4(){
    MultaManager obj;
    MultaArchivo archMulta , archMulta2022("MultasPagadas2022.dat");
    Multa regMulta;
    int cantRegMulta = archMulta.getCantidadRegistros();

    archMulta2022.vaciar();

    for (int i=0 ; i<cantRegMulta ; i++ ){
        regMulta = archMulta.leer(i);
        if(!regMulta.getEliminado() && regMulta.getFechaMulta().getAnio() == 2022 && regMulta.getPagada()){
            archMulta2022.guardar(regMulta);
        }
    }

    int cant = archMulta2022.getCantidadRegistros();

    for (int i=0 ; i<cant ; i++ ){
        obj.Listar(archMulta2022.leer(i));
        std::cout<<std::endl;
    }





}

