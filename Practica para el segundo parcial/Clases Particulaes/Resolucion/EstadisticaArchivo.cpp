#include "EstadisticaArchivo.h"
#include <cstring>
#include <iostream>



ArchivoEstadistica::ArchivoEstadistica(){
    strcpy(nombre,"estadistica.dat");
}


bool ArchivoEstadistica::guardar(Estadistica reg) {
    FILE* p = fopen(nombre, "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(Estadistica), 1, p);
    fclose(p);
    return ok;
}


Estadistica ArchivoEstadistica::leer(int pos){
    Estadistica reg;
    FILE* pFile = fopen("estadistica.dat", "rb");
    if (pFile != NULL)
    {
        fseek(pFile, pos * sizeof(Estadistica), SEEK_SET);
        fread(&reg, sizeof(Estadistica), 1, pFile);
        fclose(pFile);
    }
    return reg;
}



int ArchivoEstadistica::getCantidad() {
    FILE* p = fopen("estadistica.dat", "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Estadistica);
    fclose(p);
    return cant;
}



void ArchivoEstadistica::vaciar(){
    FILE *p = fopen(nombre, "wb");
    if (p == NULL)
    {
    return ;
    }
    fclose(p);
}


