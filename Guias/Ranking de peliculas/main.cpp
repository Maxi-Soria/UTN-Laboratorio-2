#include <iostream>
#include "Pelicula.h"
#include "RankingDePeliculas.h"
#include "funciones.h"

using namespace std;

///ACA PONELO EN TRUE O FALSE SEGUN QUIERAS USAR O NO EL HARCODEO DE DATOS, ESO SE EJECUTA EN EL CASE 1
bool debug = false;
int main(){

    Pelicula obj;
    RankingDePeliculas ranking;
    Fecha aux;

    int opcion;

        do{
        system("cls");

        cout << "MENU " << endl;
        cout << "1- CARGAR PELICULA" << endl;
        cout << "2- PUNTUAR PELICULA" << endl;
        cout << "3- VER RANKING" << endl;
        cout << "0) SALIR" << endl;
        cin >> opcion;

        switch (opcion){
        case 1:
                system("cls");
                if(debug){
                    ranking.Agregar(Pelicula("Pelicula uno   ", Fecha(1,1,2001),0));
                    ranking.Agregar(Pelicula("Pelicula dos   ", Fecha(2,2,2002),0));
                    ranking.Agregar(Pelicula("Pelicula tres  ", Fecha(3,3,2003),0));
                    ranking.Agregar(Pelicula("Pelicula cuatro", Fecha(4,4,2004),0));
                    ranking.Agregar(Pelicula("Pelicula cinco ", Fecha(5,5,2005),0));
                }
                else{
                    ranking.Agregar(CargarPelicula());
                }

                system("pause");
            break;
        case 2:
                system("cls");
                ranking.mostrarTitulos();
                ranking.puntuarPelicula(elegirPelicula());
                system("pause");
            break;
        case 3:
                system("cls");
                ranking.Mostrar();
                system("pause");
            break;

        case 0:
                system("cls");
                cout << "Hasta pronto!!" << endl;
            break;
        }

    } while (opcion != 0);


    return 0;
}
