#include <iostream>

using namespace std;
void carga_vector_con2(int *vec, int tam){
    for (int i=0 ; i< tam; i++ ){
        vec[i] = 2;

    }
    cout << "cargado A" << endl;
}

void carga_vector_con7(int *vec, int tam){
    for (int i=0 ; i< tam; i++ ){
        vec[i] = 7;
    }
    cout << "cargado B" << endl;
}

void elementos_no_repetidos(int *vecA, int *vecB, int A, int B);


int main(){
    int const TAM_A = 50;
    int const TAM_B = 10;

    int *vecA = nullptr;
    int *vecB = nullptr;

    vecA = new int [TAM_A];
    vecB = new int [TAM_B];



    if (vecA != nullptr && vecB != nullptr){
        carga_vector_con2(vecA, TAM_A);
        carga_vector_con7(vecB, TAM_B);
        elementos_no_repetidos(vecA, vecB, TAM_A, TAM_B);


    delete []vecA;
    delete []vecB;
    }

    return 0;

}


void elementos_no_repetidos(int *vecA, int *vecB, int A, int B){
    int tam_vecC = A+B;
    int pos = 0;
    bool esta = false;
    int  *vecC = nullptr;

    vecC = new int [tam_vecC];

    if (vecC != nullptr){
        //BUSCAR A EN B
       for (int i=0 ; i<A ; i++ ){
            esta = false;
           for (int j=0 ; j<B ; j++ ){
                if (vecA[i] == vecB[j]){
                    esta = true;
                }
           }
            if (!esta){
               vecC[pos]=vecA[i];
               pos++;
            }
       }

       //BUSCAR B EN A
              for (int i=0 ; i<B ; i++ ){
            esta = false;
           for (int j=0 ; j<A ; j++ ){
                if (vecB[i] == vecA[j]){
                    esta = true;
                }
           }
            if (!esta){
               vecC[pos]=vecB[i];
               pos++;
            }
       }

       //MOSTRAR C
       for (int i=0 ; i<pos ; i++ ){
           cout << vecC[i] << " ";
       }

    delete []vecC;
    }
}



