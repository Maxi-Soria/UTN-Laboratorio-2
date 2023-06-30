#include <iostream>
#include <cstring>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"


bool buscarPaisPorCodigo(const char* codigo) {
    Pais reg;

    FILE* p = fopen("paises.dat", "rb");
    if (p == nullptr) {
        cout << "Error al abrir el archivo de paises." << endl;
        return false;
    }

    while (fread(&reg, sizeof(Pais), 1, p)) {
        if (strcmp(reg.getCodigo(), codigo) == 0) {
            fclose(p);
            return true;  // El registro de país existe
        }
    }

    fclose(p);
    return false;  // El registro de país no existe
}

bool listarArchivo(){
    Pais reg;
    FILE *p;
    p = fopen("paises.dat", "rb");
    if (p == NULL){
    cout << "No se pudo abrir " << endl;
    return false;
    }
    while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.mostrar();
        cout << endl;

    }
    fclose(p);
    return true;
    }

int main()
{
    //listarArchivo();
    if(buscarPaisPorCodigo("BRA")){
        cout << "El registro existe" << endl;
    }
    else{
        cout << "El registro no existe" << endl;
    }
    return 0;
}
