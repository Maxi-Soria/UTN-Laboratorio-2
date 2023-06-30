#include "RecuperatorioPrimerParcial.h"
#include "ClasesParticularesArchivo.h"
#include "EstudiantesArchivo.h"
#include <cstring>
#include <iostream>



void RecuperatorioPrimerParcial::cursoConMayorAyuda(){
    ClasesParticularesArchivo archClasePart;
    ClaseParticular regClasepart;
    int cantRegCPart = archClasePart.getCantidad();

    int vecMinutosPorCurso[10]={};

    for (int i=0 ; i< cantRegCPart ; i++ ){
        regClasepart = archClasePart.leer(i);
        vecMinutosPorCurso[regClasepart.getIdCurso()-1] += regClasepart.getDuracion();
    }
    int maxDuracion = 0;

    for (int i=0 ; i<10 ; i++ ){
        if(vecMinutosPorCurso[i] > maxDuracion){
            maxDuracion = vecMinutosPorCurso[i];
        }
    }

    std::cout<<"Mayor duracion " << maxDuracion << " minutos y el/los cursos es/son " <<std::endl;

    for (int i=0 ; i<10 ; i++ ){
        if(vecMinutosPorCurso[i] == maxDuracion){
            std::cout<< "Curso #" <<  i+1 << std::endl;
        }
    }
}


void RecuperatorioPrimerParcial::alumnosConPocaAyuda(){
    EstudiantesArchivo archEst;
    Estudiante regEst;
    int cantEst = archEst.getCantidad();

    ClasesParticularesArchivo archClasPart;
    ClaseParticular regClasPart;
    int cantClasPart = archClasPart.getCantidad();

    for (int i=0 ; i<cantEst ; i++ ){
        bool masDeUnaHora = false;
        regEst = archEst.leer(i);
        for (int j=0 ; j<cantClasPart ; j++ ){
            regClasPart = archClasPart.leer(j);
            if(regEst.getLegajo() == regClasPart.getLegajoAlumno() && regClasPart.getDuracion() > 60){
                masDeUnaHora = true;
            }
        }
        if(!masDeUnaHora){
            std::cout << regEst.getLegajo() << "     " << regEst.getNombres() << std::endl;
        }
    }


}

class Estadistica{
private:
    int _IdCurso;
    float _promedio;
public:
    void setIdcurso(int idcurso){_IdCurso = idcurso;}
    void setPromedio(float promedio){_promedio = promedio;}
    int getIdCurso(){return _IdCurso;}
    float getPromedio(){return _promedio;}
    void Mostrar(){
        std::cout << "Id curso: " << _IdCurso << " promedio de recaudacion: $" << _promedio << std::endl;
    }
};

class ArchivoEstadistica{
private:
    char nombre[15];
public:
    ArchivoEstadistica(){
        strcpy(nombre,"estadistica.dat");
    }
    ///ABRE Y GUARDA EN EL ARCHIVO
    bool guardar(Estadistica reg) {
        FILE* p = fopen(nombre, "ab");
        if (p == NULL) {
            return false;
        }
        bool ok = fwrite(&reg, sizeof(Estadistica), 1, p);
        fclose(p);
        return ok;
    }
    ///LEER UN REGISTRO
    Estadistica leer(int pos){
    Estadistica reg;
    FILE* pFile = fopen("estadistica.dat", "rb");
    if (pFile != NULL)
    {
        fseek(pFile, pos * sizeof(Estadistica), SEEK_SET);
        fread(&reg, sizeof(Estadistica), 1, pFile);
        fclose(pFile);
    }
    return reg;
    }

    ///CONTAR REGISTROS
    int getCantidad() {
        FILE* p = fopen("estadistica.dat", "rb");
        if (p == NULL) {
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Estadistica);
        fclose(p);
        return cant;
    }
    ///VACIAR ARCHIVO
    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL)
        {
        return ;
        }
        fclose(p);
    }



};


void RecuperatorioPrimerParcial::generarEstadistica(){
    float vecRecaudacion[10] = {};
    int vecCont[10]={};


    ClasesParticularesArchivo archCl;
    ClaseParticular regCl;
    int cantRegCl = archCl.getCantidad();

    for (int i=0 ; i<cantRegCl ; i++ ){
        regCl = archCl.leer(i);
        vecRecaudacion[regCl.getIdCurso()-1] += regCl.getMonto();
        vecCont[regCl.getIdCurso()-1]++;
    }


    ArchivoEstadistica archEsta;
    Estadistica regEsta;
    archEsta.vaciar();

    for (int i=0 ; i<10 ; i++ ){
        vecRecaudacion[i] = vecRecaudacion[i]/vecCont[i];
        regEsta.setIdcurso(i+1);
        regEsta.setPromedio(vecRecaudacion[i]);
        archEsta.guardar(regEsta);
    }
}

void RecuperatorioPrimerParcial::mostrarEstadistica(){
    ArchivoEstadistica archEsta;
    int cantReg = archEsta.getCantidad();

    for (int i=0 ; i<cantReg ; i++ ){
        archEsta.leer(i).Mostrar();
    }
}

void RecuperatorioPrimerParcial::nuncaRecibioAyuda(int legajoProf){

    EstudiantesArchivo archEst;
    Estudiante regEst;
    int cantRegEst = archEst.getCantidad();

    ClasesParticularesArchivo archCl;
    ClaseParticular regCl;
    int cantReg = archCl.getCantidad();

    std::cout<<"Estudiantes a los que el profesor " << legajoProf << " no ayudo"<<std::endl;
    for (int i=0 ; i<cantRegEst ; i++ ){
            bool ayudo = false;
            regEst = archEst.leer(i);

        for (int j=0 ; j<cantReg ; j++ ){
            regCl = archCl.leer(j);
            if(regEst.getLegajo() == regCl.getLegajoAlumno() && regCl.getLegajoProfesor() == legajoProf){

                ayudo = true;
            }
        }
        if(ayudo == false){
            std::cout<<regEst.getLegajo()<<std::endl;
        }
    }

}





