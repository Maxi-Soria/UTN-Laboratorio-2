#pragma once
#include <string>

class ClaseParticular
{
private:
  int _id;
  int _legajoAlumno;// legajo del alumno que realiza la clase particular
  int _legajoProfesor; // el legajo del profesor que realiza la clase particular
  int _monto; // monto de la clase particular
  int _idCurso; // curso para el que esta la clase particular
  int _duracion; // tiempo en minutos de la clase particular

public:
  ClaseParticular();
  ClaseParticular(int id, int legajoAlumno, int legajoProfesor, int monto, int idCurso, int duracion);
  int getId();
  int getLegajoAlumno();
  int getLegajoProfesor();
  int getMonto();
  int getIdCurso();
  int getDuracion();
  void setId(int id);
  void setLegajoAlumno(int legajoAlumno);
  void setLegajoProfesor(int legajoProfesor);
  void setMonto(int monto);
  void setIdCurso(int idCurso);
  void setDuracion(int duracion);
  std::string toString();
};

