#include <iostream>
#include "ListaDeTareas.h"
#include "funciones.h"

using namespace std;

string pedirEtiqueta(){
    string eti;
    cin.ignore();
    cout << "Ingrese la etiqueta que desea buscar: ";
    getline(cin,eti);
    return eti;
}

///----------------
bool debug = false;
///----------------
int main(){
    setlocale(LC_ALL, "");

    Tarea reg(1,"Aprender Archivos","Mucha",Fecha(18,5,2023),0);




    /*
    ListaDeTareas lista;
    int opcion;


        do{
        system("cls");

        cout << "MENU " << endl;
        cout << "1- CARGAR TAREA" << endl;
        cout << "2- MOSTRAR LISTA" << endl;
        cout << "3- VER TAREA" << endl;
        cout << "4- MODIFICAR ESTADO" << endl;
        cout << "5- VER TAREAS CON DEADLINE" << endl;
        cout << "6- VER TAREAS CON ETIQUETAS" << endl;
        cout << "7- VER TAREAS POR ETIQUETAS" << endl;
        cout << "0- SALIR " << endl;
        cin >> opcion;

        switch (opcion){
        case 1:
                system("cls");
                if(debug){lista = harcodeoLista();}
                else{lista.Agregar(CargarTarea());}
                system("pause");
            break;
        case 2:
                system("cls");
                lista.Mostrar();
                system("pause");
            break;
        case 3:
                system("cls");
                lista.MostrarTarea(seleccionarId());
                system("pause");
            break;
        case 4:
                system("cls");
                lista.ModificarEstado(seleccionarId());
                system("pause");
            break;
        case 5:
                system("cls");
                lista.mostrarDeadLine();
                system("pause");
            break;
        case 6:
                system("cls");
                lista.mostrarTareaConEti(seleccionarId());
                system("pause");
            break;
        case 7:
                system("cls");
                lista.mostrarTareaPorEtiqueta(pedirEtiqueta());
                system("pause");
            break;

        case 0:
                system("cls");
                cout << "Hasta pronto!!" << endl;
            break;
        }

    } while (opcion != 0);
*/
}

/*
1
Crear concepto del videojuego
Media
30
04
2023
Hecho
3
pruebo etis
hola
chau

2
Diseñar niveles
Alta
15
05
2023
Hecho
4
digo
sera que
funciona esta vez
no se

3
Crear sprites
Media
30
05
2023
Pendiente
2
maxi
facu soria

4
Desarrollar la mecánica del juego
Alta
15
06
2023
Pendiente
6
nombre
hola
parrilla
compu piola
juegos de pc
terminando


5
Programar el juego
Alta
30/06/2023
Pendiente
6
Crear la música y efectos de sonido
Baja
15/07/2023
Pendiente
7
Integrar música y efectos de sonido
Media
30/07/2023
Pendiente
8
Realizar pruebas de rendimiento
Media
15/08/2023
Pendiente
9
Corregir errores
Alta
30/08/2023
Pendiente
10
Lanzar el juego
Baja
15/09/2023
Pendiente

*/
