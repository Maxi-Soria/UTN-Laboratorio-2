#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "ListaDeTareas.h"

using namespace std;


Tarea CargarTarea(){
    Tarea t;
    t.Cargar();
    return t;
}

ListaDeTareas harcodeoLista(){
    ListaDeTareas lista;
    lista.Agregar(Tarea(1, "Crear concepto del videojuego", "Media", Fecha(30,4,2023) ,"Hecho"));
    lista.Agregar(Tarea(2, "Diseñar niveles", "Alta", Fecha(15,5,2023) ,"Hecho"));
    lista.Agregar(Tarea(3, "Crear sprites", "Media", Fecha(30,5,2023), "Pendiente"));
    lista.Agregar(Tarea(4, "Desarrollar la mecánica del juego" ,"Alta" ,Fecha(15,6,2023), "Pendiente"));
    lista.Agregar(Tarea(5, "Programar el juego" ,"Alta", Fecha(30,6,2023) ,"Pendiente"));
    lista.Agregar(Tarea(6, "Crear la música y efectos de sonido", "Baja" ,Fecha(15,7,2023) ,"Pendiente"));
    lista.Agregar(Tarea(7, "Integrar música y efectos de sonido" ,"Media", Fecha(30,7,2023), "Pendiente"));
    lista.Agregar(Tarea(8, "Realizar pruebas de rendimiento", "Media", Fecha(15,8,2023) ,"Pendiente"));
    lista.Agregar(Tarea(9, "Corregir errores" ,"Alta" ,Fecha(30,8,2023) ,"Pendiente"));
    lista.Agregar(Tarea(10, "Lanzar el juego" ,"Baja" ,Fecha(15,9,2023) ,"Pendiente"));
    return lista;
}

int seleccionarId(){
    int id;
    cout << "INGRESE EL ID QUE DESEA: ";
    cin >> id;
    return id;
}

int contarDiasFaltantes(Fecha f1){
    Fecha fActual(10,10,2023);
    int cont = 0;
    while (f1.toString("YYYY/MM/DD") < fActual.toString("YYYY/MM/DD")){
        f1.agregarDias(1);
        cont++;
    }
return cont;
}
