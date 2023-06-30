#include <iostream>
#include "Bidon.h"
using namespace std;

int main(){

    Bidon vecBidones [3] = {Bidon("Banana", 22), Bidon("Anana", 35), Bidon("Sandia", 44)};

    float capacidadesVasos[3] = {150, 200, 300};

    ///Cantidad batidos vendidos
    int cantBanana=0, cantAnana=0, cantSandia=0;

    /// Registro de una venta
    int codBatido, codVaso;
    float miliLitros;

    cout << "Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
    cin >> codBatido;

    while(codBatido != 0){

        cout << "Vaso (1 - 150ml, 2 - 200ml, 3 - 300ml): ";
        cin >> codVaso;

        miliLitros = capacidadesVasos[codVaso-1];

        if(vecBidones[codBatido-1].getCapacidad() > miliLitros){
            vecBidones[codBatido-1].extraer(miliLitros);
        }
        else{
            cout << "Sin stock de ese producto" << endl;
        }


        cout <<  "-------------------------------------" << endl;
        cout << "Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
        cin >> codBatido;
    }

    cout << endl << "Estadisticas del dia: " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Banana: " << vecBidones[0].getCapacidad() << " lts (" << cantBanana << " ventas)" << endl;
    cout << "Anana : " << vecBidones[1].getCapacidad() << " lts (" << cantAnana << " ventas)" << endl;
    cout << "Sandia: " << vecBidones[2].getCapacidad() << " lts (" << cantSandia << " ventas)" << endl;


    return 0;
}
