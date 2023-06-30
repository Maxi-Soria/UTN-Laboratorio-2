#pragma once
#include "ClaseParticular.h"

class ClasesParticularesArchivo
{
public:
  ClaseParticular leer(int nroRegistro);
  bool leerTodos(ClaseParticular registros[], int cantidad);
  bool guardar(ClaseParticular registro);
  bool guardar(ClaseParticular registro, int nroRegistro);
  int getCantidad();
  int buscar(int id);
};

