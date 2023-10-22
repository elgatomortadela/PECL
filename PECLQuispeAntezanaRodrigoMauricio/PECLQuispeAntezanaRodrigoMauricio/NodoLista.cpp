#include "NodoLista.hpp"

NodoLista::NodoLista(Pedido p, NodoLista* sig)
{
    pedido = p;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}

