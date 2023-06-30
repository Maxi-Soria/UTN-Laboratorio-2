#include <iostream>
//#include <cstdlib>

using namespace std;

/*
Una tienda online dispone de todas las ventas realizadas el mes pasado en los tres pa�ses donde comercializa. Por cada venta registra:
N�mero de pa�s (1 a 3)
D�a de la venta (1 a 31)
Monto de la venta (float)

Para indicar el fin de la carga de informaci�n se ingresa un n�mero de pa�s igual a -1. La informaci�n no se encuentra agrupada ni ordenada bajo ning�n criterio.
Se pide calcular e informar:

A) Por cada pa�s y d�a, el total recaudado. S�lo mostrar informaci�n de aquellos d�as en los que hubo recaudaci�n.
B) Por cada pa�s, la cantidad de d�as en los que no hubo recaudaci�n.
C) Los n�meros de d�a en los que no hubo recaudaci�n en ninguno de los pa�ses.
*/
void mostrar_puntoA(float matriz[][31]){

    for (int i = 0 ; i < 3 ; i++ ){
        cout << "\nRecaudacion pais " << i+1 << endl;
        for (int j = 0 ; j < 31 ; j++ ){
            if (matriz[i][j] > 0){
                cout << "Dia " << j+1 << " $ " << matriz[i][j] << endl;
            }
        }
    }
    cout << endl;
}

void mostrar_puntoB(float matriz[][31]){
    int sin_recaudacion = 0;
    for (int i = 0 ; i < 3 ; i++ ){
        cout << "Dias sin recaudacion del pais " << i+1 << " : ";
        sin_recaudacion = 0;
        for (int j = 0 ; j < 31 ; j++ ){
            if (matriz[i][j] == 0){
                sin_recaudacion++;
            }
        }
        cout << sin_recaudacion << endl;
    }
    cout << endl;
}

void mostrar_puntoC(float matriz[][31]){
    int acum = 0;
    cout << "No hubo recaudacion de nungun pais los dias: " << endl;
    for (int i = 0 ; i < 31 ; i++ ){
        acum = 0;
        for (int j = 0 ; j < 3 ; j++ ){
            acum += matriz[j][i];
        }
        if (acum == 0){
            cout << i+1 << " ";
        }
    }
    cout << endl;
}


int main(){
    setlocale (LC_ALL, "Spanish");
    int pais, dia;
    float importe;

    //PUNTO A
    float recaud_pais_dia[3][31]={};


    cout << "Ingrese �umero de pais: ";
    cin >> pais;

    while(pais != -1){
        cout << "Ingrese numero de dia: ";
        cin >> dia;
        cout << "Ingrese el importe: ";
        cin >> importe;

        //Punto A
        recaud_pais_dia[pais-1][dia-1] += importe;


        cout << "Ingrese numero de pais: ";
        cin >> pais;
    }

    mostrar_puntoA(recaud_pais_dia);
    mostrar_puntoB(recaud_pais_dia);
    mostrar_puntoC(recaud_pais_dia);


    return 0;
}
