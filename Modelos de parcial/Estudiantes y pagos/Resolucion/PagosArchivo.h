#pragma once
#include "Pago.h"

class PagosArchivo
{
public:
  Pago leer(int nroRegistro);
  bool leerTodos(Pago estudiantes[], int cantidad);
  bool guardar(Pago est);
  bool guardar(Pago est, int nroRegistro);
  int getCantidad();
  int buscar(int id);
};

