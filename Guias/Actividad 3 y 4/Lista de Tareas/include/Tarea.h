#ifndef TAREA_H
#define TAREA_H
#include "Fecha.h"


class Tarea{
    private:
        int _id;
        std::string _descripcion;
        std::string _dificultad;
        Fecha _fechaLimite;
        std::string _estado;
        std::string _vecEtiquetas[10];
        int _cantEti;
    public:
        Tarea();
        Tarea(int id, std::string descripcion,std::string dificultad, Fecha fechaLimite, std::string estado);
        void Cargar();
        void Mostrar();

        int getId();
        std::string getDescripcion();
        std::string getDificultad();
        Fecha getFechaLimite();
        std::string getEstado();
        std::string* getVecEtiquetas();
        int getCantEti();

        void setID(int ID);
        void setDescripcion(std::string descripcion);
        void setFechaLimite(Fecha fechaLimite);
        void setNivelDificultad(int dificultad);
        void setEstado(std::string estado);




};

#endif // TAREA_H
