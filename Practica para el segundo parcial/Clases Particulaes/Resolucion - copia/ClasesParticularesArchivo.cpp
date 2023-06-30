#include "ClasesParticularesArchivo.h"

ClaseParticular ClasesParticularesArchivo::leer(int nroRegistro)
{
  ClaseParticular registro;
  FILE* pFile = fopen("clasesparticulares.dat", "rb");
  if (pFile != NULL)
  {
    fseek(pFile, nroRegistro * sizeof(ClaseParticular), SEEK_SET);
    fread(&registro, sizeof(ClaseParticular), 1, pFile);
    fclose(pFile);
  }
  return registro;
}

bool ClasesParticularesArchivo::leerTodos(ClaseParticular registros[], int cantidad)
{
  bool ok = false;
  FILE* pFile = fopen("clasesparticulares.dat", "rb");
  if (pFile != NULL)
  {
    fread(registros, sizeof(ClaseParticular), cantidad, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

bool ClasesParticularesArchivo::guardar(ClaseParticular registro)
{
  bool ok = false;
  FILE* pFile = fopen("clasesparticulares.dat", "ab");
  if (pFile != NULL)
  {
    fwrite(&registro, sizeof(ClaseParticular), 1, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

bool ClasesParticularesArchivo::guardar(ClaseParticular registro, int nroRegistro)
{
  bool ok = false;
  FILE* pFile = fopen("clasesparticulares.dat", "rb+");
  if (pFile != NULL)
  {
    fseek(pFile, nroRegistro * sizeof(ClaseParticular), SEEK_SET);
    fwrite(&registro, sizeof(ClaseParticular), 1, pFile);
    fclose(pFile);
    ok = true;
  }
  return ok;
}

int ClasesParticularesArchivo::getCantidad()
{
  int cantidad = 0;
  FILE* pFile = fopen("clasesparticulares.dat", "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(ClaseParticular);
    fclose(pFile);
  }
  return cantidad;
}

int ClasesParticularesArchivo::buscar(int id)
{
  int nroRegistro = -1;
  int cantidad = getCantidad();
  ClaseParticular registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro = leer(i);
    if (registro.getId() == id)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}



