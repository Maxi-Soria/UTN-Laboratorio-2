#include <iostream>
#include <cstdlib>
#include "Bidon.h"


/// CONSTRUCTOR
Bidon::Bidon() {
  _sabor = "Sin Sabor";
  _capacidad = 1.0f;
}

Bidon::Bidon(std::string sabor, float litros){
    _sabor = sabor;
    if(litros>0){
        _capacidad = litros;
    }
}

///SETTERS
void Bidon::setSabor(std::string sabor){_sabor = sabor;}
void Bidon::setCapacidad(float capacidad){_capacidad = capacidad;}

///GETTERS
std::string Bidon::getSabor(){return _sabor;}
float Bidon::getCapacidad(){return _capacidad;}

/// METODO LLENAR
void Bidon::llenar(int litros){_capacidad = litros*1000;}

///METODO EXTRAER
void Bidon::extraer(float cantidad) {
  if (cantidad > 0) {
    _capacidad -= cantidad;
    if (_capacidad < 0) {
      _capacidad = 0;
    }
  }
}



