#include "ModeloParcial.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"
#include "MultaManager.h"
#include <iostream>

int ModeloParcial::Punto1(){
    AgenteArchivo archAg;
    Agente regAg;
    int cantRegAg = archAg.getCantidadRegistros();

    int* vecAgentes = nullptr;
    vecAgentes = new int[cantRegAg]{};
    if(vecAgentes == nullptr){
        return -1;
    }

    MultaArchivo archMl;
    Multa regMul;
    int cantMultas = archMl.getCantidadRegistros();

    for (int i=0 ; i<cantRegAg ; i++ ){
        regAg = archAg.leer(i);
        for (int j=0 ; j<cantMultas ; j++ ){
            regMul = archMl.leer(j);
            if(regAg.getIdAgente() == regMul.getIDAgente() && regMul.getFechaMulta().getAnio() ==2022 && !regMul.getEliminado()){
                vecAgentes[i]++;
            }
        }
    }

    int cont = 0;
    for (int i=0 ; i<cantRegAg ; i++ ){
        if(vecAgentes[i] == 0){
            cont++;
        }

    }
    return cont;
}

void ModeloParcial::Punto2(){
    AgenteArchivo archAg;
    Agente regAg;
    int cantRegAg = archAg.getCantidadRegistros();

    int* vecAgentes = nullptr;
    float* vecRecaudacion = nullptr;
    vecAgentes = new int[cantRegAg]{};
    vecRecaudacion = new float[cantRegAg]{};
    if(vecAgentes == nullptr || vecRecaudacion == nullptr){
        return ;
    }

    MultaArchivo archMl;
    Multa regMul;
    int cantMultas = archMl.getCantidadRegistros();

    for (int i=0 ; i<cantRegAg ; i++ ){
        regAg = archAg.leer(i);
        for (int j=0 ; j<cantMultas ; j++ ){
            regMul = archMl.leer(j);
            if(regAg.getIdAgente() == regMul.getIDAgente() && regMul.getFechaMulta().getAnio() ==2023 && !regMul.getEliminado()){
                vecAgentes[i]++;
                vecRecaudacion[i] += regMul.getMonto();
            }
        }
    }

    for (int i=0 ; i<cantRegAg ; i++ ){
        regAg = archAg.leer(i);
        std::cout << regAg.getIdAgente() << "  ";
        std::cout << regAg.getApellidos() << " ";
        std::cout << regAg.getNombres() << " ";
        std::cout << vecAgentes[i] << " ";
        std::cout << vecRecaudacion[i] << std::endl;
    }

}

void ModeloParcial::Punto3(){
    int vec[10]={};

    MultaArchivo archMul;
    Multa regMul;
    int cantMul = archMul.getCantidadRegistros();

    for (int i=0 ; i<cantMul ; i++ ){
        regMul = archMul.leer(i);
        if(!regMul.getEliminado()){
            vec[regMul.getTipoInfraccion()-1]++;
        }
    }

    for (int i=0 ; i<10 ; i++ ){
        std::cout << "Tipo " << i+1 << " cantidad: " << vec[i] << std::endl;
    }
}

void ModeloParcial::Punto4(){
    MultaArchivo Multa2022("MultasPagadas2022.dat");
    MultaManager m;
    Multa2022.vaciar();

    MultaArchivo archMul;
    Multa regMul;
    int cantMul = archMul.getCantidadRegistros();

    for (int i=0 ; i<cantMul ; i++ ){
        regMul = archMul.leer(i);
        if(regMul.getFechaMulta().getAnio() == 2022 && regMul.getPagada() && !regMul.getEliminado()){
            Multa2022.guardar(regMul);
        }
    }

    for (int i=0 ; i<Multa2022.getCantidadRegistros() ; i++ ){
        m.Listar(Multa2022.leer(i));
        std::cout<<std::endl;
    }





}


