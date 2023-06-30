#include <iostream>

using namespace std;

int puntoA(float *notas, int cant);
void puntoB(float *notas, int cant, string *nombres);


int main(){

    int cant_alumnos;


    cout << "Ingrese la cantidad de Alumnos: ";
    cin >> cant_alumnos;
    cout << endl;

    string *nombre = nullptr;
    float *notas = nullptr;

    nombre = new string [cant_alumnos];
    notas = new float[cant_alumnos];

    if(nombre != nullptr && notas != nullptr ){

        for (int i=0 ; i<cant_alumnos ; i++ ){
            cout << "Ingrese el nombre y apellido: ";
            cin.ignore();
            getline(cin,nombre[i]);
            cout << "Ingrese la nota final: ";
            cin >> notas[i];
            cout << endl;

        }

        cout << "Total de alumnos que exedieron el prom gral es: " << puntoA(notas, cant_alumnos);
        cout << endl;
        puntoB(notas, cant_alumnos, nombre);


    delete[] nombre;
    delete[] notas;
    }
    return 0;
}

int puntoA(float *notas, int cant){

    float prom_gral = 0, acu_notas = 0;

    for (int i=0 ; i<cant ; i++ ){
        acu_notas+= notas[i];
    }
    prom_gral = acu_notas/cant;

    int mayores_al_promedio = 0;
    for (int i=0 ; i<cant; i++ ){
        if(notas[i] > prom_gral){
            mayores_al_promedio++;
        }
    }
return mayores_al_promedio;
}

void puntoB(float *notas, int cant, string *nombres){
    int cant_aprob = 0;
    float prom_aprob, notas_aprob = 0;

    for (int i=0 ; i<cant ; i++ ){
        if(notas[i] > 6){
            cant_aprob++;
            notas_aprob += notas[i];
        }
    }
    prom_aprob = notas_aprob/cant_aprob;

    for (int i=0 ; i<cant ; i++ ){
        if(notas[i] > prom_aprob){
            cout << nombres[i] << endl;
        }
    }
}
