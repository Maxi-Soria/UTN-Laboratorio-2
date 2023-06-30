#include "PagosArchivo.h"

Pago PagosArchivo::leer(int nroRegistro)
{
  Pago pago;
  FILE* p;
  p = fopen("pagos.dat", "rb");
  if (p == NULL)
  {
    return pago;
  }
  fseek(p, nroRegistro * sizeof(Pago), SEEK_SET);
  fread(&pago, sizeof(Pago), 1, p);
  fclose(p);
  return pago;
}

bool PagosArchivo::leerTodos(Pago pagos[], int cantidad)
{
  FILE* p;
  p = fopen("pagos.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(pagos, sizeof(Pago), cantidad, p);
  fclose(p);
  return true;
}

bool PagosArchivo::guardar(Pago pago)
{
  FILE* p = fopen("pagos.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&pago, sizeof(Pago), 1, p);
  fclose(p);
  return ok;
}

bool PagosArchivo::guardar(Pago pago, int nroRegistro)
{
  FILE* p = fopen("pagos.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Pago), SEEK_SET);
  bool ok = fwrite(&pago, sizeof(Pago), 1, p);
  fclose(p);
  return ok;
}

int PagosArchivo::getCantidad()
{
  FILE* p = fopen("pagos.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Pago);
  fclose(p);
  return cant;
}

int PagosArchivo::buscar(int id)
{
  int cant = getCantidad();
  Pago pago;
  for (int i = 0; i < cant; i++)
  {
    pago = leer(i);
    if (pago.getId() == id)
    {
      return i;
    }
  }
  return -1;
}