#include "RecuperatorioParcial.h"
#include "EstadisticaArchivo.h"


void RecuperatorioParcial::cursoConMayorAyuda(){
    ClasesParticularesArchivo archParticular;
    ClaseParticular regParticular;
    int cantRegPart = archParticular.getCantidad();

    int vecHorasCurso[10]={};
    int maxDuracion = 0;;

    for (int i=0 ; i<cantRegPart ; i++ ){
        regParticular = archParticular.leer(i);
        vecHorasCurso[regParticular.getIdCurso()-1]+=regParticular.getDuracion();
    }

    for (int i=0 ; i<10 ; i++ ){
        if(vecHorasCurso[i]>maxDuracion){
            maxDuracion = vecHorasCurso[i];
        }
    }

    std::cout<< "Los ID de cursos del punto 1 son: ";
    for (int i=0 ; i<10 ; i++ ){
        if(vecHorasCurso[i] == maxDuracion){
            std::cout<<i+1 << " ";
        }
    }
    std::cout<<std::endl;
}


void RecuperatorioParcial::alumnosConPocaAyuda(){
    EstudiantesArchivo archEst;
    Estudiante regEst;
    int cantRegEst = archEst.getCantidad();

    ClasesParticularesArchivo archParticular;
    ClaseParticular regParticular;
    int cantRegPart = archParticular.getCantidad();

    std::cout<<"LEGAJO   NOMBRE"<<std::endl;
    for (int i=0 ; i<cantRegEst ; i++ ){
        regEst = archEst.leer(i);
        bool masDeUnaHora = false;
        for (int j=0 ; j<cantRegPart ; j++ ){
            regParticular = archParticular.leer(j);
            if(regEst.getLegajo() == regParticular.getLegajoAlumno() && regParticular.getDuracion() > 60){
                masDeUnaHora = true;
            }
        }
        if(!masDeUnaHora){
            std::cout<<regEst.getLegajo() << "  " << regEst.getNombres() << std::endl;
        }
    }

    std::cout<<std::endl;
}



void RecuperatorioParcial::generarEstadisticasAyuda(){
    ArchivoEstadistica archEstad;
    Estadistica regEst;
    archEstad.vaciar();

    ClasesParticularesArchivo archParticular;
    ClaseParticular regParticular;
    int cantRegPart = archParticular.getCantidad();

    float vecRecCurso[10]={};

    for (int i=0 ; i<cantRegPart ; i++ ){
        regParticular = archParticular.leer(i);
        vecRecCurso[regParticular.getIdCurso()-1] += regParticular.getMonto();
    }

    for (int i=0 ; i<10 ; i++ ){
        regEst.setIdCurso(i+1);
        regEst.setRecaudacion(vecRecCurso[i]);
        archEstad.guardar(regEst);
    }

}


void RecuperatorioParcial::mostrarEstadisticas(){
    ArchivoEstadistica obj;
    Estadistica reg;

    int cant = obj.getCantidad();

    for (int i=0 ; i<cant ; i++ ){
        obj.leer(i).Mostrar();

    }


}













