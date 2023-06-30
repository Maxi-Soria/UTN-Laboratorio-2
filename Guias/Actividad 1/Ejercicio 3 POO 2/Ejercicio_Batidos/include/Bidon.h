#ifndef BIDON_H
#define BIDON_H
#include <cstring>




class Bidon{
private:
  std::string _sabor;
  float _capacidad;


public:

    Bidon();
    Bidon(std::string sabor, float litros);

    void extraer(float cantidad);
    void llenar(int cantidad);

    // getters y setters
    void setSabor(std::string sabor);
    void setCapacidad(float capacidad);

    std::string getSabor();
    float getCapacidad();


};

#endif // BIDON_H
