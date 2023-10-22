#include "NodoPila.hpp"

NodoPila::NodoPila(Pedido p, NodoPila* sig)
{
    pedido = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}

