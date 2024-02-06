#ifndef TIPOINFRACCION_H
#define TIPOINFRACCION_H


class TipoInfraccion
{
public:
    TipoInfraccion();
    TipoInfraccion(int idTipoInfraccion,string descripcion,float costo,int nivelSeveridad);

    //////
    void setIdTipoInfraccion(int tipoInfraccion);
    void setDescripcion (string descripcion);
    void setCosto (float costo);
    void setNivelSeveridad (int nivelSeveridad);
    ////
    int getIdTipoInfraccion();
    string getDescripcion();
    float getCosto();
    int getNivelSeveridad();

private:
    int _idTipoInfraccion;
    char _descripcion[50];
    float _costo;
    int _nivelSeveridad;
};

#endif // TIPOINFRACCION_H

