#pragma once
#include "Fecha.h"
class Pago
{
private:
  int _id;
  float _monto; // monto del pago
  int _legajo; // legajo del estudiante
  int _idCurso; // id del curso al que se le paga (1 - 10)
  Fecha _fecha; // fecha del pago
  int _mes; // Mes periodo de cursada (1 a 12)
  int _anio; // Año periodo de cursada
  int _idMetodoPago; // 1: Efectivo, 2: Tarjeta de crédito

public:
  Pago();
  Pago(int id, float monto, int legajo, int idCurso, Fecha fecha, int mes, int anio, int idMetodoPago);
  int getId();
  float getMonto();
  int getLegajo();
  int getIdCurso();
  Fecha getFecha();
  int getMes();
  int getAnio();
  int getIdMetodoPago();
  void setId(int id);
  void setMonto(float monto);
  void setLegajo(int legajo);
  void setIdCurso(int idCurso);
  void setFecha(Fecha fecha);
  void setMes(int mes);
  void setAnio(int anio);
  void setIdMetodoPago(int idMetodoPago);
  std::string toString();
  bool esPagovencido();
};

