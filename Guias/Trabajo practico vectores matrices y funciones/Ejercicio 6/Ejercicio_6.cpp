#include <iostream>
#include <cstdlib>

using namespace std;

/*
6
La Universidad Brian Lara dispone de los registros de todos los cursos que se dictarán en el año actual. Por cada curso se registró la siguiente información:
Número de curso (entero)
Número de aula (10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
Turno ('M' - Mañana, 'T' - Tarde, 'N' - Noche)
Cantidad de alumnos inscriptos

El fin de la carga de datos se indica con un número de curso igual a cero. La información no está agrupada ni ordenada. Se pide calcular informar:

A) Por cada aula, la cantidad total de cursos que la utilizaron.
B) El promedio de alumnos por turno (se muestra un sólo resultado).
C) Por cada aula, la máxima cantidad de alumnos inscriptos en un curso. Por ejemplo, si el aula 50 es utilizada por el curso 1 con 30 alumnos y el curso 2 con 75 alumnos. Entonces, la mayor cantidad de alumnos inscriptos para el aula 50 es de 75.
*/

void total_cursos_por_aula(int vec[], int tam){

    for (int i = 0 ; i < tam ; i++ ){
        cout << "Aula n° " << (i+1)*10 << " total de cursos: " << vec[i] << endl;
    }
    cout << endl;
}

void prom_alumnos_por_turno(int maniana, int tarde, int noche){
    int tot_alumnos = maniana + tarde + noche;
    cout << "Promedios de alumnos por turno " << endl;
    cout << "Mañana: " << (float)maniana*100/tot_alumnos << endl;
    cout << "Tarde:  " << (float)tarde*100/tot_alumnos << endl;
    cout << "Noche:  " << (float)noche*100/tot_alumnos << endl;

}

int main(){
    setlocale (LC_ALL, "Spanish");

    int num_curso, num_aula, cant_alumnos;
    char turno;

    int const TAM = 9;
    int vec_aulas[TAM] = {};

    int cont_M = 0, cont_T = 0,  cont_N = 0;

    int vec_maximos[TAM] = {};

    cout << "Ingrese el numero de curso: ";
    cin >> num_curso;

    while (num_curso != 0){

        cout << "Ingrese el numero de aula: ";
        cin >> num_aula;
        cout << "Ingrese el turno M/N: ";
        cin >> turno;
        cout << "Ingrese la cantidad de inscriptos: ";
        cin >> cant_alumnos;

        //Punto A
        vec_aulas[(num_aula/10)-1]++;

        //Punto B
        if (turno == 'M'){
            cont_M++;
        }else{
            if (turno == 'T'){
                cont_T++;
            }else{
                cont_N++;
            }
        }

        //Punto C
        if (vec_maximos[(num_aula/10)-1] == 0){
            vec_maximos[(num_aula/10)-1]  = cant_alumnos;
        }
        else{
            if (cant_alumnos > vec_maximos[(num_aula/10)-1]){
                vec_maximos[(num_aula/10)-1]  = cant_alumnos;
            }
        }




        cout << endl;
        cout << "Ingrese el numero de curso: ";
        cin >> num_curso;
    }
    cout << endl;

    //total_cursos_por_aula(vec_aulas, TAM);
    //prom_alumnos_por_turno(cont_M, cont_T, cont_N );

    for (int i = 0 ; i < 9 ; i++ ){
        cout << "Aula " << (i+1)*10 << " maximo: " << vec_maximos[i] << endl;
    }


    return 0;
}

