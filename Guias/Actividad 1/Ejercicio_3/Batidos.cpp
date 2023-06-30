#include <iostream>
#include <cstdlib>

using namespace std;



int main(){
    setlocale (LC_ALL, "Spanish");

    int capacidades_vaso[3] = {150,200,300};

    int  stock_banana = 20000, stock_anana = 35000, stock_sandia = 44000;

    int cont_banana = 0, cont_anana = 0, cont_sandia = 0;

    int cod_batido, cod_vaso, mil_lit;


    cout << "Ingrese el codigo de batido: ";
    cin >> cod_batido;

    while (cod_batido != 0){
        cout << "Ingrese el codigo de vaso: ";
        cin >> cod_vaso;

        mil_lit = capacidades_vaso[cod_vaso-1];

        switch (cod_batido){
        case 1:
            if(mil_lit <= stock_banana){
                stock_banana = stock_banana-mil_lit;
                cont_banana++;
            }else{
                cout << "No hay stock" << endl;
            }

        break;
        case 2:
            if(mil_lit <= stock_anana){
                stock_anana = stock_anana-mil_lit;
                cont_anana++;
            }else{
                cout << "No hay stock" << endl;
            }
        break;
        case 3:
            if(mil_lit <= stock_sandia){
                stock_sandia = stock_sandia-mil_lit;
                cont_sandia++;
            }else{
                cout << "No hay stock" << endl;
            }
        break;

        default:
            cout << "no existe sabor" << endl;
        break;
        }

        cout << endl;
        cout << "Ingrese el codigo de batido: ";
        cin >> cod_batido;
    }

    cout << "Stock de banana: " << (float) stock_banana/1000 << " lts" << ", cantidad de ventas " << cont_banana <<endl;
    cout << "Stock de anana: " << (float) stock_anana/1000 << " lts" << ", cantidad de ventas " << cont_anana <<endl;
    cout << "Stock de sandia: " << (float) stock_sandia/1000 << " lts" << ", cantidad de ventas " << cont_sandia <<endl;



    return 0;
}
