#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Pedido dato)
{
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}
