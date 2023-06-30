#include <iostream>
#include "ListaDeTareas.h"
#include "funciones.h"

using namespace std;



///----------------
bool debug = true;
///----------------
int main(){
    setlocale(LC_ALL, "");

    ListaDeTareas obj, *p;

    p=obj.getLista();

    &p.Mostrar();




}
































/*    ListaDeTareas lista;
    int opcion;

        do{
        system("cls");

        cout << "MENU " << endl;
        cout << "1- CARGAR TAREA" << endl;
        cout << "2- MOSTRAR LISTA" << endl;
        cout << "3- VER TAREA" << endl;
        cout << "4- MODIFICAR ESTADO" << endl;
        cout << "5- VER TAREAS CON DEADLINE" << endl;
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

                system("pause");
            break;

        case 0:
                system("cls");
                cout << "Hasta pronto!!" << endl;
            break;
        }

    } while (opcion != 0);
*/
