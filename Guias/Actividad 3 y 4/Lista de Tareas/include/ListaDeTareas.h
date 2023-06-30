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
        void mostrarTareaConEti(int id);
        void mostrarTareaPorEtiqueta(std::string etiqueta);

};

#endif // LISTADETAREAS_H
