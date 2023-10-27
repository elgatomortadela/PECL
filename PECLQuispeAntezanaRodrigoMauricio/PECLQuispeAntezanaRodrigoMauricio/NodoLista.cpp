#include "NodoLista.hpp"

NodoLista::NodoLista(Pedido p, NodoLista* sig, NodoLista* ant)
{
    pedido = p;
    siguiente = sig;
    anterior = ant;
}

NodoLista::~NodoLista()
{
}

