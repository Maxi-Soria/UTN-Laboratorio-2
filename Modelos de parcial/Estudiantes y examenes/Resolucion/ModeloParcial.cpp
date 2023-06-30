#include <iostream>
#include <iomanip>
#include "EstudiantesArchivo.h"
#include "ExamenesArchivo.h"
#include "ModeloParcial.h"


//using namespace std;

void  ModeloParcial::Punto1(){
    EstudiantesArchivo archEstud;
    Estudiante regEst;
    int cantRegEstudiantes =  archEstud.getCantidad();

    ExamenesArchivo archExam;
    Examen regExam;
    int cantRegExamenes = archExam.getCantidad();

    std::cout << std::setw(6) << "LEGAJO" << std::setw(12) << "APELLIDO" << std::setw(13) << "NOMBRE" << std::endl;
    for (int i=0 ; i<cantRegEstudiantes ; i++ ){
            bool rindioEn2022 = false;
            regEst = archEstud.leer(i);

        for (int j=0 ; j<cantRegExamenes ; j++ ){
            regExam = archExam.leer(j);
            if(regEst.getLegajo() == regExam.getLegajo() && regExam.getFecha().getAnio() == 2022 ){
                rindioEn2022 = true;
            }
        }
        if(!rindioEn2022){
           std::cout << std::left<<std::setw(10)<< regEst.getLegajo() <<std::setw(15) << regEst.getApellidos() << std::setw(15)<< regEst.getNombres() << std::endl;
        }
    }
}

void ModeloParcial::Punto2(){
    EstudiantesArchivo archEstud;
    Estudiante regEst;
    int cantRegEstudiantes =  archEstud.getCantidad();

    ExamenesArchivo archExam;
    Examen regExam;
    int cantRegExamenes = archExam.getCantidad();

    //std::cout << std::setw(6) << "LEGAJO" << std::setw(12) << "APELLIDO" << std::setw(13) << "NOMBRE" << std::endl;
    for (int i=0 ; i<cantRegEstudiantes ; i++ ){
        int contExamAprob = 0;
        int contExamDesap = 0;

        regEst = archEstud.leer(i);

        for (int j=0 ; j<cantRegExamenes ; j++ ){
            regExam = archExam.leer(j);
            if(regEst.getLegajo() == regExam.getLegajo() ){
                if(regExam.getNota() >= 6){
                    contExamAprob++;
                }else{
                    contExamDesap++;
                }

            }
        }
        std::cout << std::left<<std::setw(10)<< regEst.getLegajo();
        std::cout << std::setw(15) << regEst.getApellidos();
        std::cout << std::setw(15)<< regEst.getNombres();
        std::cout << std::setw(6) << contExamAprob << std::setw(6) << contExamDesap << std::endl;
    }
}

void ModeloParcial::Punto3(){

    int cont = 0;

    EstudiantesArchivo archEstud;
    Estudiante regEst;
    int cantRegEstudiantes =  archEstud.getCantidad();

    ExamenesArchivo archExam;
    Examen regExam;
    int cantRegExamenes = archExam.getCantidad();

    for (int i=0 ; i<cantRegEstudiantes ; i++ ){
            regEst = archEstud.leer(i);
            int vecMaterias[60]={};

        for (int j=0 ; j<cantRegExamenes ; j++ ){
            regExam = archExam.leer(j);
                if(regEst.getLegajo() == regExam.getLegajo() && regExam.getFecha().getAnio() >= 2018  && regExam.getFecha().getAnio() <= 2022){
                    if(vecMaterias[regExam.getIDMateria()-1] == false){
                        vecMaterias[regExam.getIDMateria()-1] = true;
                    }
                    else{
                        cont++;
                        j=cantRegExamenes;
                    }
                }
            }
    }
        std::cout << "El total de alumnos que rindio mas de una vez examen para la misma materia entre los años 2018 y 2022 es: " << cont << std::endl;

}

