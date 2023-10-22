#include "NodoCola.hpp"

NodoCola::NodoCola(Pedido p, NodoCola* sig)
{
    pedido = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}

