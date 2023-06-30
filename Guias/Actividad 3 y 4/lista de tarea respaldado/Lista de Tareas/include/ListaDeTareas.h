#ifndef LISTADETAREAS_H
#define LISTADETAREAS_H
#include "Tarea.h"


class ListaDeTareas{
    private:
        Tarea _listaTareas[10];
        int _cantTareas;
        void ordenar();
    public:
        ListaDeTareas();
        void Agregar(Tarea t);
        void Mostrar();
        void MostrarTarea(int id);
        void ModificarEstado(int id);
        void mostrarDeadLine();

        ListaDeTareas* getLista();

};

#endif // LISTADETAREAS_H
