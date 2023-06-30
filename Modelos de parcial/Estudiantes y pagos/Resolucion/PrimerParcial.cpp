#include <iostream>
#include "PrimerParcial.h"
#include "PagosArchivo.h"
#include "EstudiantesArchivo.h"
#include <iomanip>
#include <cstring>



void PrimerParcial::listarRecaudacion(){

    float vecRecaudacion[10]={};
    PagosArchivo archPago;
    Pago regPago;
    int cantRegPago = archPago.getCantidad();

    for (int i=0 ; i<cantRegPago ; i++ ){
        regPago = archPago.leer(i);

        int anio = regPago.getFecha().getAnio();
        int mes = regPago.getFecha().getMes();
        int dia = regPago.getFecha().getDia();

        if((anio > 2020) || (anio == 2020 && mes > 5) || (anio == 2020 && mes == 5 && dia >= 10)  ){
            vecRecaudacion[regPago.getIdCurso()-1] += regPago.getMonto();
        }
    }

    for (int i=0 ; i<10 ; i++ ){
        std::cout << "Curso " << i+1 << " recaudacion $ " << vecRecaudacion[i] << std::endl;

    }


}

void PrimerParcial::listarAlumnosNoMorosos(){
    EstudiantesArchivo archEstud;
    Estudiante regEstud;
    int cantRegEstudiantes = archEstud.getCantidad();

    PagosArchivo archPago;
    Pago regPago;
    int cantRegPago = archPago.getCantidad();
    std::cout << "Los legajos de los alumnos que nunca realizaron un pago vencido son: "<< std::endl;

    for (int i=0 ; i<cantRegEstudiantes ; i++ ){
            regEstud = archEstud.leer(i);
            bool pagoVenc = false;
        for (int j=0 ; j<cantRegPago ; j++ ){
            regPago = archPago.leer(j);

            if(regEstud.getLegajo() == regPago.getLegajo() && regPago.esPagovencido()){
                pagoVenc = true;
            }
        }
        if(!pagoVenc){
            std::cout << regEstud.getLegajo() << " " ;
        }
    }
    std::cout<<std::endl;
}

void PrimerParcial::soloUnCurso(){
    EstudiantesArchivo archEstud;
    Estudiante regEstud;
    int cantRegEstudiantes = archEstud.getCantidad();

    PagosArchivo archPago;
    Pago regPago;
    int cantRegPago = archPago.getCantidad();

    for (int i=0 ; i<cantRegEstudiantes ; i++ ){

            int cursoPagado = 0;

            regEstud = archEstud.leer(i);

        for (int j=0 ; j<cantRegPago ; j++ ){

            regPago = archPago.leer(j);

            if(regEstud.getLegajo() == regPago.getLegajo() && regPago.getAnio() == 2021){
                cursoPagado++;
            }
        }
        if(cursoPagado == 1){
            std::cout << std::left <<std::setw(6) << regEstud.getLegajo();
            std::cout << std::setw(11) << regEstud.getNombres();
            std::cout << std::setw(11) << regEstud.getApellidos() << std::endl;

        }
    }
}

class Estadistica{
private:
    int _anio;
    float _recaudacion;
public:
    void setAn(int anio){_anio = anio;}
    void setRecaudacion(float recaudacion){_recaudacion = recaudacion;}
    void Mostrar(){
    std::cout << "Anio " << _anio << " recaudacion: $" << _recaudacion << std::endl;
    }
};

class ArchivoEstadistica{
private:
    char nombre[16];
public:
    ArchivoEstadistica(){
        strcpy(nombre,"estadistica.dat");
    }
    ///ESCRIBIR-------------------------------------------------
    bool escribirRegistro(Estadistica reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    void vaciar(){
    FILE *p = fopen(nombre, "wb");
    if (p == NULL)
    {
      return ;
    }
    fclose(p);
    }
    ///LISTAR ------------------------------------------------------
    bool listarArchivo(){
        Estadistica reg;
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL){
        std::cout << "No se pudo abrir " << std::endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.Mostrar();
        std::cout << std::endl;
        }
        fclose(p);
        return true;
        }
    ///CONTAR -------------------------------------------
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Estadistica);
    }
    ///LEER----------------------------------------------
    Estadistica leer(int nroRegistro){
        Estadistica reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return reg;
        }
        fseek(p, nroRegistro * sizeof(Estadistica), SEEK_SET);
        fread(&reg, sizeof(Estadistica), 1, p);
        fclose(p);
        return reg;
    }
};







void PrimerParcial::generarEstadistica(){

  int vecRecaudacionAnios[3000]={};

  PagosArchivo archPG;
  Pago regPG;

  ArchivoEstadistica archEstad;
  Estadistica regEstad;

  archEstad.vaciar();

  int cantRegPago = archPG.getCantidad();

  for (int i=0 ; i<cantRegPago ; i++ ){
      regPG = archPG.leer(i);
      vecRecaudacionAnios[regPG.getAnio()-1] += regPG.getMonto();
  }

  for (int i=0 ; i<3000 ; i++ ){
     if(vecRecaudacionAnios[i]>0){
        regEstad.setAn(i+1);
        regEstad.setRecaudacion(vecRecaudacionAnios[i]);
        archEstad.escribirRegistro(regEstad);
     }
  }

}

void PrimerParcial::mostrarEstadistica(){
    ArchivoEstadistica archEstad;
    Estadistica regEstad;
    int cant = archEstad.contarRegistros();

    for (int i=0 ; i<cant ; i++ ){
        regEstad = archEstad.leer(i);
        regEstad.Mostrar();
    }


}

void PrimerParcial::cursosPremium(int legajo){
    bool vecPagoCursos[10] = {};
    float maxPago = 0;

    PagosArchivo archPago;
    Pago regPago;
    int cantRegPago = archPago.getCantidad();

    for (int i=0 ; i<cantRegPago ; i++ ){
        regPago = archPago.leer(i);
        if(regPago.getLegajo() == legajo && regPago.getMonto() > maxPago){
            maxPago = regPago.getMonto();
        }
    }

    for (int i=0 ; i<cantRegPago ; i++ ){
        regPago = archPago.leer(i);
        if(regPago.getLegajo() == legajo &&  maxPago == regPago.getMonto()){
            vecPagoCursos[regPago.getIdCurso()-1] = true;
        }
    }

    std::cout << "El legajo " << legajo << " realizo el mayor pago individual a el/los curso/cursos: ";
    for (int i=0 ; i<10 ; i++ ){
        if(vecPagoCursos[i]){
            std::cout << i+1 << " ";
        }
    }
    std::cout<<std::endl;


}


