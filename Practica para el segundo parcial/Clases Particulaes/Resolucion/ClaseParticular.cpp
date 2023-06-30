#include "ClaseParticular.h"

// creamos el  constructor
ClaseParticular::ClaseParticular()
{
  _id = 0;
  _legajoAlumno = 0;
  _legajoProfesor = 0;
  _monto = 0;
  _idCurso = 0;
  _duracion = 0;
}

ClaseParticular::ClaseParticular(int id, int legajoAlumno, int legajoProfesor, int monto, int idCurso, int duracion) {
    _id = id;
    _legajoAlumno = legajoAlumno;
    _legajoProfesor = legajoProfesor;
    _monto = monto;
    _idCurso = idCurso;
    _duracion = duracion;
}

int ClaseParticular::getId()
{
  return _id;
}

int ClaseParticular::getLegajoAlumno()
{
  return _legajoAlumno;
}

int ClaseParticular::getLegajoProfesor()
{
  return _legajoProfesor;
}

int ClaseParticular::getMonto()
{
  return _monto;
}

int ClaseParticular::getIdCurso()
{
  return _idCurso;
}

int ClaseParticular::getDuracion()
{
  return _duracion;
}

void ClaseParticular::setId(int id)
{
  _id = id;
}

void ClaseParticular::setLegajoAlumno(int legajoAlumno)
{
  _legajoAlumno = legajoAlumno;
}

void ClaseParticular::setLegajoProfesor(int legajoProfesor)
{
  _legajoProfesor = legajoProfesor;
}

void ClaseParticular::setMonto(int monto)
{
  _monto = monto;
}

void ClaseParticular::setIdCurso(int idCurso)
{
  _idCurso = idCurso;
}

void ClaseParticular::setDuracion(int duracion)
{
  _duracion = duracion;
}

std::string ClaseParticular::toString()
{
  std::string s = "Id: " + std::to_string(_id) + " Legajo Alumno: " + std::to_string(_legajoAlumno) + " Legajo Profesor: " + std::to_string(_legajoProfesor) + " Monto: " + std::to_string(_monto) + " Id Curso: " + std::to_string(_idCurso) + " Duracion: " + std::to_string(_duracion);
  return s;
}






