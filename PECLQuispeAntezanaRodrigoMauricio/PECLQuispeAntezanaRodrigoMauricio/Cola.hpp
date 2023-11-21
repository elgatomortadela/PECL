#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    void insertar(Pedido p);
    Pedido eliminar();
    void mostrar();
    Pedido verPrimero();
    int getLongitud();

private:
    pnodoCola primero, ultimo;
    int longitud;

};

#endif // COLA_HPP
